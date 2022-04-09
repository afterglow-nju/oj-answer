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
pair<long long, long long> p[500001];
long long a[500001],red[500001];
bool f[500001];
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>> q ;
int main()
{	
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		memset(a, 0, sizeof(a));
		memset(p, 0, sizeof(p));
		memset(red, 0, sizeof(red));
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			p[i].first = a[i];
			p[i].second = i;
			q.push(p[i]);
		}

		long long m=n;
		while (!q.empty())
		{	
			while (q.top().first>p[m].first)
			{	
				pair<long long, long long> tem = q.top();
				q.pop();
				f[tem.second] = true;
				red[tem.second] = m - tem.second - 1;
			}
			q.pop();
			
			for (int i = m-1; i >= 1; i--)
			{
				if (f[i] == false)
				{
					m = i;
					break;
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{	
			if (f[p[i].second] == false) cout << -1 << " ";
			else cout << red[i] << " ";
		}
		cout << '\n';
	}
}






