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
long long p[31];
long long f[31][501], g[31][501];
long long d[501], plan[501];
int main()
{
	int T,m,n;
	cin >> T;
	while (T--)
	{	
		bool flag = false;
		memset(f, 0, sizeof(f));
		memset(g, 0, sizeof(g));
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			cin >> p[i];
			if(m>=p[i])flag=true;
		}
		if (flag == false)
		{
			cout << "Sorry, you can't buy anything.";
		}
		else
		{	
			for (int i = 0; i <= n; i++)
			{
				for (int j = 0; j <= m; j++)g[i][j] = 1; //我们设G[i][j]代表F[i][j]的方案总数，那么最总结果应该是G[N][V]。我们初始化G[][]为1，因为对每个F[i][j]至少应该有一种方案，即前i件物品中选取若干件物品放入剩余空间为j的背包使其价值最大的方案数至少为1，因为F[i][j]一定存在。
			}
			
			for (int i = 1; i <= n; i++)
			{
				for (int v = 0; v <= m; v++)
				{
					f[i][v] = f[i - 1][v];//先取，然后在比较吧，这样方便一点
					g[i][v] = g[i - 1][v];						//说明不取更优，所以方案数等于g[i-1][v]
					if (v >= p[i])
					{
						if (f[i][v] < f[i - 1][v - p[i]] + 1)
						{
							f[i][v] = f[i - 1][v - p[i]] + 1;
							g[i][v] = g[i - 1][v - p[i]];		//说明取第i个物品更优，所以方案数等于g[i-1][v-p[i]]
						}
						else if (f[i][v] == f[i - 1][v - p[i]] + 1)	
						{
							g[i][v] += g[i - 1][v - p[i]];     // 说明取第i个物品和不取第i的物品一样优，所以方案数相加
						}
					}
					/*
					if (v - p[i] >= 0)
					{
						f[i][v] = max(f[i - 1][v], f[i - 1][v - p[i]] + 1);
					}
					else
					{
						f[i][v] = f[i - 1][v];
					}
					//		g[i][v] = 0;
					if (f[i][v] == f[i - 1][v] && f[i][v] != f[i - 1][v - p[i]] + 1)
						g[i][v] = g[i - 1][v];
					else if (f[i][v] == f[i - 1][v - p[i]] + 1 && f[i][v] != f[i - 1][v])
						g[i][v] = g[i - 1][v - p[i]];
					else g[i][v] = g[i - 1][v] + g[i - 1][v - p[i]];
					*/
				}
				
			}
			cout << "You have " << g[n][m] << " selection(s) to buy with " << f[n][m] << " kind(s) of souvenirs.";
			
			/*
				memset(d, 0, sizeof(d));
				fill(plan, plan + 501, 1);
				for (int i = 1; i <= n; i++)
				{
					for (int v = m; v >= p[i]; v--)
					{
						/*
						if (d[v] == d[v - p[i]] + 1)
						{
							plan[v] += plan[v - p[i]];//取不取都一样优，方案数相加
						}
						else if (d[v] < d[v - p[i]] + 1)
						{
							plan[v] = plan[v - p[i]];//第i个物品装入，取第i个物品最优，所以方案数是plan[v-p[i]]
						}
						d[v] = max(d[v -p[i]] + 1, d[v]);
					}
				}
				cout << "You have " << plan[m] << " selection(s) to buy with " << d[m] << " kind(s) of souvenirs.";
				*/
		}
		cout << '\n';
	}
}





