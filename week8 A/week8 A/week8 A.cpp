#include <iostream>
#include<vector>
using namespace std;
const int M = 1e5 + 10;
vector<int> edge[M];
int c[M];
bool flag = true;
void dfs(int x)
{	
	if (flag == false) return;
	for (int i = 0; i <edge[x].size(); i++)//从0开始因为vector从0开始
	{
		if (c[edge[x][i]]==0)
		{
			c[edge[x][i]] = -c[x];
			dfs(edge[x][i]);
		}
		else
		{
			if (c[edge[x][i]] == c[x] && x!=edge[x][i])
			{
				flag = false;
				return;
			}
		}
	}
}

int main()
{

	int n, m, sum;
	cin >> sum;
	while (sum > 0)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++) edge[i].clear(), c[i] = 0;
		for (int i = 1; i <= m; i++)
		{
			int x, y;
			cin >> x >> y;
			edge[x].push_back(y);
			edge[y].push_back(x);//从1开始，不然不对
		}
		for (int i = 1; i <= n; i++)
		{
			if (c[i] == 0)
			{
				c[i] = 1;
				dfs(i);
			}
		}
		if (flag)
		{
			cout << "yes" << '\n';
			for (int i = 1; i <= n; i++)
			{
				if (c[i] > 0) cout << "red" << '\n';
				else cout << "blue" << '\n';
			}
		}
		else { cout << "no"<<'\n'; }
	flag = true;
	sum--;
	//for (int i = 1; i <=M-1; i++) edge[i].clear(), c[i] = 0;
	}
}
/*
//#include<bits/stdc++.h>
#define M 100005
using namespace std;
int n, m, flag;
vector<int>e[M];
int color[M];
void dfs(int x)
{
	for (int i = 0; i < e[x].size(); ++i)
		if (!color[e[x][i]])
		{
			color[e[x][i]] = -color[x];
			dfs(e[x][i]);
		}
		else if (color[e[x][i]] == color[x]) flag = 1;
}
int main()
{
	int T;
	for (scanf_s("%d", &T); T; --T)
	{
		flag = 0;
		scanf_s("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) e[i].clear(), color[i] = 0;
		for (int x, y, i = 1; i <= m; ++i)
		{
			scanf_s("%d%d", &x, &y);
			e[x].push_back(y);
			e[y].push_back(x);
		}
		for (int i = 1; i <= n; ++i)
			if (!color[i])
				color[i] = 1,
				dfs(i);
		if (flag) puts("no");
		else
		{
			puts("yes");
			for (int i = 1; i <= n; ++i) puts(color[i] > 0 ? "red" : "blue");
		}
	}
}
dfs框架结构
1. 退出条件，递归多少层dfs(depth) n代表递归了多少层 递归到n推出
	if depth>n....
	递归or dfs就是一棵树，不断往下搜 check的目的就是在往下搜的过程中直接判断，不用判断到底部，该节点往下都不再考虑了
	以上为n皇后
2. 数独
难度在于怎么剪枝
用全局变量维护时，每一次回溯时，恢复到原来状态

bfs
1. 求最短路径
	
	dist
	层的概念
	队列，前半段第i层的点，后半段第i+1层的点
queue<int> q; (queue<pair> q)
q.empty()
while(!q.empty())
x=q.front()获取队头 
q.pop()弹掉队头
q.push

多起点bfs
vector
a[x].pushback(y)
a[y].pushback(x)

排序
bool cmp(node s1,node s2)
{
	return s1.x<s2.x(你希望s1排在前面)

}
bool cmp(int x,int y)
return x%1000<y%1000 按后三位排序;

多关键字
多写几个if

















*/




