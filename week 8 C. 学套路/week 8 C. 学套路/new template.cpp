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
const ll mod1 = 1e6;
const ll maxn = 1e6 + 10;
ll a[maxn];
int main()
{
	int T;
	while (T--)
	{
		memset(a, 0, sizeof(a));
		int n;
		cin >> n;
		int p, q, x, y, z;
		cin >> p >> q >> x >> y >> z;
		a[1] = p;
		a[2] = q;
		for (int i = 3; i <= n; i++)
		{
			a[i] = ((x * a[i - 2] + y * a[i - 1] + z) % mod1) + 1;
		}

	}
}