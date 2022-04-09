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
	ll tem = 1;
	for (; b; b >>= 1, a =quick_mul(a,a,m) % m)
	{
		if (b & 1)tem = quick_mul(tem,a,m) % m;
	}
	return tem;
}
int main()
{
	ll a, b, m;
	cin >> a >> b >> m;
	cout << quick_power(a, b, m);
}






