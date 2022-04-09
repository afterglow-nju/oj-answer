#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<bitset>
#include<stack>
#include<utility>
#include<iomanip>
#include<vector>
#include<math.h>
#include<string>
#include<stdio.h>
#include<limits>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll euler_phi(ll n)
{
    ll ans = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans = ans / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) ans = ans / n * (n - 1);
    return ans;
}

ll quick_power(ll x, ll y) //x^y % mod
{
    ll tem = 1;
    for (; y; y >>= 1, x = x * x % mod)
    {
        if (y & 1)tem = tem * x % mod;
    }
    return tem;
}
int main()
{   

    ll n, m;
    cin >> n >> m;
    ll tem = n;
    ll ans = 0;//对称的
    for (ll i = 1; i*i <= n; i++)
    {
        if (n % i == 0)
        {   
            ans = (ans + quick_power(m, i) * euler_phi(n/i) % mod) % mod;
            if(i*i!=n)
            ans = (ans + quick_power(m, n/i) * euler_phi(i) % mod) % mod;

        }
    }
   // ans = ans / n;
    //不能直接除n，要乘上n的逆元
    cout << ans*quick_power(n,mod-2)%mod;
}






