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
ll a[100001], p[40];//log(1e12)<=40
ll gcd(ll a, ll b)
{
	ll t;
	while (b)
	{
		t = a; a = b; b = t % b;
	}
	return a;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int m = 0;
	ll tem = a[1];
	for (int i = 2; 1LL * i * i <= tem; i++)
	{
		if (!(tem % i))
		{
			p[++m] = i;
			while (!(tem % i))tem /= i;//只考虑质因子是什么，不考虑质因子的次数
		}
		
	}
	if (tem != 1)p[++m] = tem;
	for (int i = 1; i <= n; i++)
	{
		ll g = gcd(a[i], a[1]);
		//cout << i << "	" << g << '\n';
		int j = 1;
		for (; j <= m; j++)
		{
			if (!(g % p[j]))
			{
				g /= p[j];
				cout << g << " ";
				break;
			}
		}
		if (j > m)cout << -1 << " ";
	}


}






