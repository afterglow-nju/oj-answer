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
const int maxn = 10000;
int fa[maxn], val[maxn];
int find(int x)
{
	if (x == fa[x])return x;
	int fx = find(fa[x]);
	val[x] += val[fa[x]];
	return fa[x] = fx;
}
void Union(int x, int y)
{
	x = find(x);
	y = find(y);
	fa[y] =x;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		bool f = false;
		for (int i = 0; i <= n; i++)
		{
			fa[i] = i;
			val[i] = 0;
		}
		for (int i = 1; i <= m; i++)
		{
			int s, t, v;
			cin >> s >> t >> v;
			s--;
			int t1 = find(s);
			int t2 = find(t);
			if (t1 == t2)
			{
				if (v != val[t] - val[s])
				{
					f = 1;
				}
			}
			else
			{
				fa[t2] = t1;
				val[t2] = val[s] - val[t] + v;
			}

		}
		if (f)
		{
			cout << "false" << '\n';
		}
		else
		{
			cout << "true" << '\n';
		}
	}
}