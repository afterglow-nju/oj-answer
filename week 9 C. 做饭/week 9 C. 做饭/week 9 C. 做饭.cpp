#include <iostream>
using namespace std;
typedef long long ll;
ll d[101][2001], linesum[101],a[101][2001],nd[201][2001];//nd means negative d[101][2001]
ll mod = 998244353;
ll N = 100;
int main()
{
    ll n, m;
    cin >> n >> m;
    ll ans = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            linesum[i] = (linesum[i] + a[i][j]) % mod;
        }
        ans = ans * (1+linesum[i] )% mod;
    }

    //i方式 j食材
        
  /*  nd[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {   
        for (int j =0; j <= i; j++)
        {   
            nd[i][j] = nd[i - 1][j];
            for (int k = 1; k <= m; k++)
            {
               nd[i][j] = nd[i][j] * a[i][k] % mod;
            }
        }
    }
    
    for (int j = 1; j <= n; j++)
    {
        ans = (ans + nd[n][j]) % mod;
    }
    cout << ans;
    */
   // cout << ans;
    for (int t = 1; t <= m; t++)
    {   
       // memset(d, 0, sizeof(d));
        d[0][N] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = -i + N; j <= i + N; j++)
            {
                d[i][j] = (d[i - 1][j] + d[i - 1][j - 1] * a[i][t] % mod + d[i - 1][j+1] * (linesum[i] - a[i][t]) % mod) % mod;

            }
        }
        for (int i = 1; i <= n; i++)
        {
            ans = (ans - d[n][i+N]) % mod;
        }

    }

    
    cout << (ans-1+mod)%mod;
}

