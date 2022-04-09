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
int c[5],f[5][10001],cost[5],num[5];
int main()
{
	int p;
	cin >> p >> c[1] >> c[2] >> c[3] >> c[4];
	cost[1] = 1, cost[2] = 5, cost[3] = 10,cost[4] = 25;
	for (int i = 1; i <= 4; i++)
	{
		
		for (int j = 0; j <= p; j++)
		{
			f[i][j] = f[i - 1][j];
			for (int k = 0; k <= c[i]; k++)
			{
				
				if (j >= k*cost[i])
				{
					f[i][j] = max(f[i][j], f[i - 1][j - k * cost[i]] + k);
				}
			}
		}
		num[i] = f[i][p] - num[i - 1];
		cout << f[i][p] << " ";
	}
//	cout << num[1]<<" "<<num[2]<<" "<<num[3]<<" "<<num[4];
}






