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
const long long maxn = 100001;
int n, m;
int v[maxn], num[maxn],d[maxn],val[maxn];
void divide()
{
	for (int i = 1; i <= m; i++)
	{
		d[i] = -INT_MAX;
	}
	int tot = 0;
	d[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int k = 0; (1 << k) <= num[i]; k++)
		{
			num[i] -= (1 << k);
			val[++tot] = v[i] * (1 << k);
		}
		val[++tot] = num[i] * v[i];
	}
	for (int i = 1; i <= tot; i++)
	{
		//cout << val[i] << '\n';
		for (int j = m; j >= val[i]; j--)
		{
			d[j] = max(d[j], d[j - val[i]] + val[i]);
		}
	}

	int ans = 0;
	for (int i = 1; i <= m; i++)
	{
		if (d[i] >= 0)
		{
			ans++;
			//cout << i << '\n';
		}
	}
		cout << ans << '\n';
}
int main()
{	

	while (1)
	{
		cin >> n >> m;
		if (n ==0&& m == 0) break;
		for (int i = 1; i <= n; i++)
		{
			cin >> v[i];
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> num[i];
		}
		divide();
	}
}






