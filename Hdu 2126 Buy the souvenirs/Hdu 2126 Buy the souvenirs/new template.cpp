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
long long p[31];
long long f[31][501], g[31][501];
long long d[501], plan[501];
int main()
{
	int T,m,n;
	cin >> T;
	while (T--)
	{	
		bool flag = false;
		memset(f, 0, sizeof(f));
		memset(g, 0, sizeof(g));
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			cin >> p[i];
			if(m>=p[i])flag=true;
		}
		if (flag == false)
		{
			cout << "Sorry, you can't buy anything.";
		}
		else
		{	
			for (int i = 0; i <= n; i++)
			{
				for (int j = 0; j <= m; j++)g[i][j] = 1; //������G[i][j]����F[i][j]�ķ�����������ô���ܽ��Ӧ����G[N][V]�����ǳ�ʼ��G[][]Ϊ1����Ϊ��ÿ��F[i][j]����Ӧ����һ�ַ�������ǰi����Ʒ��ѡȡ���ɼ���Ʒ����ʣ��ռ�Ϊj�ı���ʹ���ֵ���ķ���������Ϊ1����ΪF[i][j]һ�����ڡ�
			}
			
			for (int i = 1; i <= n; i++)
			{
				for (int v = 0; v <= m; v++)
				{
					f[i][v] = f[i - 1][v];//��ȡ��Ȼ���ڱȽϰɣ���������һ��
					g[i][v] = g[i - 1][v];						//˵����ȡ���ţ����Է���������g[i-1][v]
					if (v >= p[i])
					{
						if (f[i][v] < f[i - 1][v - p[i]] + 1)
						{
							f[i][v] = f[i - 1][v - p[i]] + 1;
							g[i][v] = g[i - 1][v - p[i]];		//˵��ȡ��i����Ʒ���ţ����Է���������g[i-1][v-p[i]]
						}
						else if (f[i][v] == f[i - 1][v - p[i]] + 1)	
						{
							g[i][v] += g[i - 1][v - p[i]];     // ˵��ȡ��i����Ʒ�Ͳ�ȡ��i����Ʒһ���ţ����Է��������
						}
					}
					/*
					if (v - p[i] >= 0)
					{
						f[i][v] = max(f[i - 1][v], f[i - 1][v - p[i]] + 1);
					}
					else
					{
						f[i][v] = f[i - 1][v];
					}
					//		g[i][v] = 0;
					if (f[i][v] == f[i - 1][v] && f[i][v] != f[i - 1][v - p[i]] + 1)
						g[i][v] = g[i - 1][v];
					else if (f[i][v] == f[i - 1][v - p[i]] + 1 && f[i][v] != f[i - 1][v])
						g[i][v] = g[i - 1][v - p[i]];
					else g[i][v] = g[i - 1][v] + g[i - 1][v - p[i]];
					*/
				}
				
			}
			cout << "You have " << g[n][m] << " selection(s) to buy with " << f[n][m] << " kind(s) of souvenirs.";
			
			/*
				memset(d, 0, sizeof(d));
				fill(plan, plan + 501, 1);
				for (int i = 1; i <= n; i++)
				{
					for (int v = m; v >= p[i]; v--)
					{
						/*
						if (d[v] == d[v - p[i]] + 1)
						{
							plan[v] += plan[v - p[i]];//ȡ��ȡ��һ���ţ����������
						}
						else if (d[v] < d[v - p[i]] + 1)
						{
							plan[v] = plan[v - p[i]];//��i����Ʒװ�룬ȡ��i����Ʒ���ţ����Է�������plan[v-p[i]]
						}
						d[v] = max(d[v -p[i]] + 1, d[v]);
					}
				}
				cout << "You have " << plan[m] << " selection(s) to buy with " << d[m] << " kind(s) of souvenirs.";
				*/
		}
		cout << '\n';
	}
}





