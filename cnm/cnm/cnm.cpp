#include <iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<iomanip>

using namespace std;
int c[1000000], e[1000000], g[100000], h[100000];
double f[1000000], d[100000];
char a[100000];
double sum = 0;
int main()
{
	memset(e, 0, sizeof(e));
	memset(g, 0, sizeof(g));

	int i = 0;
	cin >> a;
	while (a[i] != '\0')
	{
		g[i] = a[i] - '0';
		i++;
	}
	i--;
	int yushu = 0, n = 0;
	int j = 0;
	//bool flag = true;
	int flag = 0;
	while (flag == 0)
	{
		n = 0;
		for (n; n <= i; n++)
		{
			yushu = g[n] % 2;
			g[n + 1] = yushu * 10 + g[n + 1];
			g[n] = g[n] / 2;
		}
		c[j] = yushu;
		j++;
		flag = 1;
		for (int aa = 0; aa <= i; aa++) {
			if (g[aa] != 0)
			{
				flag = 0;
			}
		}
		//	cout << yushu;
	}
	j--;
	//int ww = 0;
//	for (j; j >= 0; j--,ww++) c[j]=h[ww];





	int m = 0;
	//int k = ww;
	for (j; j >= 0; j--)
	{
		if (c[j] == 1)
		{
			d[m] = pow(2, j);
			m++;
		}
	}
	m--;
	sort(d, d + m + 1);
	//	cout << "0 ";
	//	for (int j = 0; j <= m; j++) cout << d[j]<<" ";
		//找到所有二进制位为1的数所代表的的十进制数，不含0

	int u = pow(2, m + 1);
	for (int j = 0; j <= u - 2; j++)
	{
		e[0]++;
		sum = 0;
		int q = m;
		for (int i = 0; i <= m; i++)
		{
			if (e[i] >= 2)
			{
				e[i + 1]++;
				e[i] = 0;
			}
		}
		//	for (q;q>=0; q--)
		//	{
		//		cout << e[q];
		//	}
		//	cout << " ";
		for (int i = 0; i <= m; q--, i++)
		{
			if (e[q] == 1)
			{
				sum += d[i];
				//	cout << "aa";
			}
		}
		//	cout << sum<<" ";
		f[j] = sum;
	}

	sort(f, f + u - 2);
	cout << "0 ";
	for (int i = 0; i <= u - 2; i++) cout <<fixed<<setprecision(0)<< f[i] << " ";


}