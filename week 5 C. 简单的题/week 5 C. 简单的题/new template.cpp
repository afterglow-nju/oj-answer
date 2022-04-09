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
#include<cstring>
#include<limits>
using namespace std;
const long long maxn =0x3f3f3f3f;
int tot;
int dis[1001][1001],ans[1001][1001],m[1001][1001];



void qm(int n)
{
	n--;
	while (n)
	{
		if (n & 1)
		{
			memset(m, maxn, sizeof(m));
			for (int k = 1; k <= tot; k++)
				for (int i = 1; i <= tot; i++)
					for (int j = 1; j <= tot; j++)
						m[i][j] = min(m[i][j], ans[i][k] + dis[k][j]);
			for (int i = 1; i <= tot; i++)
			{
				for (int j = 1; j <= tot; j++)
				{
					ans[i][j] = m[i][j];
				}
			}
		}
		memset(m, maxn, sizeof(m));
		for (int k = 1; k <= tot; k++)
		{
			for (int i = 1; i <= tot; i++)
			{
				for (int j = 1; j <= tot; j++)
					m[i][j] = min(m[i][j],dis[i][k] + dis[k][j]);
			}
		}
		for (int i = 1; i <= tot; i++)
		{
			for (int j = 1; j <= tot; j++)
			{
				dis[i][j] = m[i][j];
			}
		}
		n >>= 1;
	}

}
int num[1005];
int main()
{
	int n, t, s, e;
	cin >> n >> t >> s >> e;
	memset(dis, maxn, sizeof(dis));
	memset(ans, maxn, sizeof(ans));

	for (int i = 1; i <= t; i++)
	{
		int w, x, y;
		cin >> w >> x >> y;
		if (!num[x])
		{
			num[x] = ++tot;
		}
		if (!num[y])
		{
			num[y] = ++tot;
		}
		dis[num[x]][num[y]] = w;//min(w,dis[num[x]][num[y]]);
		dis[num[y]][num[x]] = dis[num[x]][num[y]];
		ans[num[y]][num[x]]= dis[num[x]][num[y]];
		ans[num[x]][num[y]]= dis[num[x]][num[y]];
		//cout << dis[num[x]][num[y]] << '\n';
	}
	qm(n);
	cout << ans[num[s]][num[e]];
}






