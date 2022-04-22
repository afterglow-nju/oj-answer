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
int h[1001];
typedef long long ll;
ll d[1001];
ll pre[1001];
const ll mod = 1e9 + 7;
int main()
{
	ll ans = 0;
	int n, k = INT_MAX;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> h[i];
		k = min(k, h[i]);
	}
	do
	{
		for (int i = 0; i <= h[1]; i++)pre[i] = i + 1;
		for (int i = h[1] + 1; i <= 1000; i++)pre[i] = h[1] + 1;
		for (int i = 2; i <= n; i++)
		{
			memset(d, 0, sizeof(d));
			for (int j = 0; j <= h[i]; j++)d[j] = pre[h[i] - j];
			pre[0] = d[0];
			for (int j = 1; j <= 1000; j++)pre[j] = (pre[j - 1] + d[j]) % mod;
		}
		ans = (ans + pre[0]) % mod;
		for (int i = 1; i <= n; i++)h[i]--;
	}while ((n & 1) && k--);
	cout << ans;
}