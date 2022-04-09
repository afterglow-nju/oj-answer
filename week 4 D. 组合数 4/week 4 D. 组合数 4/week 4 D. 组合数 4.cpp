#include <iostream>
using namespace std;
typedef long long ll;
ll M= 2000000;
ll mod = 1000000007;
ll x, y;

ll a[2000001];
ll p[2000001];
ll inv_x[2000001];
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
ll c(ll n, ll m)
{
    ll ans = 0;
    ans = a[n] * inv_x[m]% mod * inv_x[n-m] % mod;
    return ans % mod;
}
ll lucas(ll n, ll m)
{
    if (n == 0) return 1;
    return c(n % mod, m % mod) * lucas(n / mod, m / mod) % mod;
}
ll s()
{
    a[0] = 1,inv_x[0]=1;
    cin >> x >> y;
    ll t = min(x, y); ll t1 = max(x, y);
    x = t; y = t1;
    return lucas(x + y, x);
}
int main()
{
    int t;
   
    ll ans = 0;
    a[0] = 1, inv_x[0] = 1;
    
   
   
    for (ll i = 1; i <= M; i++)
    {
        a[i] = i * a[i - 1] % mod;
    }
    
    for (ll i = 0; i <= M; i++)
    {
        inv_x[i] = inv(a[i], mod);
    }
    
     cin >> t;
    while (t--)
    {   
       // s();
        cout << s()<<'\n';
    }
}


