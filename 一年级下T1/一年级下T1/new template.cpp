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
long long v[1001], ti[1001], dp[101][10001];
int main()
{
	int t,n,m;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		memset(v, 0, sizeof(v));
		memset(ti, 0, sizeof(ti));
		for (int i = 0; i < 101; i++)
		{
			for (int j = 0; j < 10001; j++)
			{
				dp[i][j] = 0;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> v[i] >> ti[i];
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= m; j++)
			{	
				dp[i][j] = dp[i - 1][j];
				if (j >= ti[i])
				{
					dp[i][j] = max(dp[i][j], dp[i - 1][j - ti[i]] + v[i]);
				}
			}
		}
		cout << dp[n][m]<<'\n';

	}
}






