#include <iostream>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;
ll qf(ll b, ll n)
{
    if (n == 0) return 1;
    if (n == 1) return b;
    ll n1 = n;
    n1 >>= 1;
    ll t = qf(b, n1) % mod;
    if (n & 1) return t * t % mod * b % mod;
    else return t * t % mod;
}
ll inv(ll b, ll n)
{
    return qf(b, n - 2);
}
ll fac(ll n)
{
    ll ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * (i % mod) % mod;
    }
    return ans;
}

int f[10001], g[10001];
int main()
{   
    ll n, ans = 0;
    cin >> n;
    for (int i = n-1; i>=0; i--)
    {
        f[i] = (f[i + 1] + n * inv(n - i, mod) % mod)%mod;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        g[i] = (n * inv(n - i, mod) % mod * f[i] % mod + g[i + 1]) % mod;
    }
    cout << g[0];
}
