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
const int maxn = 40010;
int buk[201][maxn], p[maxn];
int f[maxn],cnt[maxn],pos[maxn];
int main()
{
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> p[i];
	int length = sqrt(n);
	memset(f, 0x3f3f3f, sizeof(f));
	f[0] = 0;
	for (int i = 1; i <= n; i++)
	{

		for (int j = 1; j <= length; j++)//段能最多只能有j个元素
		{
			buk[j][p[i]]++;
			if (buk[j][p[i]] == 1)
			{
				cnt[j]++;
				if (cnt[j] > j)//要新建一个段了
				{
					while (--buk[j][p[pos[j]]] != 0)
					{
						pos[j]++;
					}
					pos[j]++;
					cnt[j] = j;
				}
			}
			if (cnt[j] == j)
			{
				f[i] = min(f[pos[j] - 1] + j * j, f[i]);
			}
			/*cout << "J=" << j << '\n';
			for (int i = 1; i <= n; i++)cout << f[i] << " ";
			cout << '\n';
		*/}
		
	}
	cout << f[n];
}