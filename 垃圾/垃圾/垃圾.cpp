// week 4B.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;
int c[1000000], d[1000000], e[1000000], f[1000000];
int sum = 0;
int main()
{
	memset(e, 0, sizeof(d));
	unsigned long int x, y;
	int i = 0;
	cin >> y;
	while (y != 0)
	{
		c[i] = y % 2;
		y = y / 2;
		i++;
	}
	i--;
	//for (int j = 0; j <= i; j++) cout << c[j];
	int m = 0;
	for (i; i >= 0; i--)
	{
		if (c[i] == 1)
		{
			d[m] = pow(2, i);
			m++;
		}
	}
	m--;
	sort(d, d + m + 1);
	//	cout << "0 ";
	//	for (int j = 0; j <= m; j++) cout << d[j]<<" ";




		//cout << m;//m从0开始 所以m=2等于有三位数,循环直接用
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
	for (int i = 0; i <= u - 2; i++) cout << f[i] << " ";
}