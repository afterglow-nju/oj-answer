#include<iostream>
#include<stdio.h>
using namespace std;
char a[1000005], b[1005];
int nex[1000005][26], n, m;
int f[1005];
int main()
{
	scanf_s("%s", a + 1);
	scanf_s("%s", b + 1);
	n = strlen(a + 1);
	m = strlen(b + 1);

	for (int i = n; i >= 1; i--)
	{
		for (int j = 0; j < 26; j++) nex[i][j] = nex[i + 1][j];
		nex[i][a[i] - 'a'] = i;
	}
	int t = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = i; j >= 1; j--)
		{
			if (f[j - 1] || j == 1)
			{
				t = nex[f[j - 1] + 1][b[i] - 'a'];
				if (t != 0 && (!f[j] || f[j] > t))
				{
					f[j] = t;
				}
			}
		}
	}
	int ans = m;
	while (ans && !f[ans]) ans--;
	cout << ans;


}

