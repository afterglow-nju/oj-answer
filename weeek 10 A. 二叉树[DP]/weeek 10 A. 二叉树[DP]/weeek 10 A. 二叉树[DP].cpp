#include <iostream>
#include<algorithm>
using namespace std;

long long a[51], sum[51][51],f[51][51][51],s[51];
int main()
{
    //cout << f[1][2][0] << '\n';
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    s[0] = 0;
  //  cout << f[1][2][0] << '\n';
   // memset(f, 1, sizeof(f));
    for (int i = 0; i <= 50; i++)
    {
        for (int j = 0; j <= 50; j++)
        {
            for (int k = 0; k <= 50; k++)
            {
                f[i][j][k] = INT_MAX;
            }
         //   cout << sum[i][j] << " ";
        }
    }
   // cout << f[1][2][0]<<'\n';
    /*
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                sum[i][j] += a[k];
            }
            cout << sum[i][j]<<" ";
        }
    }
    */
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            f[i][i][j] = 0;
        }
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i+len<= n+1; i++)
        {
            int end = i + len - 1;
            for (int k = 1; k <= m; k++)
            {
               // cout << f[i][end][k-1] << " "<<i<<" "<<end<<" "<<k-1<<'\n';
                f[i][end][k] = f[i][end][k - 1];
              //  cout << f[i][end][k] << " ";
                for (int j = i; j <= end - 1; j++)
                {
                    f[i][end][k] = min(f[i][end][k], f[i][j][k - 1] + f[j + 1][end][k - 1] + s[end]-s[i-1]);
                  //  cout << f[i][end][k]<<" ";
                }
            }
        }
    }
    cout << f[1][n][m];
}

