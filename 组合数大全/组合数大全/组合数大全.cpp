#include <iostream>
using namespace std;
typedef long long ll;
ll mod = 1e6 + 3;
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
ll c(ll n, ll m)
{
    ll ans = 0;
    ans = fac(n) * inv(fac(m), mod) % mod * inv(fac(n - m), mod) % mod;
    return ans % mod;
}
ll lucas(ll n, ll m)
{
    if (n == 0) return 1;
    return c(n % mod, m % mod) * lucas(n / mod, m / mod) % mod;
}
int main()//卢卡斯定理
{
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    cout << lucas(n, m);
}

/*
组合数1
        采用杨辉三角和滚动数组，只记录杨辉三角每行前m的值 O(mn)
ll mod = 1e9 + 7;
ll c[10000];
int main()
{
    int n, m;
    cin >> n >> m;
    m = min(m, n - m);
    c[0] = 1;
    for(int i=1;i<=n;i++)
    {
        for (int j = m; j >= 1; j--)
            c[j] = (c[j] + c[j - 1])%mod;
    }
    cout << c[m];
}


快速幂 注意在qf中return的项是相乘不是相加

ll qf(ll b, ll n)
{
    if (n == 0) return 1;
    if (n == 1) return b;
    ll n1 = n;
    n1 >>= 1;
    ll t = qf(b, n1)%mod;
    if (n & 1)
    {

        return t*t%mod*b%mod;
    }
    else
    {
        return t*t%mod;
    }
}
int main()
{
    ll n, b;
    cin >> n >> b;
    cout << qf(b, n - 2);
}

逆元解决组合数

ll mod = 1e9 + 7;
ll qf(ll b, ll n)
{
    if (n == 0) return 1;
    if (n == 1) return b;
    ll n1 = n;
    n1 >>= 1;
    ll t = qf(b, n1)%mod;
    if (n & 1)
    {

        return t*t%mod*b%mod;
    }
    else
    {
        return t*t%mod;
    }
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
        ans = ans * (i%mod)%mod;
    }
    return ans;
}
ll c(ll n, ll m)
{
    ll ans = 0;
    ans = fac(n) * inv(fac(m),mod)%mod*inv(fac(n-m),mod)%mod;
    return ans%mod;
}
int main()
{
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    cout << c(n, m);
}

卢卡斯定理

*/