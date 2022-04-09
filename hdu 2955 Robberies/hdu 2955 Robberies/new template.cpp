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
int m[101];
double p[101];
//d[i][m]=pro
double d[100000];
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		double pro;
		int n;
		cin >> pro >> n;
		pro = 1 - pro;//pro bu bei zhua de gai lv 
		memset(m, 0, sizeof(m));
		memset(p, 0, sizeof(p));
		memset(d, 0, sizeof(d));
		long long total = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> m[i] >> p[i];
			p[i] = 1 - p[i];
			total += m[i];
		}
		d[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (long long j =total; j >=m[i]; j--)
			{
				d[j]= max(d[j], d[j-m[i]]* p[i]);
			}
		}
		for (long long j = total; j >=0; j--)
		{	
			if (d[j]>=pro)
			{
				cout << j <<'\n';
				break;
			}
		}
		

	}
	
}

/*
s[i]
f[i]
d[i][j]
j=s
for(int i=1;i<=n;i++)
{
	for(int j=1;j<=total;j++)
	{	
		d[i][j]=d[i-1][j];
		if(j-s[i]>=0)
		d[i][j]=max(d[i-1][j],d[i-1][j-s[i]]+f[i]+s[i])
	}
}

*/






