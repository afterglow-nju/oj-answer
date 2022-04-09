#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
using namespace std;

int main() {
    int N, x;
    cin >> N;
    vector<vector<int>> a(N, vector<int>(N, 0));
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> x;
            a[i][j] = x;
            if (x == 0) {
                dp[i][j] = 300; //宿舍楼
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << dp[i][j]<<" ";

        }
        cout << '\n';
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (a[i][j] == 1) {
                continue;
            }
            if (i > 0) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            }
            if (j > 0) {
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
        }
    }
    for (int i = N - 1; i >= 0; i--) {
        for (int j = N - 1; j >= 0; j--) {
            if (a[i][j] == 1) {
                continue;
            }
            if (i < N - 1) {
                dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
            }
            if (j < N - 1) {
                dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
            }
        }
    }


    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << dp[i][j] << " ";

        }
        cout << '\n';
    }



    int ans = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (a[i][j] == 0) {
                ans = max(ans, dp[i][j]);
            }

        }
    }
    //cout << ans << endl;
}