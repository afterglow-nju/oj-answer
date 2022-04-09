#include<iostream>
using namespace std;

class MC
{
private:
	int a[6][4];
public:
	MC();
	void rotatex();
	void rotatey();
	void rotatez();
	bool isGood();
};

MC::MC() {
	for (int i = 0; i < 6; ++i)
		for (int j = 0; j < 4; ++j)
		{
			cin >> a[i][j];
		}
}
void MC::rotatex() {
	int tmp0 = a[3][0], tmp1 = a[3][1];
	for (int i = 3; i > 0; --i)
	{
		a[i][0] = a[i - 1][0];
		a[i][1] = a[i - 1][1];
	}
	a[0][0] = tmp0, a[0][1] = tmp1;
	return;
}
void MC::rotatey() {
	int tmp0 = a[0][0], tmp2 = a[0][2];
	a[0][0] = a[4][0], a[0][2] = a[4][2];
	a[4][0] = a[2][3], a[4][0] = a[2][1];
	a[2][3] = a[5][0], a[2][1] = a[5][2];
	a[5][0] = tmp0, a[5][2] = tmp2;
	return;
}
void MC::rotatez() {
	int tmp0 = a[1][0], tmp2 = a[1][2];
	a[1][0] = a[4][2], a[1][2] = a[4][3];
	a[4][2] = a[3][3], a[4][3] = a[3][1];
	a[3][3] = a[5][1], a[3][1] = a[5][0];
	a[5][0] = tmp2, a[5][1] = tmp0;
	return;
}
bool MC::isGood() {
	bool ret = true;
	for (int i = 0; i < 6; ++i)
		for (int j = 1; j < 4; ++j)
		{
			ret &= (a[i][j] = a[i][0]);
		}
	return ret;
}

int main() {
	int num;
	cin >> num;
	bool flag;
	while (num--)
	{
		flag = false;
		MC tmpMC;
		tmpMC.rotatex();
		flag |= tmpMC.isGood();
		if (!flag)
		{
			tmpMC.rotatex();
			tmpMC.rotatex();
			flag |= tmpMC.isGood();
			if (!flag)
				tmpMC.rotatex();
		}

		if (!flag)
		{
			tmpMC.rotatey();
			flag |= tmpMC.isGood();
			if (!flag)
			{
				tmpMC.rotatey();
				tmpMC.rotatey();
				flag |= tmpMC.isGood();
				if (!flag)
					tmpMC.rotatey();
			}
		}

		if (!flag)
		{
			tmpMC.rotatez();
			flag |= tmpMC.isGood();
			if (!flag)
			{
				tmpMC.rotatez();
				tmpMC.rotatez();
				flag |= tmpMC.isGood();
			}
		}
	}

	cout << (flag ? "YES" : "NO") << endl;
	return 0;
}