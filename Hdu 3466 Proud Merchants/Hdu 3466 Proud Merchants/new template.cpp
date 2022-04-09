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
//int p[501], q[501], v[501];
struct node
{
	int p;
	int q;
	int v;
}t[501];
bool com(node a, node b)
{
	return a.p - a.q >b.p - b.q;
}
int d[5001];
int main()
{
	int n, m;
	while (cin>>n>>m)
	{	
		memset(d, 0, sizeof(d));

		for (int i = 0; i < n; i++)
		{
			cin >> t[i].p >> t[i].q >> t[i].v;
		}
		sort(t, t + n,com);
		for (int i = 0; i < n; i++)
		{
			for (int j = m; j >= t[i].q; j--)
			{
				d[j] = max(d[j],d[j-t[i].p]+t[i].v);
			}
		}
		cout << d[m] << '\n';
	}
}






