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
const int maxn = 100000;
int a[7];
int cost[maxn], val[maxn],dp[maxn];
int divide(int sum)
{
	int i, j, k, tot = 0;
	for (i = 1; i <= 6; i++)
	{
		if (a[i] == 0)continue;
		for (k = 0; (1 << k) <= a[i]; k++)
		{
			a[i] -= (1 << k);
			val[++tot] = (1 << k) * i;
		}
		val[++tot] = a[i] * i;
	}
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= tot; i++)
	{
		for (int j = sum; j >= val[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - val[i]] + val[i]);
		}
	}
	if (dp[sum] == sum) return 1;
	else return 0;
}
int main()
{	
	int c = 0;
	while (1)
	{
		c++;
		int sum = 0;
		for (int i = 1; i <= 6; i++)
		{
			cin >> a[i];
			sum += a[i] * i;
		}
		if (sum == 0)break;
		cout << "Collection #" << c << ":" << '\n';
		if (sum & 1)
		{
			cout << "Can't be divided." << '\n'<<'\n';
			continue;
		}
		if (divide(sum / 2)) cout << "Can be divided." << '\n' << '\n';
		else cout << "Can't be divided." << '\n'<<'\n';
	}
}






