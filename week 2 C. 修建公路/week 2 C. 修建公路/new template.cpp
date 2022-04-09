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
#define inf 0x3fffffff
using namespace std;
const int maxn = 401;
bitset<maxn> d[maxn];
int ans=0,c[maxn];
int main()
{	
/*	d[1]= 3;
	cout << d[1][1]<<'\n';
	cout << d[1].count();*/
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		d[i][i] = 1;
		c[i] = 1;
	}
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		d[u][v] = 1;
		d[u] = d[u] | d[v];
		for (int j = 1; j <= n; j++)
		{
			if (d[j][u])
			{
				d[j] |= d[v];
				c[j] = d[j].count();
			}
			ans += c[j];
		}
/*		for (int j = 1; j <= n; j++)
		{	
			ans += d[j].count();
		}*///d[j].count()Ì«·ÑÊ±¼ä£¿£¿ O(n)
		cout << ans-n << " ";
		ans = 0;

	}











}






