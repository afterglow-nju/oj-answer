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
//你想啊，我们要记录的量，一个商品，是哪一个牌子，是这个牌子多少个商品，价值价格
struct node
{
	int price;
	int value;
}a[11][101];
int num[11], d[11][10001];
int main()
{
	int n, m, k;
	while (cin >> n >> m >> k)
	{
		int t;
		memset(num, 0, sizeof(num));

		for (int i = 1; i <= n; i++)
		{
			cin >> t;
			num[t]++;
			cin >> a[t][num[t]].price >> a[t][num[t]].value;
		}

		for (int i = 1; i <= k; i++)
		{
			for (int j = 0; j <= m; j++)
			{
				d[i][j] = -INT_MAX;
			}
		}

		//memset(d, -1, sizeof(d));
		memset(d[0], 0, sizeof(d[0]));

		for (int i = 1; i <= k; i++)
		{
			for (int k = 1; k <= num[i]; k++)
			{
				for (int j = m; j >= a[i][k].price; j--)
				{

					d[i][j] = max(d[i][j], d[i][j - a[i][k].price] + a[i][k].value);
					d[i][j] = max(d[i][j], d[i - 1][j - a[i][k].price] + a[i][k].value);

					/*
					if (d[i][j - a[i][k].price] != -1)
					{
						d[i][j] = max(d[i][j], d[i][j - a[i][k].price] + a[i][k].value);
					}
					if (d[i - 1][j - a[i][k].price] != -1)
					{
						d[i][j] = max(d[i][j], d[i - 1][j - a[i][k].price] + a[i][k].value);
					}
					*/
					//判断的顺序很重要
				}

			}
		}
		if (d[k][m] < 0)cout << "Impossible" << '\n';
		else
		{
			cout << d[k][m] << '\n';
		}
	}
}
