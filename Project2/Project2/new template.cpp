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

vector<vector<int> > temp;
vector<int> t;
pair<int, int> dot[15];
long long a[2000001], b[2000001];


long long FastPower(long long b, long long n)
{
	long long mod = n;
	n = n - 2;
	long long ans = 1;
	while (n > 0)
	{
		if (n & 1) ans = ans * b % mod;
		n = n >> 1;
		b = (b * b) % mod;
	}
	return ans;
}

int main()
{
	long long n, m, k, mod = 1e9 + 7;
	cin >> n >> m >> k;
	long long ways[16][16];
	for (int i = 0; i < k; i++)
	{
		cin >> dot[i].first >> dot[i].second;
	}
	sort(dot, dot + k);
	//Ԥ����׳�
	a[0] = 1;
	b[0] = 1;
	for (int i = 1; i <= 2000000; i++)
	{
		a[i] = a[i - 1] * i % mod;
		b[i] = b[i - 1] * FastPower(i, mod) % mod;
	}
	//dot[i]->dot[j]��·���� 
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (dot[i].first <= dot[j].first && dot[i].second <= dot[j].second)
			{
				ways[i][j] = ((a[dot[j].first - dot[i].first + dot[j].second - dot[i].second] * b[dot[j].first - dot[i].first]) % mod) * b[dot[j].second - dot[i].second] % mod;
			}
			else ways[i][j] = 0;
		}
	}
	long long way1[16], way2[16];
	long long sum = 0;
	//i�ķ�Χ��1-2^p.size()���ռ����⣬ÿһ���Ӽ�����Ӧ��
		//�����ƶ���һ����Ҳ����i
	for (int i = 1; i < (1 << k); ++i) 
	{	
		memset(way1, 0, sizeof(way1));
		long long ans = 0, bits = 0;
		int index = 1;
		for (int j = 0; j < k; ++j)
		{
			if (i & (1 << j))
			{
				bits++;//��i�Ķ����Ƶĵ�jλ�Ƚϣ����Ƿ�Ϊ1������ѡ��
				way1[index++]=j;
			}
		}
		index--;
		if (index > 1)
		{
			for (int i = 1; i < index;i++)
			{
				ans += ways[way1[i]][way1[i + 1]] % mod;
			}
		ans=ans+ways[0][way1[1]]+way1[index][n]
		}

		cout << ans;
		if (bits & 1)//��1�ĸ�������������мӷ���������м���
			sum =(sum+ans)%mod ;
		else sum =(sum-ans)%mod ;
	}
	//cout << sum;
	

}






