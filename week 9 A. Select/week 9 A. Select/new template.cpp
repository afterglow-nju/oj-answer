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
#include <set>
using namespace std;
const int maxn = 100001;
int a[maxn],f[maxn],g[maxn];
int lo[maxn], ub[maxn];
map<int, int> mmap;
int main()
{
	int n, m;
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	mmap[a[n]] = n;
	lo[n] = -1;
	ub[n] = -1;
	for (int i = n - 1; i >= 1; i--)
	{
		auto it=mmap.lower_bound(a[i]);
		if (it == mmap.end())lo[i] = -1;
		else lo[i] = it->second;
		it = mmap.upper_bound(a[i]);
		if (it == mmap.begin())
		{
			ub[i] = -1;
		}
		else
		{
			it--;
			ub[i] = it->second;
		}
		mmap[a[i]] = i;

	}
	for (int i = 1; i <= m; i++)
	{
		int t, p;
		cin >> t >> p;
		if (t)
		{
			cout << ub[p] << '\n';
		}
		else
		{
			cout << lo[p] << '\n';
		}
	}



}



/*
* 
* 
* 
* 
	sort(b+1,b+1+n);
	for (int i = n; i >= 1; i--)
	{
		while (!s.empty() && b[s.top()].first < b[i].first)s.pop();
		f[i] = s.empty() ? -1 : s.top();
		s.push(i);
	}
	for (int i = n; i >= 1; i--)
	{
		while (!s1.empty() && b[s1.top()]> b[i])s1.pop();
		g[i] = s1.empty() ? -1 : s1.top();
		s1.push(i);
	}
	for (int i = 1; i <= m; i++)
	{
		int t, p;
		cin >> t >> p;
		if (t)
		{
			cout << g[p] << '\n';
		}
		else
		{
			cout << f[p] << '\n';
		}
	}
	
* 
for (int i = 1; i <= m; i++)
{
	int T, p, ans;
	cin >> T >> p;
	if (T)
	{
		ans = 0;
		a[0] = 0;
		for (int j = p + 1; j <= n; j++)
		{
			if (a[j] <= a[p])
			{
				if (a[ans] < a[j])ans = j;
			}
		}
		if (ans == 0)ans = -1;
	}
	else
	{
		ans = 0;
		a[0] = INT_MAX;
		for (int j = p + 1; j <= n; j++)
		{
			if (a[j] >= a[p])
			{
				if (a[ans] > a[j])ans = j;

			}
		}
		if (ans == 0)ans = -1;
	}
	cout << ans << '\n';
}
*/