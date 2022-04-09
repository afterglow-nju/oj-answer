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
int n;
const int N = 100010;
vector<pair<int, int> > edge[N];
void addedge(int x, int y, int z) {
	edge[x].push_back(make_pair(y, z));
}
typedef long long ll;
ll maxdis = 0;
ll d[N];
void dis(int s,int fa)
{
	for (auto it = edge[s].begin(); it != edge[s].end(); it++)
	{
		int y = it->first, w = it->second;
		if (y != fa)
		{
			d[y] = max(d[y],d[s] + w);
			dis(y, s);
		}
		else continue;
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n-1; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		addedge(u, v, w);
		addedge(v, u, w);
	}
	dis(1, 0);
	int node = 0;
	for (int i = 2; i <= n; i++)
	{
		if (d[i] > d[node])node = i;
	}
	memset(d, 0, sizeof(d));
	dis(node, 0);
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, d[i]);
	}
	cout << ans;
}