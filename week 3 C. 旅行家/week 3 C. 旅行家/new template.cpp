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
const long long maxn = 4000001;
long long mod = 1e9 + 7;
vector<pair< long long, long long> > edge[maxn];
void addedge(long long x, long long y, long long z) {
	edge[x].push_back(make_pair(y, z));
}
long long dis[maxn],length[maxn],h[maxn];
queue<int> q;
int main()
{
	int n, m;
	cin >> n >> m;
	int num = n;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w, len = 0, we[11], node[11];
		cin >> u >> v >> w;
		while (w)
		{
			we[++len] = w % 10;
			w /= 10;
		}
		node[0] = u; node[len] = v;
		for (int i = 1; i < len; i++)
		{
			node[i] = ++num;///保证特殊性
		}
		for (int i = 1; i <= len; i++)
		{
			addedge(node[i - 1], we[len - i + 1], node[i]);//弱智！！！！
		}
		node[len] = u; node[0] = v;
		for (int i = 1; i < len; i++)
		{
			node[i] = ++num;
		}
		for (int i = 1; i <= len; i++)
		{
			addedge(node[i - 1], we[len-i+1], node[i]);
		}
	}
	/*
	for (int t = 1; t <=num ; t++)
	{
		vector<pair< long long, long long> > ::iterator it;
		cout << "is" << t << '\n';
		for (it = edge[t].begin(); it != edge[t].end(); it++)
		{
			cout << it->first << " " << it->second << '\n';
		}
	}*/
	::memset(dis, -1, sizeof(dis));
	dis[1] = 0; length[1] = 0;
	q.push(1);
	while (!q.empty())
	{
		int t = q.front(), len = 1;
		q.pop();
		h[len] = t;//h代表同位数同
		while ((!q.empty()) && (dis[q.front()] == dis[t]) && (length[q.front()] == length[t]))
		{
			h[++len] = q.front();
			q.pop();
		}
		vector<pair< long long, long long> > ::iterator it;
		for (int i = 0; i <= 9; i++)
		{
			for (int j = 1; j <= len; j++)
			{
				for (it = edge[h[j]].begin(); it != edge[h[j]].end(); it++)
				{
					if (it->first != i)continue;
					if (dis[it->second] == -1)
					{
						//if ((dis[t] * 10 + it->first) % mod < dis[it->second])
						//{
						dis[it->second] = (dis[t] * 10 + it->first) % mod;
						length[it->second] = length[t] + 1;
						q.push(it->second);
						//}
					}
				}

			}

		}

		
	}
	for (int i = 2; i <= n; i++)
	{
		//	if (dis[i] > mod)cout << -1 << '\n';
		//	else
		cout << dis[i] % mod << '\n';
	}
}






