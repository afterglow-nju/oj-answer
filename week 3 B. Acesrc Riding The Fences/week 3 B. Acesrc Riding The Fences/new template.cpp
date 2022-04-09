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
const long long maxn = 2048;
bool used[maxn];
int degree[maxn];
int mul[maxn][maxn];
int record[maxn];
vector<pair< long long, long long> > edge[maxn];
void addedge(long long x, long long y, long long z) {
	edge[x].push_back(make_pair(y, z));
}

queue<long long> q;
void dfs(int n)
{
	vector<pair< long long, long long> > ::iterator it;
	for (it = edge[n].begin(); it != edge[n].end(); it++)
	{
		if (mul[n][it->first])
		{
			mul[n][it->first]--;
			mul[it->first][n]--;
			dfs(it->first);
		}
		
	}
	
	q.push(n);
}
bool com(pair<long long, long long>a, pair<long long, long long>b)
{
	return a.first > b.first;
}
int main()
{

	int F;
	cin >> F;
	int ans = 0;
	for (int i = 1; i <= F; i++)
	{
		int m, n;
		cin >> m >> n;

		
		degree[m]++;
		degree[n]++;
		mul[m][n]++;
		mul[n][m]++;
		addedge(n, m, 1);
		addedge(m, n, 1);
	}
	bool flag = true;
	int index = 1;
	for (int i = 1; i <= 500; i++)
	{
		sort(edge[i].begin(), edge[i].end());
		if (degree[i] % 2 != 0&&flag)
		{	
			flag = false;
			index = i;
			
		}
	}

	dfs(index);

	int i = 1;
	while (!q.empty())
	{
		record[i++] = q.front();
		q.pop();
	}
	i--;
	for (i; i >= 1; i--)
		cout << record[i] << '\n';
}





