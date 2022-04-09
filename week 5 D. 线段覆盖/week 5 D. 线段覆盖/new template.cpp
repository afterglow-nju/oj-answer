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
struct str
{
	ll l, r, c;
} s[2002];
bool com(str a, str b)
{
	return a.r < b.r;
}
ll f[2001];
int main()
{

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i].l >> s[i].r >> s[i].c;
	}
	sort(s + 1, s + 1 + n, com);
	s[n + 1].r = s[n + 1].l = m;
	s[0].r = s[0].l = 0;
	for (int i = 1; i <= n + 1; i++)
	{
		f[i] = 1e12;
		for (int j = 0; j < i; j++)
		{
			if(i!=n+1)f[i] = min(f[i], f[j]+(max(s[i].l - s[j].r,0ll)) * s[i].c);
			if (j != 0)f[i] = min(f[i], f[j]+(max(s[i].l - s[j].r,0ll)) * s[j].c);


		}//	cout << f[i] << '\n';
	}
	cout << f[n + 1];
}






