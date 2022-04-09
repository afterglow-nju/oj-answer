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
using namespace std;
typedef long long ll;
ll read() {
	ll ans = 0, f = 1; char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -f; c = getchar(); }
	while (c >= '0' && c <= '9') ans = ans * 10 + c - 48, c = getchar();
	return ans * f;
}
int n;
struct Point {
	long long x, y;
}point[2002];

double mult(Point a, Point b, Point c) {
	return b.y * (a.x - c.x) + a.y * (c.x - b.x) + c.y * (b.x - a.x);
}
bool intersect(Point aa, Point bb, Point cc, Point dd)
{
	if (max(aa.x, bb.x) < min(cc.x, dd.x)) return false;
	if (max(aa.y, bb.y) < min(cc.y, dd.y)) return false;
	if (max(cc.x, dd.x) < min(aa.x, bb.x)) return false;
	if (max(cc.y, dd.y) < min(aa.y, bb.y)) return false;
	if ((mult(cc,dd ,aa) * mult(cc, dd, bb) > 0)|| (mult(aa, bb, cc) * mult(aa, bb, dd) > 0)) return false;
	return true;
}
bool boom[1011];
int main() {
	
	n = read();
	memset(boom, 0, sizeof(boom));
	for (int i = 1; i <= n; ++i) point[2 * i - 1].x = read(), point[2 * i - 1].y = read(), point[2 * i].x = read(), point[2 * i].y = read();
	for (int i = n; i>1; --i) {
		for (int j = i - 1; j >= 1; --j) {
			if (intersect(point[2 * i - 1], point[2 * i], point[2 * j - 1], point[2 * j]))
			{
				//cout << "i=" << i << "j=" << j << '\n';
				boom[j] = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (boom[i] == 0)ans++;
	}/*
	for (int i = 1; i <= n; i++)
	{
		cout << "i=" << i << " bool=" << boom[i] << '\n';
	}*/
	cout << ans << endl;
	return 0;
}