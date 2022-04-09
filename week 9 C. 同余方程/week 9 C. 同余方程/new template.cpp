#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<bitset>
#include<stack>
#include<utility>
#include<iomanip>
#include<vector>
#include<math.h>
#include<string>
#include<stdio.h>
#include<limits>
using namespace std;

void ext_gcd(int a, int b, int& d, int& x, int& y)
{
	if (!b)
	{
		d = a;
		x = 1;
		y = 0;
	}
	else
	{
		ext_gcd(b, a % b, d, y, x);
		y -= x * (a / b);
	}
}
int main()
{
	int a, b;
	cin >> a >> b;
	int d; int x; int y;
	ext_gcd(a, b, d, x, y);
	while (x < 0)
	{
		x += b;
	}
	cout << x;
}






