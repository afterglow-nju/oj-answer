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
long long v[1001], ti[1001], dp[101][10001],dp2[1001][200000];
int main()
{
	int t, n, m;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		memset(v, 0, sizeof(v));
		memset(ti, 0, sizeof(ti));
		if (m <= 10000)
		{
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
			cout << dp[n][m] << '\n';
		}
		else
		{
			for (int i = 0; i < 1001; i++)
			{
				for (int j = 0; j < 200000; j++)
				{
					dp2[i][j] = INT_MAX;
				}
			}
			long long value = 0;//统计最大学分
			for (int i = 1; i <= n; i++)
			{
				cin >> v[i] >> ti[i];
				value += v[i];

			}
			dp2[0][0] = 0;
			for (int i = 1; i <= n; i++)
			{
				for (int j = 0; j <= value; j++)
				{
					dp2[i][j] = dp2[i - 1][j];
					if (j - v[i] >= 0)//如果剩下的时间还够的话就尝试选这门课
					{
						dp2[i][j] = max(dp2[i][j], dp2[i - 1][j - v[i]]+ti[i]);
					}
					//cout << i << " " << j << " " << dp[i][j]<<'\n';
				}
			}

			for (int i = value; i >= 1; i--)
			{
				if (dp2[n][i] >= 0)
				{
					cout << i << " ";
					break;
				}
			}

		}
	}
}
/*
因为m的值太大，所以把m放在dp值的位置。dp[n][k]代表选到了第n门课，现在有k的学分的情况下，还剩的时间的数量
转移方程dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]]-ti[i]);
最后要求的值就是i  i是满足dp[n][i]>=0的最大的i
*/






