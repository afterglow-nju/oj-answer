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

long long dis[100001];
vector<pair< long long,  long long> > edge[100001];
void addedge( long long x,  long long y,  long long z) {
	edge[x].push_back(make_pair(y, z));
}
vector<pair< long long,  long long> > ::iterator it;

priority_queue < pair<long long, long long>, vector < pair < long long , long long >> , greater<pair<long long, long long>> > q;
const long long maxn = 922337203685477;

 int main()
{	
	 long long n, m,c;
	cin >> n >> m;
	c = n;
	for ( long long i = 1; i <= m; i++)
	{	
		 long long u, v, w;
		cin >> u >> v>>w;
		addedge(u, v, w);
	}
	dis[1] = 0;
	q.push(make_pair(dis[1],1));
	for ( long long i = 2; i <= n; i++)
	{
		dis[i] =maxn;
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
	for ( long long i = 1; i <= n; i++)
	{	
		if (dis[i]== maxn)cout << -1 << " ";
		else
			cout <<dis[i] << " ";
	}
	
}






