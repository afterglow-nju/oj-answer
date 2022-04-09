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
const int N = 1000;
struct node
{
	int color;
	int first;
}V[N];
struct Edge
{
	int num;
	bool deleted;
	int u, v, w, next;
}E[N];
int n, m, index;
void add(int u, int v, int w)
{
	E[++index].u = u;
	E[index].v = v;
	E[index].w = w;
	E[index].deleted = 0;
	E[index].num = index;
	E[index].next = V[u].first;
	V[u].first = index;
}
enum{none,blue,red};
bool dfs(int num, int color)
{
	//cout << num << '\n';
	V[num].color = color;
	for (int i = V[num].first; i ; i = E[i].next)
	{
		if (V[E[i].v].color == none)
		{
			if (dfs(E[i].v, 3 - color) == false)
			{
				cout << "AAAA\n";
				E[i].deleted = 1;
				int t;
				if (i % 2 == 1)
				{
					t = i + 1;
				}
				else t = i - 1;
				E[t].deleted = 1;
				return false;
			}
		}
		else if (V[E[i].v].color != 3 - color)
		{
			cout << "BB\n";
			E[i].deleted = 1;
			int t;
			if (i % 2 == 1)t = i + 1;
			else t = i - 1;
			E[t].deleted = 1;
			return false;
		}
	}return true;
	
}
vector<pair<int, int> > edge[N];
void addedge(int x, int y, int z) {
	edge[x].push_back(make_pair(y, z));
}
typedef long long ll;
int main()
{

	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
		add(b, a, c);
	}
	for (int i = 1; i <= n; i++)
	{
		if (V[i].color == none)
		{
			dfs(i, red);
		}
	}
	int k = 0;
	cout << index<<'\n';
	for(int i=1;i<=index;i++)
cout << E[i].deleted << " " << E[i].w << '\n';
	for (int i = 1; i <= index; i++)
	{
	//	if (E[i].deleted==1)k += E[i].w;
		for (int j = i + 2; j <= index; j++)
		{

		}
	//
	}
	//cout << k;
}