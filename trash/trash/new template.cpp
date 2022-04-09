
module rv32is(
	input 	clock,
	input 	reset,
	output[31:0] imemaddr,
	input[31:0] imemdataout,
	output 	imemclk,
	output[31:0] dmemaddr,
	input[31:0] dmemdataout,
	output[31:0] dmemdatain,
	output 	dmemrdclk,
	output	dmemwrclk,
	output[2:0] dmemop,
	output	dmemwe,
	output[31:0] dbgdata,
	output done,
	output wb
);//add your code here

wire regwrclk;
reg[31:0] pc_r;
reg[31:0] dbg_pc_r;
wire[31:0] nextpc;
wire[4:0] ra, rb, rw; // rs1 rs2
wire[31:0] rs1data, rs2data, rewrdata; //bus1 bus2 busw
wire[31:0] instr;
wire[6:0] op;
wire[2:0] func3;
wire[6:0] func7;
wire[31:0] imm;
wire[31:0] aluresult;
wire[31:0] alua, alub;
wire[31:0] dmemrdaddr;
wire[31:0] dmemwraddr;
wire less, zero;

wire[2:0] extop;
wire regwr;
wire aluasrc;
wire[1:0] alubsrc;
wire[3:0] aluctr;
wire[2:0] branch;
wire memtoreg;
wire memwr;
wire[2:0] memop;
wire pcasrc, pcbsrc;

wire[31:0] regwrdata;
reg wb_r;

//只有rd是在上升沿那个的
assign done = instr == 0;
assign imemclk = ~clock;
assign dmemrdclk = clock;
assign dmemwrclk = ~clock;
assign regwrclk = ~clock;

assign instr = imemdataout;
assign op = instr[6:0];
assign ra = instr[19:15];
assign rb = instr[24:20];
assign rw = instr[11:7];
assign func3 = instr[14:12];
assign func7 = instr[31:25];
assign op = instr[6:0];

assign dmemwe = memwr;
assign dmemop = func3;
assign dbgdata = dbg_pc_r;

assign regwrdata = (memtoreg == 1'b1)? dmemdataout:aluresult;
	assign alua = (aluasrc == 1'b1)? pc_r:rs1data;
		assign alub = (alubsrc[1] == 1'b1)? 32'h00000004 : ((alubsrc[0] == 1'b1)? imm:rs2data);
			assign wb = wb_r;

always@(negedge clock)
begin
if (reset) begin
pc_r <= 32'h80000000;
wb_r <= 0;
end
else begin
if (instr != 0) begin
wb_r <= 1;
end
else begin
wb_r <= 0;
end
pc_r <= nextpc;
dbg_pc_r <= pc_r;
end
end

assign imemaddr = (reset == 1'b1)? 32'b0: nextpc;
assign dmemrdaddr = rs1data + { {20{instr[31]}}, instr[31:20]}; //aluresult; //for
assign dmemwraddr = rs1data + { {20{instr[31]}}, instr[31:25], instr[11:7]};
assign dmemdatain = rs2data;
assign dmemaddr = (dmemwe == 0) ? dmemrdaddr : dmemwraddr;


regfile myregfile(.ra(ra),
	.rb(rb),
	.rw(rw),
	.wrdata(regwrdata),
	.outa(rs1data),
	.outb(rs2data),
	.regwr(regwr),
	.wrclk(regwrclk));

immgen immgenImpl(.instr(instr),
	.extop(extop),
	.imm(imm));

pcgen pcgenImpl(.pc(pc_r),
	.imm(imm),
	.rs1data(rs1data),
	.pcasrc(pcasrc),
	.pcbsrc(pcbsrc),
	.nextpc(nextpc),
	.instr(instr));

controlsig congent(.op(op),
	.func3(func3),
	.func7(func7),
	.extop(extop),
	.regwr(regwr),
	.aluasrc(aluasrc),
	.alubsrc(alubsrc),
	.aluctr(aluctr),
	.branch(branch),
	.memtoreg(memtoreg),
	.memwr(memwr),
	.memop(memop));

alu myalu(.dataa(alua),
	.datab(alub),
	.aluctr(aluctr),
	.less(less),
	.zero(zero),
	.aluresult(aluresult));

branchctr bctr(.branch(branch),
	.less(less),
	.zero(zero),
	.pcasrc(pcasrc),
	.pcbsrc(pcbsrc));

endmodule

module alu(
	input[31:0] dataa,
	input[31:0] datab,
	input[3:0]  aluctr,
	output less,
	output zero,
	output reg[31:0] aluresult);

wire[31:0] adderout;
wire addcarry;
wire[31:0] shiftout;
wire[31:0] adderbin;
wire al, lr, us, sa;
wire overflow;
wire[31:0] sltresult;

//alucontrol signal
assign al = aluctr[3]; //shift arithmetic/logical
assign lr = ~aluctr[2]; //shift left/right;
assign us = aluctr[3]; //unsigned or signed compare
assign sa = aluctr[3] | aluctr[1]; //add or subtaction

assign adderbin = { 32{sa} } ^ datab;
assign{ addcarry,adderout } = dataa + adderbin + {31'b0,sa};
//adderip myadder(.cin(sa),.dataa(dataa),.datab(adderbin),.cout(addcarry),.result(adderout));
assign overflow = (dataa[31] ^ ~adderbin[31]) & (adderout[31] ^ dataa[31]);
assign less = (us == 1'b1)? (addcarry^sa):(overflow^adderout[31]) ; //unsigned carry^cin, singed overflow^result[31]

	assign sltresult = { 31'b0,less};
	assign zero = ~(| adderout);

	always@(*)
	begin
		case(aluctr[2:0])
		3'd0:
			aluresult = adderout;
		3'd1:
			aluresult = shiftout;
		3'd2:
			aluresult = sltresult;
		3'd3:
			aluresult = datab;
		3'd4:
			aluresult = dataa ^ datab;
		3'd5:
			aluresult = shiftout;
		3'd6:
			aluresult = dataa | datab;
		3'd7:
			aluresult = dataa & datab;
		endcase

	end
	bshifter shifter(.indata(dataa), .shift(datab[4:0]), .lr(lr), .al(al), .outdata(shiftout));

endmodule

module bshifter(indata, shift, lr, al, outdata);
input[31:0] indata;
input[4:0] shift;
input lr,al;
output reg[31:0] outdata;

reg[31:0] l4out, l3out,l2out, l1out;
wire[31:0] lin,rin;

assign lin = 32'b0;

assign rin = (al == 1'b1)?{32{indata[31]}}:32'b0; //1 arithmetic 0 logical

always @(*)
begin
	if (shift[4] == 1'b0)
		 l4out = indata;
	 else
		if (lr == 1'b1)    // 1 left 0 right
		   l4out = {indata[15:0], lin[15:0]};
		 else
		   l4out = {rin[15:0],indata[31:16]};
end

always @(*)
begin
	if (shift[3] == 1'b0)
		 l3out = l4out;
	 else
		if (lr == 1'b1)    // 1 left 0 right
		   l3out = {l4out[23:0], lin[7:0]};
		 else
		   l3out = {rin[7:0],l4out[31:8]};
end

always @(*)
begin
	if (shift[2] == 1'b0)
		 l2out = l3out;
	 else
		if (lr == 1'b1)    // 1 left 0 right
		   l2out = {l3out[27:0], lin[3:0]};
		 else
		   l2out = {rin[3:0],l3out[31:4]};
end

always @(*)
begin
	if (shift[1] == 1'b0)
		 l1out = l2out;
	 else
		if (lr == 1'b1)    // 1 left 0 right
		   l1out = {l2out[29:0], lin[1:0]};
		 else
		   l1out = {rin[1:0],l2out[31:2]};
end

always @(*)
begin
	if (shift[0] == 1'b0)
		 outdata = l1out;
	 else
		if (lr == 1'b1)    // 1 left 0 right
		   outdata = {l1out[30:0], lin[0]};
		 else
		   outdata = {rin[0],l1out[31:1]};
end

endmodule

module branchctr(branch, less, zero, pcasrc, pcbsrc);
  input[2:0] branch;
	input less;
	input zero;
	output reg pcasrc;
	output reg pcbsrc;

	always@(*)
	begin
		case(branch)
			3'd0:
			begin
				pcasrc = 1'b0;
				pcbsrc = 1'b0;
			end
			3'd1:
			begin
				pcasrc = 1'b1;
				pcbsrc = 1'b0;
			end
			3'd2:
			begin
				pcasrc = 1'b1;
				pcbsrc = 1'b1;
			end
			3'd4:
			begin
				pcasrc = (zero == = 1'bx)?1'b1:zero;
				pcbsrc = 1'b0;
			end
			3'd5:
			begin
				pcasrc = (zero == = 1'bx)?1'b1:~zero;
				pcbsrc = 1'b0;
			end
			3'd6:
			begin
				pcasrc = (less == = 1'bx)?1'b1:less;
				pcbsrc = 1'b0;
			end
			3'd7:
			begin
				pcasrc = (less == = 1'bx)?1'b1:~less;
				pcbsrc = 1'b0;
			end
			default:
			begin
				pcasrc = 1'b0;
				pcbsrc = 1'b0;
			end
		endcase
	end
endmodule

/* verilator lint_off COMBDLY */
module controlsig(op, func3, func7, extop, regwr,aluasrc,alubsrc,aluctr,branch, memtoreg, memwr, memop);
	input[6:0] op;
	input[2:0] func3;
	input[6:0] func7;
	output reg[2:0] extop;
	output reg regwr;
	output reg aluasrc;
	output reg[1:0] alubsrc;
	output reg[3:0] aluctr;
	output reg[2:0] branch;
	output reg memtoreg;
	output reg memwr;
	output reg[2:0] memop;

	always@(*)
	begin
		//assign default values;
			extop <= 3'b0;
			regwr <= 1'b0;
			aluasrc <= 1'b0;
			alubsrc <= 2'b0;
			aluctr <= 4'b0;
			branch <= 3'b0;
			memtoreg <= 1'b0;
			memwr <= 1'b0;
			memop <= 3'b0;
			case(op[6:2])
				5'b01101: //lui
				begin
					extop <= 3'b001;
					regwr <= 1'b1;
					alubsrc <= 2'b01;
					aluctr <= 4'b0011;
				end
				5'b00101: //auipc
				begin
					extop <= 3'b001;
					regwr <= 1'b1;
					aluasrc <= 1'b1;
					alubsrc <= 2'b01;
					aluctr <= 4'b0000;
				end
				5'b00100: //alu imm type
				begin
					regwr <= 1'b1;
					alubsrc <= 2'b01;
					aluctr <= (func3 == 3'b011)? 4'b1010: (((func3 == 3'b101)&&(func7[5]==1'b1)) ? 4'b1101: {1'b0, func3 }); //special case for sltiu and srai
	end
		5'b01100: //alu reg type
		begin
		regwr <= 1'b1;
		aluctr <= (func3 == 3'b011)? 4'b1010:  {func7[5], func3}; //special case for sltu
	end
		5'b11011: //jal
		begin
		extop <= 3'b100;
		regwr <= 1'b1;
		branch <= 3'b001;
		aluasrc <= 1'b1;
		alubsrc <= 2'b10;
		end
		5'b11001: //jalr
		begin
		extop <= 3'b000;
		regwr <= 1'b1;
		branch <= 3'b010;
		aluasrc <= 1'b1;
		alubsrc <= 2'b10;
		end
		5'b11000: //branch
		begin
		extop <= 3'b011;
		branch <= {1'b1,func3[2],func3[0]};
		aluctr <= (func3[2:1] == 2'b11)? 4'b1010: 4'b0010;
			end
			5'b00000: //load
			begin
			regwr <= 1'b1;
			memtoreg <= 1'b1;
			memop <= func3;
	alubsrc <= 2'b01;
		end
		5'b01000://store
		begin
		extop <= 3'b010;
		memwr <= 1'b1;
		memop <= func3;
	alubsrc <= 2'b01;
		end
			default:
				;
				endcase
					end
					endmodule

					module immgen(instr, extop, imm);
				input[31:0] instr;
				input[2:0] extop;
				output reg[31:0] imm;

				wire[31:0] immI, immU, immS, immB, immJ;


				assign immI = { {20{instr[31]}}, instr[31:20] };
				assign immU = { instr[31:12], 12'b0};
				assign immS = {{20{instr[31]}}, instr[31:25], instr[11:7]};
				assign immB = {{20{instr[31]}}, instr[7], instr[30:25], instr[11:8], 1'b0};
				assign immJ = {{12{instr[31]}}, instr[19:12], instr[20], instr[30:21], 1'b0};

				always@(*)
				begin
					case(extop)
					   3'b000:
						   imm = immI;
						3'b001:
							imm = immU;
						3'b010:
						   imm = immS;
						3'b011:
							imm = immB;
						3'b100:
						   imm = immJ;
						default:
							imm = immI;
					endcase
				end

			endmodule

			module pcgen(pc, imm, rs1data, pcasrc, pcbsrc, nextpc, instr);
				input[31:0] pc;
				input[31:0] imm;
				input[31:0] rs1data;
				input pcasrc,pcbsrc;
				output[31:0] nextpc;
				input[31:0] instr;

				wire[31:0] pca, pcb;

				assign pca = (pcasrc == 1'b1)? (imm&32'hfffffffe) : 32'd4;
				assign pcb = (pcbsrc == 1'b1)? (rs1data&32'hfffffffe) : pc;

				assign nextpc = (instr != 32'hdead10cc) ? pca + pcb:pc;
			endmodule

			module regfile(
				input[4:0]  ra,
				input[4:0]  rb,
				input[4:0]  rw,
				input[31:0] wrdata,
				output[31:0] outa,
				output[31:0] outb,
				input regwr,
				input  wrclk
			);

			  reg[31:0] regs[31:0];
			  initial begin
					regs[0] = 32'b0;
				end
			  assign outa = regs[ra];
			  assign outb = regs[rb];

			  always@(posedge wrclk)
				begin
					if (regwr == 1'b1) regs[rw] <= (rw==5'b00000) ? 32'b0:wrdata;
				end
			endmodule
