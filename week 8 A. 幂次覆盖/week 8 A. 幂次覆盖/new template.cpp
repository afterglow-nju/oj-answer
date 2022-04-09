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
ll read() {
	ll ans = 0; char c = getchar();
	while (c < '0' || c>'9') c = getchar();
	while (c >= '0' && c <= '9') ans = (ans * 10 + c - 48), c = getchar();
	return ans;
}
ll read1() {
	ll ans = 0; char c = getchar();
	while (c < '0' || c>'9') c = getchar();
	while (c >= '0' && c <= '9') ans = (ans * 10 + c - 48) % (mod - 1), c = getchar();
	return ans;
}
ll a[100001];
ll quick_power(ll x, ll y) //x^y % mod
{
	ll tem = 1;
	for (; y; y >>= 1, x =x*x % mod)
	{
		if (y & 1)tem = tem * x % mod;
	}
	return tem;
}

void ext_gcd(int a, int b, int& d, int& x, int& y)
{
	if (!b)
	{
		d = a;
		x = 1;
		y = 0;
	}
	else
	{
		ext_gcd(b, a % b, d, y, x);
		y -= x * (a / b);
	}
}
int main()
{
	int d;
	int x;
	int y;
	ext_gcd(234, 165, d, x, y);
	cout << d << " " << x << " " << y;
	ll k = read1();
	ll n = read();
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		ans = (ans + quick_power(a[i], k)) % mod;
	}
	cout << ans;
	

}






