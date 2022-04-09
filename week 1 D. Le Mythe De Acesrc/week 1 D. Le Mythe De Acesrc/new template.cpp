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
typedef long long  ll;
int a[20001];
int dis[20001],b[20001];
int vis[20001];
vector<pair< ll, ll> > edge[20001];
void addedge(ll x, ll y, ll z) {
	edge[x].push_back(make_pair(y, z));
}
vector<pair< ll, ll> > ::iterator it;

priority_queue < pair<ll, ll>, vector < pair < ll, ll >>, greater<pair<ll, ll>> > q;
const ll maxn = 922337203685477;
int main()
{

	int n, query;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	fill(dis + 1, dis + 1 + a[1], maxn);
	/*
	for (int i = 2; i <= n; i++)
	{
		dis[a[i] % a[1]] = min(dis[a[i] % a[1]], a[i]);
	}
	*/
	dis[0] = 0;
	q.push(make_pair(dis[0], 0));
	while (!q.empty())
	{
		pair<long long, long long> t = q.top();
		q.pop();
		int u = t.second;
		if (vis[u]) continue;
		vis[u] = 1;
		for (int j = 2; j <= n; j++)
		{
			int r = (u + a[j]) % a[1];
			if (!vis[r] && dis[u] + a[j] < dis[r])
			{
				dis[r] = dis[u] + a[j];
				q.push(make_pair(dis[r], r));
			}
		}
	}
	cin >> query;
	while (query--)
	{
		ll x;
		cin >> x;
		if (x >= dis[x % a[1]])
			cout << "Acesrc!" << '\n';
		else
			cout << "Acesrc?" << '\n';

	}
}


