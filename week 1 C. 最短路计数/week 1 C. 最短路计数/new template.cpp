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
long long dis[1000001],ans[1000001];
vector<pair< long long, long long> > edge[1000001];
void addedge(long long x, long long y, long long z) {
	edge[x].push_back(make_pair(y, z));
}
vector<pair< long long, long long> > ::iterator it;
priority_queue < pair<long long, long long>, vector < pair < long long, long long >>, greater<pair<long long, long long>> > q;
const long long maxn = 922337203685477, mod= 100003;
int main()
{
	long long n, m, c;
	cin >> n >> m;
	c = n;
	for (long long i = 1; i <= m; i++)
	{
		long long u, v, w;
		cin >> u >> v >> w;
		addedge(u, v, w);
		addedge(v, u, w);
	}
	dis[1] = 0;
	ans[1] = 1;
	q.push(make_pair(dis[1], 1));
	for (long long i = 2; i <= n; i++)
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
				ans[y] = ans[x];
				q.push(make_pair(dis[y], y));
			}
			else if (dis[y] == w + dis[x])
			{
				ans[y] =(ans[y]+ ans[x])%mod;
			}
		}
	}
	for (long long i = 1; i <= n; i++)
	{
		if (dis[i] == maxn)cout <<0 ;
		else
			cout << ans[i];
		cout << '\n';
	}

}






