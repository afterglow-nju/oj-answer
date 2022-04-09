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
typedef long long ll;
ll mod =319;
ll quick_power(ll x, ll y)//x^y
{
	ll tem = 1;
	for (; y; y >>= 1, x = x * x % mod)
	{
		if (y & 1)tem = tem * x % mod;
	}
	return tem;
}

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
	cout << quick_power(100,0);
	int a, b, d, x, y;
	cin >> a >> b;
	ext_gcd(a, b, d, x, y);
	cout << "a multipltive inverse mod b=" << x;

	/*
	char a[100];
	for (int i = 1; i <= 6; i++)
	{
		cin >> a[i];
	}
	int count = 0;
	for (int i = 1; i <= 26; i++)
	{
		for (int j = 1; j <= 6; j++)
		{
			int tem = a[j] + i;
			if (tem > 90)
			{
				tem = tem - 90 + 64;
			}
			cout << char(tem+32);
			//if (j % 5 == 0)//cout <<"	";
		}
		cout << '\n';
	}

	while (1)
	{
		int x, y;
		cin >> mod >> x >> y;
		cout << quick_power(x, y) << '\n';
	}*/
}






