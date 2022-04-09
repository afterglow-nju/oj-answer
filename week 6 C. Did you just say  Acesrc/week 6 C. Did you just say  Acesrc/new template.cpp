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
typedef long long ll;
const ll mod=1e9+7;

int k = 2;
struct matrix
{
	long long m[2][2];
	matrix()
	{
		memset(m, 0, sizeof(m));
	}
	friend matrix operator*(matrix a, matrix b)
	{
		matrix ans;
		for (int i = 0; i < k ; i++)
		{
			for (int j = 0; j < k; j++)
			{
				for (int l =0; l < k ; l++)
				{
					ans.m[i][j] = (ans.m[i][j] + a.m[i][l] * b.m[l][j]%mod) % mod;
				}
			}
		}
		return ans;
	}
	friend matrix operator^(matrix a, long long b)
	{
		matrix ans;
		for (int i = 0; i < k; i++)ans.m[i][i] = 1;
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
matrix f;
int main()
{
	ll n;
	cin >> n;
	
	f.m[0][0] = 4;
	f.m[0][1] = 1;
	f.m[1][0] = 2;
	f.m[1][1] = 1;
	if (n == 1)cout << 1;
	else
	{
		f = f ^ (n-1);
		cout << f.m[0][0]<<"   "<<f.m[0][1]<<"  "<<(f.m[0][0]+ f.m[0][1]) % mod;
	}
}
//递推式可以用矩阵快速解决






