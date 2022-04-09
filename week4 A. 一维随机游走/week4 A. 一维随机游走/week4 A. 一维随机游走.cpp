#include <iostream>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;

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
int main()
{
    ll a, b, c, t = 1, m = 1;
    cin >> a >> b >> c;
    if (c == 2)
    {
        cout << a % mod * inv(a + b, mod)%mod;
    }
    else if (c == 1) cout << 1;
    else
    {
        t = qf(c-1, a+b)%mod;
        t--;
        t = qf(t, mod - 2);
        m = qf(c - 1, a)%mod;
       ll w = qf(c - 1, b );
        cout << (m-1)%mod* t%mod;
      // cout << ((t * t % mod + t) % mod + (w * m % mod)) % mod * (inv(t * t % mod - 1, mod)) % mod;
        //ll qw = qf(c, b);
        //cout << inv(qw - 1, mod);
    }
}


