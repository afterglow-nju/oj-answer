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
struct node
{
	int v, w;//v就是点，w是权重
	node() {}
	node(int a, int b) { v = a; w = b; }
};
const int maxn = 100001;
vector<node>tree[maxn], ask[maxn];
int father[maxn],dis[maxn],vis[maxn],ans[maxn];
void init()
{
	for (int i = 0; i < maxn; i++)
	{
		dis[i] = 0;
		father[i] = i;
		vis[i] = 0;
		tree[i].clear();
		ask[i].clear();
	}
}
int find(int x)
{
	if (x == father[x])return x;
	int t = find(father[x]);
	father[x] = t;
	return t;
}
void LCA(int u, int w, int root)//i 0 i
{
	dis[u] = w;
	father[u] = u;
	vis[u] = root;
	int size = tree[u].size();//以u为根的子树大小？
	for (int i = 0; i < size; i++)
	{
		if (!vis[tree[u][i].v])
		{
			LCA(tree[u][i].v, tree[u][i].w + w, root);
			father[tree[u][i].v] = u;
		}
	}
	size=ask[u].size();
	for (int i = 0; i < size; i++)
	{
		if (vis[ask[u][i].v])
		{
			if (vis[ask[u][i].v] == root)//很重要，找到根了 只要看某种意义上的局部就可
			{
				ans[ask[u][i].w] = dis[u] + dis[ask[u][i].v] - 2 * dis[find(ask[u][i].v)];
				cout << ask[u][i].w << " =" << find(ask[u][i].v)<<'\n';
			}
			//else ans[ask[u][i].w] = -1;
		}
	}
}
int main()
{
	int n, m,s;
	cin >> n >> m>>s;
	for (int i = 1; i < n; i++)
	{
		int x, y, v=1;
		cin >> x >> y ;
		node tem1(x, v);
		node tem2(y, v);
		tree[x].push_back(tem2);//y=tree[x] x-y有边相连
		tree[y].push_back(tem1);
	}
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		node tem1(x, i);
		node tem2(y, i);
		ask[x].push_back(tem2);
		ask[y].push_back(tem1);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i]) LCA(s, 0, s);
	}
	for (int i = 1; i <= m; i++)cout << ans[i] <<'\n';
}






