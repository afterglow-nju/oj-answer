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
long long mod = 1e9 + 7;
long long quick_power(long long a, long long x, long long mod)
{ // a^x%mod
	long long ans = 1;
	while (x)
	{
		if (x & 1) ans = ans * a % mod;
		a = a * a % mod;
		x >>= 1;
	}
	return ans;
}
long long fac(long long n, long long mod)
{
	long long ans = 1;
	for (int i = 1; i <= n; i++)
	{
		ans = ans * i % mod;
	}
	return ans;
}
long long inv(long long n, long long mod)
{
	return quick_power(n, mod - 2, mod);
}
long long c(long long n, long long m)
{
	long long ans = fac(n, mod) * inv(fac(m, mod), mod) % mod * inv(fac((n - m), mod), mod) % mod;
	return ans;
}
long long lucas(long long n, long long m)
{
	if (n == 0) return 1;
	return c(n % mod, m % mod) * lucas(n / mod, m / mod) % mod;
}
int main()
{
	long long n, m, k, t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> k;
		long long ans = c(m,k)*quick_power(k, n, mod)%mod;//代表总个数
		long long bi = 0;//代表如果连续的个数
		for (int i = 1; i <= n - 1; i++)
		{
			long long tem = 1;
			tem = c(n - 1, i) * quick_power(k, i, mod) % mod;
			if (i % 2 == 0) tem = tem * (-1);
			bi = (bi + tem) % mod;
		}
		bi = c(m, k) * bi % mod;
		ans = (ans - bi) % mod;
		cout << ans<<'\n';
	}
}
/*
先不考虑任何条件，算出总共的个数，为后用容斥原理算出存在连续热爱等级的数量，然后作差
总共个数为c(m,k)*K^N
最后容斥来不及写了 :(

*/







