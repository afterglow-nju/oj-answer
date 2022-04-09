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
struct
{
	int num;
	long long v;
}d[200000];
int s[101], f[101];
int main()
{
	int n;
	cin >> n;
	long long total = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i] >> f[i];
		s[i] += 1000;
		total += s[i];
	}
	for (int i = 0; i < 200000; i++)d[i].v = -INT_MAX;
	d[0].num = 0, d[0].v = 0;//初始化很重要
	for (int i = 1; i <= n; i++)
	{
		for (int j = total; j >= s[i]; j--)
		{
			if (d[j].v - 1000 * d[j].num < d[j - s[i]].v + f[i] -1000- 1000 * d[j - s[i]].num)
			{
				d[j].v = d[j - s[i]].v + f[i];
				d[j].num = d[j - s[i]].num+1;
			}
		}
	}
	long long ans = 0;
	for (int j = total; j >= 0; j--)
	{
		if(j-1000*d[j].num>=0&&d[j].v>=0)
		ans = max(ans, d[j].v+j-1000*d[j].num);
	}
	cout << ans;
}






