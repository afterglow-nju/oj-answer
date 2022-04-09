#include <iostream>
#include<utility>
#include<algorithm>
#include<vector>
#include<queue>
typedef long long ll;
using namespace std;
pair<ll, ll> b[17],a[17];//100
ll d[17][17];//1000 1000
ll barrier = 0 ,k;
bool used[100];//100
ll mod = 1000000007;
ll f[20000003];
ll t_barrier = 1;
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
ll lucas(ll n, ll m)
{
    if (n == 0) return 1;
    return c(n % mod, m % mod) * lucas(n / mod, m / mod) % mod;
}
bool com(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first <= b.first && a.second <= b.second)return true;
    else 
    {
        if (a.first <= b.first) return true;
        else return false;
    }
}
vector<long long> dis,em;
void dfs(ll x, ll t ,ll n)
{   
    if (t == n)
    {
        ll sign = t_barrier;
        for (int i = 1; i <= k; i++)
        {
            if (used[i] == false)
            {   
               // cout << i << " ";
                dis.push_back(i);
            }
        }
       // cout << '\n';
        ll length = dis.size();
       // t_barrier = t_barrier * d[0][dis[0]] % mod*d[dis[length-1]][k+1]%mod;
        for (int i = 0; i <= length - 2; i++)
        {
            t_barrier = t_barrier * d[dis[i]][dis[i + 1]]%mod;
        }
        t_barrier = t_barrier * d[0][dis.front()]%mod * d[dis.back()][k + 1]%mod;
       // cout << t_barrier << " "<<'\n';
        dis = em;
        barrier = (barrier + t_barrier) % mod;
        t_barrier = sign;
       return; 
    }
    for (ll i = x; i <= k; i++)
    {
        if (used[i])
        {
            t++;
            used[i] = false; 
            dfs(i, t, n);
            t--;
            used[i] = true; 
        }
    }
}

int main()
{   
    f[0] = 1;
    for (int i = 1; i <= 20000002; i++)
    {
        f[i] = i * f[i - 1] % mod;
    }
	ll n, m,ans=0;
    bool f = true; ll i = 1;
    while(f)
    {
        
        if (inv(i, mod) == 833333341) { f = false; cout << i; }
        i++;
    }
   
	cin >> n >> m >> k;
    for (int i = 1; i <= 18; i++)used[i] = true;
    a[0].first = 0; a[0].second = 0;
    a[k + 1].first = n; a[k + 1].second = m;
	for (ll i = 1; i <= k; i++)
	{
		ll t1, t2;
		cin >> t1 >> t2;
        a[i].first = t1;
        a[i].second = t2;
	}
    sort(a+1, a+k+1);
    for (ll i = 0; i <= k+1 ; i++)
    {
        for (ll j = i + 1; j <= k + 1; j++)
        {
            if (a[i].first <= a[j].first && a[i].second <= a[j].second)
            {
                d[i][j] = c(a[j].first - a[i].first + a[j].second - a[i].second, a[j].second - a[i].second);
            }
            else d[i][j] = 0;
        }
    }
   // ll barrier = 0;
    for (ll j = 1; j <= k; j++)
    {
        t_barrier = 1;
        if (j % 2 == 0)t_barrier = -1;
        else t_barrier = 1;
        dfs(1, 0, j); 
    }
    //cout << d[0][k + 1];
   // cout << c(m + n, n)%mod;
    //cout << " " << barrier;a
    ans = (c(m+n,m)%mod - barrier+mod)%mod;
    cout << ans;
}





