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
long long  n, k;
long long  b[50001];
long long  S[51][51];
const long long  N = 500001;
vector<pair<long long , long long > > edge[N];
void addedge(long long  x, long long  y, long long  z) {
	edge[x].push_back(make_pair(y, z));
}
vector<long long> ans;
long long dis[N];
long long  pre[N];
vector<pair< long long, long long> > ::iterator it;

priority_queue < pair<long long, long long>, vector < pair < long long, long long >>, greater<pair<long long, long long>> > q;
const long long maxn = 922337203685477;
map<long long ,vector<long long >>record;
long long  nxt[N];
long long  cnt = 0;


long long  aans = 9999999;


void dfs(int cnt,int ans,int start)
{
	if (cnt == -1)
	{
		aans = min(ans, ans);
		return;
	}
	for (long long j = 0; j < record[nxt[cnt]].size(); j++)
	{
		dfs(cnt-1, ans + abs(start-record[nxt[cnt]][j]),j);
	}		
	
	
}
int  main()
{
	cin >> n >> k;
	for (long long i = 1; i <= n; i++)
	{
		cin >> b[i];
		record[b[i]].push_back(i);
	
	}

	for (long long i = 1; i <= k; i++)
	{
		long long  tem = 0;
		cin >> tem;
		long long  a = 1;
		for (long long  j = k; j>=1; j--)
		{
			S[i][j] = tem %10;
			tem /= 10;
			if (S[i][j] == 1)addedge(i, j, 1);
		//	cout << S[i][j] << " ";
		}
		
	}
	dis[b[1]] = 0;
	q.push(make_pair(dis[b[1]], 1));
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
				pre[y] = x;
				dis[y] = w + dis[x];
				q.push(make_pair(dis[y], y));
			}
		}
	}
	if (dis[b[n]] >= 51)
	{
		cout << -1; exit(0);
	}

	for (long long  i = pre[b[n]]; i!=b[1];)
	{
	//	cout << i << " ";
		nxt[cnt++] = i;
		i = pre[i];
	}
	cnt--;
	/*
	long long  ans = 0;
	long long  left = 1;

	//cout << '\n';
	for (long long  i = cnt; i >= 0; i--)
	{
		long long  tem = INT_MAX;
		long long  ttem=0;
		for (long long  j = 0; j < record[nxt[i]].size(); j++)
		{
		//	cout << record[nxt[i]][j] << " ";
			if (abs(left - record[nxt[i]][j]) < tem)
			{
				ttem = j;
			}
			tem = min(tem, abs(left - record[nxt[i]][j]));
		}
		//cout << '\n';
		
		ans += tem;
		left = ttem;

	}*/
	dfs(cnt, 0, 1);
	cout << aans;
	
	
	
}