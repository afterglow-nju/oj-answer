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

const ll encode = (1 << 30) + 3;

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
ll get_phi(ll x)
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
		ll n, c, x = 0, y = 0;
		cin>>n>>c;
		ll m = get_phi(n);
		cout << "m="<<m << '\n';
		exgcd(encode, m, &x, &y);
		ll decode = (x % m + m) % m;
		cout << decode << '\n';
		//ll result = pow(c, decode, n);
		//cout<<result<<'\n';
	}
}