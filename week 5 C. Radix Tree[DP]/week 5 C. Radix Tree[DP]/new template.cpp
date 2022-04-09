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
ll A = 1 << 20;
int f[1 << 20 + 2],a[200001];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f[a[i]]++;
	}
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < A; j++)
		{
			if ( j& (1 << i))
				f[j] += f[j^(1 << i)];
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
	//	cout << f[(A - 1) ^ a[i]]<<" ";
		ans += f[(A-1)^a[i]];
	}
	cout << ans;
}
