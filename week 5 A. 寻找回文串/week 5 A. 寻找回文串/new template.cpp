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
ll n;
const ll maxn = 50001;
map <ll,ll> m;
ll a[maxn];
int main()
{
	ll T;
	cin >> T;
	bool f = false;
	while (T--)
	{
		cin >> n;
		m.clear();
		
		f = 0;
		for (ll i = 1; i <= n; i++)
		{
			cin >> a[i];
			if (m.find(a[i]) == m.end()) m[a[i]] = i;
			if (m.find(a[i]) != m.end() && m[a[i]] < i - 1)
			{
				f = 1;
				break;
			}
		}
		if (f)cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}