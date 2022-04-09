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
unsigned long long v[40],vv[40],twon;//twon位二进制下的点全为1
unsigned long long ans = 2147483647;
map<unsigned long long, unsigned long long> m;
void dfs(int x, int end, unsigned long long state, unsigned long long cost)
{
	if (m[state] != 0)m[state] = min(cost, m[state]);
	else m[state] = cost;
	unsigned long long cc = (state ^ twon);
	if (m[state ^ twon] != 0 || state == twon) { ans = min(ans, m[state ^ twon] + cost); }
	if (x <= end)
	{
		dfs(x + 1, end, state, cost);
		unsigned long long tem = state ^ v[x];
		dfs(x + 1, end, tem, cost + 1);
	}
}
bool f[40];
int rnm[40][40];
int main()
{	
	


	int n, m;
	cin >> n >> m;
	for (long long i = 1; i <= m; i++)
	{
		long long a, b;

		cin >> a >> b;
		unsigned long long t1 = (1LL << b);
		unsigned long long t2 = (1LL << a);
		//if (rnm[a][b])continue;
		v[a] = v[a] | t1;
		//vv[a] = vv[a] | t1;
		//vv[b] = vv[b] |t2;
		v[b] = v[b] | t2;
		//cout << v[a] - vv[a] << '\n';
		//rnm[a][b] = 1;
	}


	for (unsigned long long i = 1; i <= n; i++)
	{
		v[i] = v[i] ^ (1LL << i);
		twon = twon ^ (1LL << i);

	}

	dfs(1, n / 2, 0, 0);
	dfs(n / 2 + 1, n, 0, 0);
	if (ans == 2147483647)cout << -1;
	else	cout << ans;
}