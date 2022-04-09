#include <iostream>
#include<vector>
#include<utility>
using namespace std;
typedef long long ll;
ll f[20000003];
pair<int, int>p[100001];
ll mod = 1e9 + 7;
vector<int> v[100001];
int deep[100001],a[100001];
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
    ans = f[n] * inv(f[m], mod) % mod * inv(f[n - m], mod) % mod;
    return ans % mod;
}

int main()
{
   // cout << (inv(3, mod) + inv(2, mod)) % mod;
    int n;
    cin >> n;
    //ll trick = 1,ans=0,mom=1;
    for (int i = 2; i <= n; i++)
    {   
        int t;
        cin >> t;
        //p[i].second = i;
        //p[i].first = t;
        //v[t].push_back(i);//v中是爸爸//第一是爸爸，第二是儿子
        a[i] = t;
    }
    ll ans = 1;
    for (int i = 2; i <= n; i++)
    {
        int t = a[i];
        int layer = 1;
        while (t != 1)
        {
            layer++;
            t = a[t];
        }
       // cout << layer << " ";
        ans = (ans + inv(layer+ 1, mod)) % mod;
    }
    cout << ans;
    

}

