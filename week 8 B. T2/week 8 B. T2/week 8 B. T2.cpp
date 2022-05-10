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
#include<assert.h>
using namespace std;
const int maxn = 200;
int n;
int dis[maxn][maxn];
string s[maxn];
int f[maxn][maxn];
void dp(int i, int j)
{
	memset(f, 0, sizeof(f));
	string a = s[i];
	string b = s[j];
	int la = a.length();
	int lb = b.length();
	for (int i = 0; i <= la; i++)
	{
		for (int j = 0; j <= lb; j++)
		{
			if (min(i, j) == 0)
				f[i][j] = max(i, j);
			else
			{
				f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
				
				if (a[i-1] != b[j-1])f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
				else f[i][j] = min(f[i][j], f[i - 1][j - 1]);

			}
		}
	}
	dis[i][j] = f[la][lb];
	dis[j][i] = f[la][lb];

}

int path[maxn] = { 0 };
void prim(int x)
{
	int mindis[maxn] = { 0 }, Min = 0;
	for (int i = 1; i <= n; i++)
	{
		mindis[i] = dis[i][x];
		path[i] = x;
	}
	int k = 0;
	for (int i = 1; i < n; i++)
	{
		Min = INT_MAX;
		for (int j = 1; j <= n; j++)
		{
			if (mindis[j] != 0 && mindis[j] < Min)
			{
				Min = mindis[j];
				k = j;
			}
		}
		mindis[k] = 0;
		for (int j = 1; j <= n; j++)
		{
			if (mindis[j] > dis[j][k])
			{
				mindis[j] = dis[j][k];
				path[j] = k;
			}
		}
	}
}
int tot = 0, Last[maxn] = { 0 }, End[maxn * 2] = { 0 }, Next[maxn * 2] = { 0 };
void Add(int x, int y)
{
	tot++;
	End[tot] = y;
	Next[tot] = Last[x];
	Last[x] = tot;
}
int Order[maxn] = { 0 }, num = 0;
bool visited[maxn] = { 0 };
void DFS(int x)
{
	num++;
	visited[x] = true;
	Order[num] = x;
	int t = Last[x], y = 0;
	while (t)
	{
		y = End[t];
		if (!visited[y])DFS(y);
		t = Next[t];
	}
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		tot = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)cin >> s[i];
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				dp(i, j);
			}
		}
		prim(1);
		memset(visited, 0, sizeof(visited));
		memset(Last, 0, sizeof(Last));
		memset(End, 0, sizeof(End));
		memset(Next, 0, sizeof(Next));
		for (int i = 1; i <= n; i++)
		{
			if (path[i] != i)
			{
				Add(i, path[i]);
				Add(path[i], i);
			}
		}
		num = 0;
		DFS(1);
		int ans = 0;
		for (int i = 2; i <= n; i++)
		{
			ans += dis[Order[i - 1]][Order[i]];
		}
		//cout << ans << '\n';
		ans += dis[Order[n]][1];
		cout << ans << '\n';
	}
}

/*for (int i = 1; i <= n; i++)fa[i] = i;
		tot = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				e[++tot].d = dis[i][j];
				e[tot].u = i;
				e[tot].v = j;
			}
		}
		sort(e + 1, e + 1 + tot, cmp);
		int ans = 0;
		for (int i = 1; i <= tot; i++)
		{
			int x = find(e[i].u);
			int y = find(e[i].v);
			if (x != y)
			{
				fa[y] = x;
				ans += 2 * e[i].d;
			}
		}
		cout << ans;*/