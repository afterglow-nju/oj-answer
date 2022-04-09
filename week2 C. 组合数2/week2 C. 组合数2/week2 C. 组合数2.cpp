#include <iostream>
using namespace std;
typedef long long ll;
ll mod = 1e6 + 3;


ll fac(ll a)
{
    if (a == 0 || a == 1) return 1;
    ll t = 1;
    for (int i = 2; i <= a; i++) t = t * i % mod;
    return t;
}
ll inv(ll a, ll b, ll m)
{
    if (b == 0) return 1;
    if (b == 2) return a * a % m;
    if (b == 1) return a;
    if (b % 2 == 0) {
        long long temp = (inv(a, b / 2, m)) % m;
        return (temp * temp) % m;
    }
    else {
        long long temp1 = (inv(a, b / 2, m)) % m;
        return (temp1 * temp1 % m * a) % m;
    }
}


ll c(ll n, ll m)
{
    // if (n == 0) return 0;
    if (m > n) return 0;
    if (m == 0 || m == n) return 1;
    ll ans = fac(n) % mod * inv(fac(m), mod - 2, mod) % mod * inv(fac((n - m)), mod - 2, mod) % mod;
    return ans;
}
ll lac(ll n, ll m)
{
    //  if (m<mod) return c(n,m);
    if (m == 0) return 1;
    //   if (n > mod || m > mod)
    else
    {
        // cout << "A";
        return c(n % mod, m % mod) * lac(n / mod, m / mod) % mod;// cout << "A";
    }
    // else
    {
        //    ans += c(n, m);
    }
    // return ans;

}



int main()
{
    // cout<<fac(200);
    // cout << inv(fac(200), mod-2,mod);
    ll n, m;
    cin >> n >> m;
    /*   if (n >= mod || m >= mod)
       {
           ll ans = fac(n % mod) * inv(fac(m % mod), mod - 2, mod) % mod * inv(fac((n - m) % mod), mod - 2, mod) % mod * fac(n / mod) * inv(fac(m / mod), mod - 2, mod) % mod * inv(fac(n / mod - m / mod), mod - 2, mod) % mod;
           cout << ans;
       }
       else
       {
           ll ans = fac(n) * inv(fac(m), mod-2,mod) % mod * inv(fac(n - m), mod-2,mod) % mod;
           cout << ans;
       }*/
    cout << lac(n, m) % mod;
}

