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
const int maxn = 100001;
typedef long long ll;
int a[maxn];
vector<int>b,s1,bs1,s2,bs2;
int dp[maxn][2];
int n;
int ans;
int c[2001];
void dfs(int step)
{
	if (step == n + 1)
	{
		int cnt = 0;
		int aans = 0;
		for (int i = 1; i <= n; i++)
		{
			//	cout << c[i] << " ";
			if (c[i] == 1)
			{
				cnt++;
				if (a[i] == cnt)aans++;
			}

		}
		//	cout << '\n';
		ans = max(ans, aans);
		return;
	}
	if (a[step] <= step)
	{
		c[step] = 0;
		dfs(step + 1);
		return;
	}
	c[step] = 1;
	dfs(step + 1);

}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b.push_back(a[i]);
	}
	dfs(1);
	cout << ans;

}
/*
d0 = b;
	d1 = b;
	d0.erase(d0.begin());
	int tem = 0;
	for (int i = 0; i < d0.size(); i++)
	{
		if (d0[i] == i + 1)tem++;
	}
	if (a[1] == 1)
	{
		dp[1][0] = tem;
		dp[1][1] = 1;
	}
	else
	{
		dp[1][0] = tem;
		dp[1][1] = 0;
		//shan
	}
	for (int i = 2; i <= n; i++)
	{

	}
*/