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
const ll maxn1 = 200001;
long long dis[maxn1];
vector<pair< long long, long long> > edge[maxn1];
void addedge(long long x, long long y, long long z) {
	edge[x].push_back(make_pair(y, z));
}
vector<pair< long long, long long> > ::iterator it;

priority_queue < pair<long long, long long>, vector < pair < long long, long long >>, greater<pair<long long, long long>> > q;
const long long maxn = 922337203685477;
int f[101][101][101];
int bemax[101][101][101], bemin[101][101][101];
int weight[101][101];
int main()
{
	int t1, t2;
	int n, m;
	cin >> t1>>t2>>n >> m;
	if (t1 == 0 && t2 == 0)
	{
		for (int i = 1; i <= m; i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			addedge(u, v, w);
			addedge(v, u, w);
		}
		dis[1] = 0;
		q.push(make_pair(dis[1], 1));
		for (int i = 2; i <= n; i++)
		{
			dis[i] = maxn;
		}
		while (!q.empty())
		{
			pair<long long, long long> t = q.top();
			q.pop();
			long long x = t.second;
			if (dis[x] != t.first)
				continue;
			for (it = edge[x].begin(); it != edge[x].end(); it++)
			{
				long long y = it->first, w = it->second;

				if (dis[y] > w + dis[x])
				{
					dis[y] = w + dis[x];
					q.push(make_pair(dis[y], y));
				}
			}
		}
		for (int i = 2; i <= n; i++)
		{
			cout << dis[i] << " ";
		}
	}
	else if(n<=100&&m<=200)
	{	
		for (int i = 0; i <= 100; i++)
		{
			for (int j = 0; j <= 100; j++)
			{
				for (int k = 0; k <= 100; k++)
				{
					bemin[i][j][k] = maxn;
				}
			}
		}

		for (int i = 1; i <= m; i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			f[0][u][v] = w;
			weight[u][v] = w;
			bemax[0][u][v] = max(bemax[0][u][v], w);
			bemin[0][u][v] = min(bemin[0][u][v], w);

		}
		for (int k = 1; k <= n; k++)
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{/*
					int newmin = min(weight[i][k], min(weight[k][j], min(bemin[k - 1][i][k], bemin[k - 1][k][j])));
					int newmax = max(weight[i][k], max(weight[k][j], max(bemax[k - 1][i][k], bemax[k - 1][k][j])));
					*/
					int newmin = min(bemin[k - 1][i][k], bemin[k - 1][k][j]);
					int newmax = max(bemax[k - 1][i][k], bemax[k - 1][k][j]);
					int newweight = f[k - 1][i][k] + f[k - 1][k][j] + t1 * (bemax[k - 1][i][k] + bemax[k - 1][k][j] - newmax) - t2 * (bemin[k - 1][i][k] + bemin[k - 1][k][j] - newmin);
					if (f[k - 1][i][j] > newweight)
					{
						f[k][i][j] = newweight;
						
					}
					else
					{
						f[k][i][j] = f[k - 1][i][j];
					}
					bemin[k][i][j] = newmin;
					bemax[k][i][j] = newmax;
				}
			}
		}
		for (int i = 2; i <= n; i++)
		{
			cout << -f[n][1][i] << " ";
		}
	}
}