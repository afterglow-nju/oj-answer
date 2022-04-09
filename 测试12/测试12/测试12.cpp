#include<iostream>
using namespace std;


int MC[24];


void initMC();

void rotateX();
void rotateY();
void rotateZ();

bool isGood();



int main() {
	int num;
	bool flag = false;
	cin >> num;
	while (num--)
	{
		flag = false;
		initMC();
		flag |= isGood();
		if (!flag)
		{
			rotateX();
			flag |= isGood();
			if (!flag)
			{
				rotateX();
				rotateX();
				flag |= isGood();
				rotateX();
			}
		}
		if (!flag)
		{
			rotateY();
			flag |= isGood();
			if (!flag)
			{
				rotateY();
				rotateY();
				flag |= isGood();
				rotateY();
			}
		}
		if (!flag)
		{
			rotateZ();
			flag |= isGood();
			if (!flag)
			{
				rotateZ();
				rotateZ();
				flag |= isGood();
			}
		}

		cout << (flag ? "YES" : "NO") << endl;
	}

	return 0;
}


void initMC() {
	for (int i = 0; i < 24; ++i)
		cin >> MC[i];
}

void rotateX() {
	int tmp0 = MC[0], tmp1 = MC[2];
	MC[0] = MC[4], MC[2] = MC[6];
	MC[4] = MC[8], MC[6] = MC[10];
	MC[8] = MC[12], MC[10] = MC[14];
	MC[12] = tmp0, MC[14] = tmp1;
}

void rotateY() {
	int tmp0 = MC[14], tmp1 = MC[15];
	MC[14] = MC[20], MC[15] = MC[22];
	MC[20] = MC[5], MC[22] = MC[4];
	MC[5] = MC[19], MC[4] = MC[17];
	MC[19] = tmp0, MC[17] = tmp1;
}

void rotateZ() {
	int tmp0 = MC[2], tmp1 = MC[3];
	MC[2] = MC[22], MC[3] = MC[23];
	MC[22] = MC[9], MC[23] = MC[8];
	MC[9] = MC[18], MC[8] = MC[19];
	MC[18] = tmp0, MC[19] = tmp1;
}

bool isGood() {
	bool ret = true;
	for (int i = 0; i < 24; ++i)
		ret &= (MC[i] == MC[i / 4 * 4]);
	return ret;
}