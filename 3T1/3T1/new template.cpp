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
ll quick_power(ll x, ll y,ll m) //x^y % mod
{
	ll tem = 1;
	for (; y; y >>= 1, x = x * x% m)
	{
		if (y & 1)tem = tem * x % m;
	}
	return tem;
}
ll euler_phi(ll n) {
	ll m = ll(sqrt(n + 0.5));
	ll ans = n;
	for (ll i = 2; i <= m; i++)
		if (n % i == 0) {
			ans = ans / i * (i - 1);
			while (n % i == 0) n /= i;
		}
	if (n > 1) ans = ans / n * (n - 1);
	return ans;
}
ll phi = 1000000006;
ll phii = 500000002;
//Å£±Æyyc!!! phiÖµÁ¬»·Ì×£¡£¡£¡£¡£¡£¡
int main()
{	
	//cout << euler_phi(phi);
	int T;
	cin >> T;
	while (T--)
	{
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		if (c == 1 && d == 1)
		{
			cout << quick_power(a, b,mod)<<'\n';
		}
		else if (d == 1)
		{
			ll powerbc = quick_power(b, c, phi);
			cout << quick_power(a, powerbc, mod)<<'\n';
		}
		else
		{
			ll powercd = quick_power(c, d, phii);
			ll powerbc = quick_power(b, powercd, phi);
			cout << quick_power(a, powerbc, mod)<<'\n';
		}
	}
}






