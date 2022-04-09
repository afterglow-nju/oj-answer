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
const long long maxn = 200001;
long long dis[maxn];
int out_degree[maxn];
vector<pair< long long, long long> > edge[maxn];
void addedge(long long x, long long y, long long z) {
	edge[x].push_back(make_pair(y, z));
}
vector<pair< long long, long long> > ::iterator it;
queue<long long>q;
//const long long maxn = 922337203685477;
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{	
		int x, y, z;
		cin >> x >> y >> z;
		addedge(x, y, z);
		out_degree[y]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!out_degree[i])
			q.push(i);
	}
	long long ans = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (it = edge[x].begin(); it != edge[x].end(); it++)
		{
			out_degree[it->first]--;
			dis[it->first] = max(dis[it->first], dis[x] + it->second);
			ans = max(ans, dis[it->first]);
			if (out_degree[it->first] == 0) q.push(it->first);
		}
	}
	cout << ans;
}






