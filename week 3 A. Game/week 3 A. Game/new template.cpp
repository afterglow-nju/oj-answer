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
int n;
const int N = 1600;
vector<pair< int, int> > edge[N*N];
void addedge(int x, int y, int z) {
	edge[x].push_back(make_pair(y, z));
}

int f[N][2];
void dp(int p, int pa)
{
	f[p][0] = 0; f[p][1] = 1;
	vector<pair< int, int> > ::iterator it;
	for (it = edge[p].begin(); it != edge[p].end(); it++) {
		int y = it->first;
		if (y == pa)continue;
		dp(y, p);
		f[p][0] += f[y][1];
		f[p][1] += min(f[y][1], f[y][0]);
	}
	
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int p,k,t;
		cin >> p >> k;
		for (int i = 1; i <= k; i++)
		{
			cin >> t;
			addedge(p, t, 1);
			addedge(t, p, 1);
		}
	}
	dp(n-1, -1);//ÈÃ0×÷Îª¸ù
	cout << min(f[n-1][1], f[n-1][0]);

}






