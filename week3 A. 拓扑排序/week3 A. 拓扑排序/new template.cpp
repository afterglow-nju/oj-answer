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
typedef long long ll;
using namespace std;
const long long maxn = 100001;
int in_degree[maxn];
vector<pair< long long, long long> > edge[maxn];
void addedge(long long x, long long y, long long z) {
	edge[x].push_back(make_pair(y, z));
}
vector<pair< long long, long long> > ::iterator it;

priority_queue<ll, vector<ll>, greater<ll>>q ;
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		addedge(x, y, 1);
		in_degree[y]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!in_degree[i])
		{
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int x = q.top();
		q.pop();
		cout << x << " ";
		for (it = edge[x].begin(); it != edge[x].end(); it++)
		{
			in_degree[it->first]--;
			if (!in_degree[it->first])
			{
				q.push(it->first);
			}
		}
	}
}






