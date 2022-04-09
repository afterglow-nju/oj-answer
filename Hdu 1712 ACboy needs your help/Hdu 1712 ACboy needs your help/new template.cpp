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
const int maxn = 200;
int kind[maxn],d[maxn][maxn],w[maxn],v[maxn];
int main()
{
	int n, t, m, s;
	while (cin >> n >> t)
	{	
		for (int i = 0; i < maxn; i++)
		{
			for (int j = 0; j < maxn; j++)
			{
				d[i][j] = -1;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> m >> s;
			if (s == 0)
			{
				for (int i = 1; i <= m; i++)
				{
					cin >> w[i] >> v[i];
				}
				for (int k = 1; k <= m; k++)
				{
					for (int j = t; j >= w[k]; j--)
					{
						if (d[i][j - w[k]] != 0)
						{
							d[i][j] = max(d[i][j], d[i][j - w[k]] + v[k]);
						}
						if (d[i - 1][j - w[k]] != 0)
						{
							d[i][j] = max(d[i][j], d[i - 1][j - w[k]] + v[k]);
						}
					}
				}
			}
			else if (s == 1)
			{
				for (int i = 1; i <= m; i++)
				{
					cin >> w[i] >> v[i];
				}
				for (int j = t; j >= 0; j--)
				{
					for (int k = 1; k <= m; k++)
					{
						if (j >= w[k])
						{
							d[i][j] = max(d[i][j], d[i][j - w[k]] + v[k]);
						}
					}
				}
			}
			else
			{
				for (int i = 1; i <= m; i++)
				{
					cin >> w[i] >> v[i];
				}
				for (int k = 1; k <= m; k++)
				{
					for (int j = t; j >=w[k]; j--)
					{
						d[i][j] = max(d[i][j], d[i][j - w[k]] + v[k]);
					}
				}
			}
		}
		cout << d[n][t] << '\n';
	}
}






