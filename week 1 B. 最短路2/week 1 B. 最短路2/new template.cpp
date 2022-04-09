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

long long dis[2001];
vector<pair< long long, long long> > edge[2001];
void addedge(long long x, long long y, long long z) {
	edge[x].push_back(make_pair(y, z));
}
vector<pair< long long, long long> > ::iterator it;

priority_queue < pair<long long, long long>, vector < pair < long long, long long >>, greater<pair<long long, long long>> > q;
const long long maxn = 922337203685477;

int main()
{
	long long n, m;
	cin >> n >> m;
	long long minn = 0;
	for (long long i = 1; i <= m; i++)
	{
		long long u, v, w;
		cin >> u >> v >> w;
		addedge(u, v, w);
	}
	dis[1] = 0;
	q.push(make_pair(dis[1], 1));
	for (long long i = 2; i <= n; i++)
	{
		dis[i] = maxn;
	}
	for (int i = 1; i <= n - 1; i++)
	{
		for (int x= 1; x <= n; x++)
		{
			for (it = edge[x].begin(); it != edge[x].end(); it++)
			{
				long long y = it->first, w = it->second;

				if (dis[y] > w + dis[x])
				{
					dis[y] = w + dis[x];
				}
			}
		}
	}
	for (long long i = 1; i <= n; i++)
	{

		cout << dis[i]<< " ";
	}

}






