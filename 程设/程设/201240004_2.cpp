#include<iostream>
using namespace std;
bool f(int a, int b);
int k;
int main()
{
	int x, y;
	cin >> x >> y;
	if (f(x, y))
		cout << "Girl";
	else cout << "Boy";
	return 0;
}
bool f(int a, int b)
{
	if (a == 1) return true;
	if ((b % 2 == 0) && (b != 1))
	{
		k = b / 2;
		return !f(a - 1, k);
	}
	else
	{
		k = (b + 1) / 2;
		return f(a - 1, k);
	}

	//	if (a == 2 && b == 1) return true;
	//	if (a == 2 && b == 2) return false;
}
