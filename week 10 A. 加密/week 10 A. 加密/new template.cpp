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

const ll e = (1 << 30) + 3;/*
ll quick_mul(ll a, ll b, ll m)
{
	a %= m;
	ll tem = 0;
	for (; b; b >>= 1, a = (a + a) % m)
	{
		if (b & 1)tem = (tem + a) % m, b--;
	}
	return tem;
}
ll quick_power(ll a, ll b, ll m)
{
	a %= m;
	//b%=m;
	ll tem = 1;
	for (; b; b >>= 1, a = quick_mul(a, a, m) % m)
	{
		if (b & 1)tem = quick_mul(tem, a, m) % m;
	}
	return tem;
}
*/
ll pow(ll a, ll b, ll n)
{
	ll result = 1LL; ll base = a;
	base = base % n; //n=n%m;
	if (b == 0) return 1;
	while (b) {
		if (b & 1)
			result = ((__int128)result * base) % n;
		b >>= 1;
		base = ((__int128)base * base) % n;
	}
	return result;
}/*
ll quick_power(ll a, ll b, ll m)
{
	a %= m;
	ll tem = 1;
	ll a128 = a;
	for (; b; b >>= 1, a128 = (__int128)a128* a128% m)
	{
		if (b & 1)tem = (__int128)tem*a128% m;
	}
	//ll ans = tem;
	return tem;
}*/
ll exgcd(ll a, ll b, ll* x, ll* y)
{
	if (b == 0) {
		*x = 1; *y = 0;
		return a;
	}
	ll ret = exgcd(b, a % b, x, y);
	ll t = *x;
	*x = *y;
	*y = t - a / b * (*y);
	return ret;
}
/*
ll phi(ll n)
{
	ll sq = sqrt(n) + 0.5;
	ll ans = 1;
	for (int i = 2; i <= sq; i++)
	{
		if (n % i == 0)
		{
			n /= i;
			ans = ans * (i - 1);
		}
	}
	return ans;
}
ll phi(ll n) {
	ll m = ll(sqrt(n + 0.5));
	ll ans = n;
	for (ll i = 2; i <= m; i++)
		if (n % i == 0) {
			ans = ans / i * (i - 1);
			while (n % i == 0) n /= i;
		}
	if (n > 1) ans = ans / n * (n - 1);
	return ans;
}*/
ll phi(ll x)
{
	ll ma = sqrt(x + 0.5);
	if ((ma & 1) == 0) ma--;
	for (ll i = ma; i > 90000; i -= 2)
	{
		if (x % i == 0)
		{
			ll ret = (i - 1) * (x / i - 1);
			return ret;
		}
	}
	return 0;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{	
		ll n, c;
		cin >> n >> c;
		ll phin = phi(n);
		//cout << "phin=" << phin << '\n';
		ll x = 0, y = 0;
		exgcd(e, phin, &x, &y);
		x = (x % phin + phin) % phin;
		//cout << x << '\n';
		ll result = pow(c, x,n);
		cout << result << '\n';
	}
}

//快速幂要128位，而且算欧拉函数要改进




