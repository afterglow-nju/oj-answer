% {
#include "lex.yy.c"
#define MAXCHILD 8
	extern int lines;
	struct syntax_tree {
		char type[32];
		char value[32];
		int value_int;
		float value_float;
		int has_value;
		int is_syn;
		int line;
		int count; // the number of children
		int empty; // empty rule (the node is both non-terminal and leaf)
		struct syntax_tree* child[MAXCHILD];
	};

	struct syntax_tree* newnode(char* type, int child_num, struct syntax_tree* childlist[], int current_line) {
		//printf("newnode: %s\n", type);
		struct syntax_tree* new = malloc(sizeof(struct syntax_tree));
		strcpy(new->type, type);
		new->has_value = 0;
		new->count = child_num;
		new->empty = 0;
		new->is_syn = 0;
		new->line = current_line;
		for (int i = 0; i < child_num; i++) {
			new->child[i] = childlist[i];
			//printf("  child: %s\n", childlist[i]->type);
		}
		return new;
	}

	struct syntax_tree* leaf(char* type, char* value) {
		//printf("leaf: %s\n", type);
		struct syntax_tree* new = malloc(sizeof(struct syntax_tree));
		strcpy(new->type, type);
		if (value != NULL) {
			strcpy(new->value, value);
			new->has_value = 1;
			//printf("  value = %s\n", value);
		}
		/*
		else
		{
			printf("type=%s\n",type);
			printf("      %s\n",value);
		}
		*/
		new->count = 0;
		new->empty = 0;
		new->is_syn = 1;
		return new;
	}

	struct syntax_tree* leaf_int(char* type, int value) {
		//printf("leaf: %s\n", type);
		struct syntax_tree* new = malloc(sizeof(struct syntax_tree));
		strcpy(new->type, type);
		new->value_int = value;
		new->has_value = 1;
		//printf("  value = %d\n", value);
		new->count = 0;
		new->empty = 0;
		new->is_syn = 1;
		return new;
	}

	struct syntax_tree* leaf_float(char* type, float value) {
		//printf("leaf: %s\n", type);
		struct syntax_tree* new = malloc(sizeof(struct syntax_tree));
		strcpy(new->type, type);
		new->value_float = value;
		new->has_value = 1;
		//printf("  value = %f\n", value);
		new->count = 0;
		new->empty = 0;
		new->is_syn = 1;
		return new;
	}

	struct syntax_tree* empty() {
		struct syntax_tree* new = malloc(sizeof(struct syntax_tree));
		new->empty = 1;
		return new;
	}

	void print_tree(struct syntax_tree* root, int level) {
		if (exist_error) return;
		if (root->empty) return;
		for (int i = 0; i < level; i++)
		{
			printf("  ");
		}
		printf("%s", root->type);
		if (root->is_syn == 0)
		{
			printf(" (%d)", root->line);
		}
		if (root->has_value) {
			if (strcmp(root->type, "INT") == 0) {
				printf(": %d", root->value_int);
			}
			else if (strcmp(root->type, "FLOAT") == 0) {
				printf(": %f", root->value_float);
			}
			else {
				printf(": %s", root->value);
			}
		}
		printf("\n");
		for (int i = 0; i < root->count; i++) {
			if (root->child[i] != NULL) print_tree(root->child[i], level + 1);
		}
	}

	int yyerror(char* msg) {
		printf("Error type B at Line %d: Syntax error.\n", lines + 1);
	}
	%}
% locations
% union {
	int Int;
	float Float;
	char* String;
	struct syntax_tree* t;
}

/* declared tokens */
% token <String>ID TYPE
% token <Int>INT
% token <Float>FLOAT
% token <t> PLUS MINUS STAR DIV AND OR DOT NOT
% token <t> SEMI COMMA ASSIGNOP RELOP
% token <t> LP RP LB RB LC RC
% token <t> STRUCT RETURN IF ELSE WHILE

/* declared non-terminals */
% type <t> Program ExtDefList ExtDef ExtDecList
% type <t> Specifier StructSpecifier OptTag Tag
% type <t> VarDec FunDec VarList ParamDec
% type <t> CompSt StmtList Stmt
% type <t> DefList Def DecList Dec
% type <t> Exp Args

% right ASSIGNOP
% left OR
% left AND
% left RELOP
% left PLUS MINUS
% left STAR DIV
% right NEG NOT
% left DOT LP RP LB RB

% nonassoc LOWER_THAN_ELSE
% nonassoc ELSE
%%
Program : ExtDefList{ struct syntax_tree* a[] = {$1}; $$ = newnode("Program", 1, a, @1.first_line); print_tree($$,0); }
;
ExtDefList: {$$ = empty(); } /* empty */
| ExtDef ExtDefList{ struct syntax_tree* a[] = {$1, $2}; $$ = newnode("ExtDefList", 2, a,@1.first_line); }
;
ExtDef: Specifier ExtDecList SEMI{ $3 = leaf("SEMI", NULL); struct syntax_tree* a[] = {$1, $2, $3}; $$ = newnode("ExtDef", 3, a, @1.first_line); }
| Specifier SEMI{ $2 = leaf("SEMI", NULL); struct syntax_tree* a[] = {$1, $2}; $$ = newnode("ExtDef", 2, a, @1.first_line); }
| Specifier FunDec CompSt{ struct syntax_tree* a[] = {$1, $2, $3}; $$ = newnode("ExtDef", 3, a, @1.first_line); }
| Specifier ExtDecList error SEMI{ exist_error = 1; DEBUGPRINT("recover from: Specifier ExtDecList error SEMI\n"); }
| Specifier error SEMI{ exist_error = 1; DEBUGPRINT("recover from: Specifier error SEMI\n"); }
;
ExtDecList: VarDec{ struct syntax_tree* a[] = {$1}; $$ = newnode("ExtDecList", 1, a, @1.first_line); }
| VarDec COMMA ExtDecList{ $2 = leaf("COMMA", NULL); struct syntax_tree* a[] = {$1, $2, $3}; $$ = newnode("ExtDecList", 3, a, @1.first_line); }
;

Specifier: TYPE{ struct syntax_tree* a[] = {leaf("TYPE",$1)}; $$ = newnode("Specifier", 1, a, @1.first_line); }
| StructSpecifier{ struct syntax_tree* a[] = {$1}; $$ = newnode("Specifier", 1, a, @1.first_line); }
;
StructSpecifier: STRUCT OptTag LC DefList RC{ $1 = leaf("STRUCT", NULL); $3 = leaf("LC", NULL); $5 = leaf("RC", NULL); struct syntax_tree* a[] = {$1, $2, $3, $4, $5}; $$ = newnode("StructSpecifier", 5, a, @1.first_line); }
| STRUCT Tag{ $1 = leaf("STRUCT", NULL); struct syntax_tree* a[] = {$1, $2}; $$ = newnode("StructSpecifier", 2, a, @1.first_line); }
;
OptTag: {$$ = empty(); } /* empty */
| ID{ struct syntax_tree* a[] = {leaf("ID", $1)}; $$ = newnode("OptTag", 1, a, @1.first_line); }
;
Tag: ID{ struct syntax_tree* a[] = {leaf("ID", $1)}; $$ = newnode("Tag", 1, a, @1.first_line); }
;

VarDec: ID{ struct syntax_tree* a[] = {leaf("ID", $1)}; $$ = newnode("VarDec", 1, a, @1.first_line); }
| VarDec LB INT RB{ $2 = leaf("LB", NULL); $4 = leaf("RB", NULL); struct syntax_tree* a[] = {$1, $2, leaf_int("INT", $3), $4}; $$ = newnode("VarDec", 4, a, @1.first_line); }
;
FunDec: ID LP VarList RP{ $2 = leaf("LP", NULL); $4 = leaf("RP", NULL); struct syntax_tree* a[] = {leaf("ID", $1), $2, $3, $4}; $$ = newnode("FunDec", 4, a, @1.first_line); }
| ID LP RP{ $2 = leaf("LP", NULL); $3 = leaf("RP", NULL); struct syntax_tree* a[] = {leaf("ID", $1), $2, $3}; $$ = newnode("FunDec", 3, a, @1.first_line); }
| ID LP VarList error RP{ exist_error = 1; DEBUGPRINT("recover from: ID LP VarList error RP\n"); }
| ID LP error RP{ exist_error = 1; DEBUGPRINT("recover from: ID LP error RP\n"); }
;
VarList: ParamDec COMMA VarList{ $2 = leaf("COMMA", NULL); struct syntax_tree* a[] = {$1, $2, $3}; $$ = newnode("VarList", 3, a, @1.first_line); }
| ParamDec{ struct syntax_tree* a[] = {$1}; $$ = newnode("VarList", 1, a, @1.first_line); }
;
ParamDec: Specifier VarDec{ struct syntax_tree* a[] = {$1, $2}; $$ = newnode("ParamDec", 2, a, @1.first_line); }
;

CompSt: LC DefList StmtList RC{ $1 = leaf("LC", NULL); $4 = leaf("RC", NULL); struct syntax_tree* a[] = {$1, $2, $3, $4}; $$ = newnode("CompSt", 4, a, @1.first_line); }
| LC DefList StmtList error RC{ exist_error = 1; DEBUGPRINT("recover from: LC DefList StmtList error RC\n"); }
;
StmtList: {$$ = empty(); } /* empty */
| Stmt StmtList{ struct syntax_tree* a[] = {$1, $2}; $$ = newnode("StmtList", 2, a, @1.first_line); }
;
Stmt: Exp SEMI{ $2 = leaf("SEMI", NULL); struct syntax_tree* a[] = {$1, $2}; $$ = newnode("Stmt", 2, a, @1.first_line); }
| CompSt{ struct syntax_tree* a[] = {$1}; $$ = newnode("Stmt", 1, a, @1.first_line); }
| RETURN Exp SEMI{ $1 = leaf("RETURN", NULL); $3 = leaf("SEMI", NULL); struct syntax_tree* a[] = {$1, $2, $3}; $$ = newnode("Stmt", 3, a, @1.first_line); }
| IF LP Exp RP Stmt % prec LOWER_THAN_ELSE{ $1 = leaf("IF", NULL); $2 = leaf("LP", NULL); $4 = leaf("RP", NULL); struct syntax_tree* a[] = {$1, $2, $3, $4, $5}; $$ = newnode("Stmt", 5, a, @1.first_line); }
| IF LP Exp RP Stmt ELSE Stmt{ $1 = leaf("IF", NULL); $2 = leaf("LP", NULL); $4 = leaf("RP", NULL); $6 = leaf("ELSE", NULL); struct syntax_tree* a[] = {$1, $2, $3, $4, $5, $6, $7}; $$ = newnode("Stmt", 7, a, @1.first_line); }
| WHILE LP Exp RP Stmt{ $1 = leaf("WHILE", NULL); $2 = leaf("LP", NULL); $4 = leaf("RP", NULL); struct syntax_tree* a[] = {$1, $2, $3, $4, $5}; $$ = newnode("Stmt", 5, a, @1.first_line); }
| Exp error SEMI{ exist_error = 1; DEBUGPRINT("recover from: Exp error SEMI\n"); }
| RETURN Exp error SEMI{ exist_error = 1; DEBUGPRINT("recover from: RETURN Exp error SEMI\n"); }
| IF LP error RP Stmt{ exist_error = 1; DEBUGPRINT("recover from: IF LP error RP Stmt\n"); }
| IF LP error RP Stmt ELSE Stmt{ exist_error = 1; DEBUGPRINT("recover from: IF LP error RP Stmt ELSE Stmt\n"); }
| WHILE LP error RP Stmt{ exist_error = 1; DEBUGPRINT("recover from: WHILE LP error RP Stmt\n"); }
;

DefList: {$$ = empty(); } /* empty */
| Def DefList{ struct syntax_tree* a[] = {$1, $2}; $$ = newnode("DefList", 2, a, @1.first_line); }
;
Def: Specifier DecList SEMI{ $3 = leaf("SEMI", NULL); struct syntax_tree* a[] = {$1, $2, $3}; $$ = newnode("Def", 3, a, @1.first_line); }
| Specifier error SEMI{ exist_error = 1; DEBUGPRINT("recover from: Specifier error SEMI\n"); }
;
DecList: Dec{ struct syntax_tree* a[] = {$1}; $$ = newnode("DecList", 1, a, @1.first_line); }
| Dec COMMA DecList{ $2 = leaf("COMMA", NULL); struct syntax_tree* a[] = {$1, $2, $3}; $$ = newnode("DecList", 3, a, @1.first_line); }
;
Dec: VarDec{ struct syntax_tree* a[] = {$1}; $$ = newnode("Dec", 1, a, @1.first_line); }
| VarDec ASSIGNOP Exp{ $2 = leaf("ASSIGNOP", NULL); struct syntax_tree* a[] = {$1, $2, $3}; $$ = newnode("Dec", 3, a, @1.first_line); }
;

Exp: Exp ASSIGNOP Exp{ $2 = leaf("ASSIGNOP", NULL); struct syntax_tree* a[] = {$1, $2, $3}; $$ = newnode("Exp", 3, a, @1.first_line); }
| Exp AND Exp{ $2 = leaf("AND", NULL); struct syntax_tree* a[] = {$1, $2, $3}; $$ = newnode("Exp", 3, a, @1.first_line); }
| Exp OR Exp{ $2 = leaf("OR", NULL); struct syntax_tree* a[] = {$1, $2, $3}; $$ = newnode("Exp", 3, a, @1.first_line); }
| Exp RELOP Exp{ $2 = leaf("RELOP", NULL); struct syntax_tree* a[] = {$1, $2, $3}; $$ = newnode("Exp", 3, a, @1.first_line); }
| Exp PLUS Exp{ $2 = leaf("PLUS", NULL); struct syntax_tree* a[] = {$1, $2, $3}; $$ = newnode("Exp", 3, a, @1.first_line); }
| Exp MINUS Exp{ $2 = leaf("MINUS", NULL); struct syntax_tree* a[] = {$1, $2, $3}; $$ = newnode("Exp", 3, a, @1.first_line); }
| Exp STAR Exp{ $2 = leaf("STAR", NULL); struct syntax_tree* a[] = {$1, $2, $3}; $$ = newnode("Exp", 3, a, @1.first_line); }
| Exp DIV Exp{ $2 = leaf("DIV", NULL); struct syntax_tree* a[] = {$1, $2, $3}; $$ = newnode("Exp", 3, a, @1.first_line); }
| LP Exp RP{ $1 = leaf("LP", NULL); $3 = leaf("RP", NULL); struct syntax_tree* a[] = {$1, $2, $3}; $$ = newnode("Exp", 3, a, @1.first_line); }
| MINUS Exp % prec NEG{ $1 = leaf("MINUS", NULL); struct syntax_tree* a[] = {$1, $2}; $$ = newnode("Exp", 2, a, @1.first_line); }
| NOT Exp{ $1 = leaf("NOT", NULL); struct syntax_tree* a[] = {$1, $2}; $$ = newnode("Exp", 2, a, @1.first_line); }
| ID LP Args RP{ $2 = leaf("LP", NULL); $4 = leaf("RP", NULL); struct syntax_tree* a[] = {leaf("ID", $1), $2, $3, $4}; $$ = newnode("Exp", 4, a, @1.first_line); }
| ID LP RP{ struct syntax_tree* tem = leaf("ID", $1); $2 = leaf("LP", NULL); $3 = leaf("RP", NULL); struct syntax_tree* a[] = {tem, $2, $3}; $$ = newnode("Exp", 3, a, @1.first_line); }
| Exp LB Exp RB{ $2 = leaf("LB", NULL); $4 = leaf("RB", NULL); struct syntax_tree* a[] = {$1, $2, $3, $4}; $$ = newnode("Exp", 4, a, @1.first_line); }
| Exp DOT ID{ $2 = leaf("DOT", NULL); struct syntax_tree* a[] = {$1, $2, leaf("ID", $3)}; $$ = newnode("Exp", 3, a, @1.first_line); }
| ID{ struct syntax_tree* a[] = {leaf("ID", $1) }; $$ = newnode("Exp", 1, a, @1.first_line); }
| INT{ struct syntax_tree* a[] = {leaf_int("INT", $1)}; $$ = newnode("Exp", 1, a, @1.first_line); }
| FLOAT{ struct syntax_tree* a[] = {leaf_float("FLOAT", $1)}; $$ = newnode("Exp", 1, a, @1.first_line); }
;
Args: Exp COMMA Args{ $2 = leaf("COMMA", NULL); struct syntax_tree* a[] = {$1, $2, $3}; $$ = newnode("Args", 3, a, @1.first_line); }
| Exp{ struct syntax_tree* a[] = {$1}; $$ = newnode("Args", 1, a, @1.first_line); }
;
%%

