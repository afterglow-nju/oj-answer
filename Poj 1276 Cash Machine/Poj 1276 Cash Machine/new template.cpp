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
const long long maxn = 100001;
int d[maxn],num[11],v[11],val[maxn];
int cash, n;
void divide()
{
	int i, j, k, tot = 0;
	for (int i = 1; i <= n; i++)
	{
		if (num[i] == 0) continue;
		for (k = 0; (1 << k) <= num[i]; k++)
		{	
			num[i] -= (1 << k);
			val[++tot] = (1 << k) * v[i];
		}
		val[++tot] = num[i] * v[i];
	}
	memset(d, 0, sizeof(d));
	for (int i = 1; i <= tot; i++)
	{
		for (int j = cash; j >= val[i]; j--)
		{
			d[j] = max(d[j], d[j - val[i]] + val[i]);
		}
	}
	//cout << d[cash] << '\n';
}
void multiple_package()
{
	int tot = 0,volumn;
	int weight[maxn], val[maxn], d[maxn], v[maxn], w[maxn];
	for (int i = 1; i <= n; i++)
	{
		for (int k = 0; (1 << k) <= num[i]; k++)
		{
			num[i] -= (1 << k);
			val[++tot] = v[i] * (1 << k);
			weight[tot] = w[i] * (1 << k);
		}
		val[++tot] = v[i] * num[i];
		weight[tot] = w[i] * num[i];
		memset(d, 0, sizeof(d));
		for (int i = 1; i <= tot; i++)
		{
			for (int j = volumn; j >= weight[i]; j--)
			{
				d[j] = max(d[j], d[j - weight[i]] + val[i]);
			}
		}

	}
//多重背包二进制化简
}
int main()
{
	while (cin >> cash >> n)
	{
		
		for (int i = 1; i <= n; i++)
		{
			cin >> num[i]>>v[i];
		}
		divide();

	}

}






