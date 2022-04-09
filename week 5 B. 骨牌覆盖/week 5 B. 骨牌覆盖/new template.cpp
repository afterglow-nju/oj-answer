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
typedef long long ll;
using namespace std;
int k;
ll mod;
struct matrix
{
	ll m[10][10];
	matrix()
	{
		memset(m, 0, sizeof(m));
	}
	friend matrix operator*(matrix a, matrix b)
	{
		matrix ans;
		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < k; j++)
			{
				for (int l = 0; l < k; l++)
				{
					ans.m[i][j] = (ans.m[i][j] + a.m[i][l] * b.m[l][j] % mod) % mod;
				}
			}
		}
		return ans;
	}
	friend matrix operator^(matrix a, long long b)
	{
		matrix ans;
		for (int i = 0; i < k; i++)
		{
			//for (int j = 0; j < k; j++)
			//{
			//	ans.m[i][j] = a.m[i][j];
		//
			ans.m[i][i] = 1;

		}

		while (b)
		{
			if (b & 1)
			{
				ans = ans * a;
			}
			a = a * a;
			b >>= 1;
		}
		return ans;
	}
};
matrix m1, m2;
int main()
{
	//m1.ma[1][1] = 0;
	m1.m[0][1] = 1;
	m1.m[1][0] = 1;
	m1.m[1][1] = 1;
	m2.m[7][0] = m2.m[7][3] = m2.m[7][6] = 1;
	m2.m[6][1] = m2.m[6][7] = m2.m[5][2] = m2.m[4][3] = m2.m[3][4] = m2.m[2][5] = m2.m[1][6] = m2.m[0][7] = m2.m[3][7] = 1;
	/*	m2.m[0][1] = 1;
		m2.m[0][4] = 1;
		m2.m[0][7] = 1;
		m2.m[1][0] = 1;
		m2.m[1][6] = 1;
		m2.m[2][5] = 1;
		m2.m[3][4] = 1;
		m2.m[4][0] = 1;
		m2.m[4][3] = 1;
		m2.m[5][2] = 1;
		m2.m[6][1] = 1;
		m2.m[7][0] = 1;*/
	ll n, m, p;
	cin >> n >> m >> p;
	mod = p;
	if (n == 1)
	{
		if (m % 2 == 0)cout << 1;
		else cout << 0;
	}
	else if (n == 2)
	{
		k = 2;
		m1 = m1 ^ (m - 1);
		cout << (m1.m[0][1] + m1.m[1][1]) % mod;
	}
	else
	{
		k = 8;
		m2 = m2 ^ m;
		cout << m2.m[7][7] << '\n';
		/*	for (int i = 0; i < k; i++)
			{
				for (int j = 0; j < k; j++)
				{
					cout << m2.m[i][j] << " ";
				}
				cout << '\n';
			}

			ll t = 0;

			for (int i = 0; i < k; i++)
			{
				t = (t + m2.m[k-1][i]) % mod;
			}
			cout << t;
		}*/
	}
}