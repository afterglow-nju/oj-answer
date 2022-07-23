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
typedef long long ll;
const int maxn = 500001;
int a[maxn];
int pre[maxn], nxt[maxn];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = i - 1; j >= 1; j--)
		{
			if (a[j] < a[i])pre[i]++;
		}
		for (int j = i + 1; j <= n; j++)
		{
			if (a[i] > a[j])nxt[i]++;
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += pre[i] * nxt[i];
	}
	cout << ans;
}