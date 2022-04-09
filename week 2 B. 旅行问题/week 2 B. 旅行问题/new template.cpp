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
int dis[20][20],d[20][1<<20];
#define inf 0x3fffffff;
int main()
{	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> dis[i][j];
		}
	}
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j =0; j < n; j++)
			{
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <(1<< n); j++)//0->1
		{
			d[i][j] = inf;
		}
	}
	for (int i = 0; i < n; i++)d[i][1 << i] = 0;
	for (int k = 1; k < (1 << n); k++)
	{
		for (int i = 0; i < n; i++)
		{
			if (k>>i&1)
			{
				for (int j = 0; j < n; j++)
				{
					d[j][k |(1 << j)] = min(d[j][k |(1 << j)], d[i][k] + dis[i][j]);
				}
			}
		}
	}
	int ans = inf;
	for (int i = 0; i < n; i++)
	{
		ans = min(ans, d[i][(1 << n)-1]);
	}
	cout << ans;
}







