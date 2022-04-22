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
const int N = 1000;

vector<pair<int, int>  > edge[N];
void addedge(int x, int y, int z) {
	edge[x].push_back( make_pair(y, z));
}
typedef long long ll;
map<pair<int, int>, int>ma;
bool camp[N];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		addedge(a, b, c);
		addedge(b, a, c);
		ma[make_pair(a, b)] = i;
		ma[make_pair(b, a)] = i;

	}
	vector<pair<int, int>>ans;
	int cost = 0;
	camp[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		vector <pair<int,int>>a,b;
		int costa = 0, costb = 0;
		for (auto j : edge[i])
		{
			int y = j.first;
			int z = j.second;
			if (y < i)
			{
				if ((z < 0 && camp[y] == 1) || (z > 0 && camp[y] == 0))
				{
					a.push_back(make_pair(i, y));
					costa += abs(z);
				}
				else
				{
					b.push_back(make_pair(i, y));
					costb += abs(z);
				}
			}
		}
		if (costa<=costb)
		{	
			camp[i] = 1;
			cost += costa;
			for (auto i : a)
			{
				ans.push_back(i);
			}
		}
		else
		{
			camp[i] = 0;
			for (auto i : b)
			{
				ans.push_back(i);
			}
			cost += costb;
		}
	}
	cout << ans.size() << '\n';
	for (auto i : ans)
	{
		//cout << i.first << "  " << i.second << '\n';
		cout << ma[i] << '\n';
	}
}