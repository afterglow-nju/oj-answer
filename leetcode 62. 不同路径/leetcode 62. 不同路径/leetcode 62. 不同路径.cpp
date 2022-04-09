#include <iostream>
using namespace std;
long long dp[101][101];
int main()
{
	int a, b;
	cin >> a >> b;
	for (int i = 1; i <= a; i++)dp[i][1] = 1;
	for (int i = 1; i <= b; i++)dp[1][i] = 1;
	for (int i = 2; i <= a; i++)
	{
		for (int j = 2; j <= b; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	cout << dp[a][b];
}

