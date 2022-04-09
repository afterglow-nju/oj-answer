//dp 小练习
#include <iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 2100;
int n, dp[9][N];
int a[8] = { 0,8,18,28,58,128,198,388 };
int cost[8] = { 0,1,6,28,88,198,328,648 };

int main()
{
    cin >> n;
    for (int i = 1; i <= 7; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j >= cost[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + a[i]);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[7][n]+10*n;
}

