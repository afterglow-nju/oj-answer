#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

int f[1001][1001];
int main()
{   
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) 
    {
        for (int j =1; j <= n; j++)
        {
            cin >> f[i][j];
            if (f[i][j] == 0) f[i][j] = 1000;
        }
    }
    for (int i = 1; i <=n; i++) {
        for (int j = 1; j <= n; j++) {
            if (f[i][j]==1) {
                continue;
            }
            if (i - 1 >0) {
                f[i][j] = min(f[i][j], f[i - 1][j] + 1);
            }
            if (j - 1 >0) {
                f[i][j] = min(f[i][j], f[i][j - 1] + 1);
            }
        }
    }
    for (int i = n ; i > 0; i--) {
        for (int j = n; j >0; j--) {
            if (f[i][j]==1) {
                continue;
            }
            if (i + 1 <= n) {
                f[i][j] = min(f[i][j], f[i + 1][j] + 1);
            }
            if (j + 1 <= n) {
                f[i][j] = min(f[i][j], f[i][j + 1] + 1);
            }
        }
    }
    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ans = max(ans, f[i][j]);
        }
    }
    cout << ans-1;


 
   
}
