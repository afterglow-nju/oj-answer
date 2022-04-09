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
const long long  inf=0x3fffffff;
using namespace std;
long long dis[1000001];
bool used[1000001];
vector<pair< long long, long long> > edge[1000001];
void addedge(long long x, long long y, long long z) {
	edge[x].push_back(make_pair(y, z));
}
vector<pair< long long, long long> > ::iterator it;
priority_queue < pair< long long, long long>, vector < pair < long long ,long long>>, greater<pair<long long ,long long>> > q;
int main()
{	
	long long T;
	cin >> T;
	while (T--)
	{
		long long n;
		cin >> n;
		for (long long i = 0; i <= n; i++) { dis[i] = inf; used[i] = false; }
		//fill(dis[0], dis[0] + 1, inf);
		dis[1] = 1;//Å¼Êý
		q.push(make_pair(dis[1],1));
		while (!q.empty())
		{
			long long w = q.top().first;
			long long v = q.top().second;
			
			q.pop();
			if (used[v])continue;
			used[v] = 1;
			dis[2 * v % n] = min(w, dis[2 * v % n]);
			dis[(2 * v + 1) % n] = min(w + 1, dis[(2 * v + 1) % n]);
			q.push(make_pair(dis[2 * v % n], 2 * v % n));
			q.push(make_pair(dis[(2 * v +1)% n], (2 * v+1) % n));
		}
		cout << dis[0] << '\n';
	}
}






