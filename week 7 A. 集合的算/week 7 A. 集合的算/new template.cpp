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
const ll mod = 998244353;
int n, k;
int a[1001];
ll total = 0;

ll f[1001][1001];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		total = 0;
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		sort(a+1, a + n+1);
		f[0][0] = 0;
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= k; j++)f[i][j] = 0;
		}
		for (int i = 0; i <= n; i++)f[i][0] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= k; j++)
			{
				if (f[i - 1][j])
				{
					f[i][j] = f[i - 1][j];
				}
				if (j >= a[i])f[i][j] =(f[i][j]+ f[i - 1][j - a[i]])%mod;
			}
		}
		/*
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= k; j++)
			{
				cout <<"i="<<i<<"j="<<j<<"f="<<f[i][j] <<'\n';
			}
			cout << '\n';
		}*/
		total = f[n][k];
		cout << total << '\n';
	}
}