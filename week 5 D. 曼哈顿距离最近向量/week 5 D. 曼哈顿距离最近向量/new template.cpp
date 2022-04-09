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
ll dp[2][30002];
ll b[20001], a[10001];
int main()
{
	int n, m;
	cin >> m >> n;

	for (int i = 1; i <= m; i++)
	{
		cin >> b[i];
		dp[1][i] = INT_MAX;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(b + 1, b + m + 1);
	sort(a + 1, a + n + 1);
	/*dp[i][j]代表在考虑第i个点
	dp[0][j]代表在b[j]之间，a[i]还是没有配对
	dp[1][j]代表已经配对
	每次遍历完后将dp[0][j]=dp[1][p]更新一下配对好前i个点后的总距离
	*/
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			//if(i<j)
			dp[1][j + 1] = min(dp[0][j] + abs(b[j] - a[i]), dp[1][j]);
			//else
			{
				//dp[1][j + 1] = min(dp[0][j] + abs(b[j] - a[i]),dp[1][j]);
				//dp[1][j + 1] = dp[0][j] + abs(b[j] - a[i]);
				//cout << "i=" << i << " j=" << j << '\n';
				//cout << dp[0][j] + abs(b[j] - a[i]) << " "<<dp[1][j]<<'\n';
			}
		}
		for (int j = 1; j <= m + 1; j++)
		{
			dp[0][j] = dp[1][j];
			dp[1][j] = INT_MAX;
		}
	}
	ll ans = INT_MAX;
	for (int i = n; i <= m + 1; i++)
	{
		ans = min(ans, dp[0][i]);
	}
	cout << ans;
}
