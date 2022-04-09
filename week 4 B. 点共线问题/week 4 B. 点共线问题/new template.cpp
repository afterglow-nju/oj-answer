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
#include<climits>
#include<set>

using namespace std;
typedef long long ll;
const int maxn = 1100000;
const int size1 = 2000;
struct triple
{
	ll first, second;
};
struct triple dot[size1];
struct line
{
	ll a, b, c;
	bool operator==(const line& tem)const
	{
		if ((this->a == tem.a && this->b == tem.b && this->c == tem.c) || (this->a == -tem.a && this->b == -tem.b && this->c == -tem.c))return true;
		else return false;
	}
	bool operator<(const line& tem)const
	{
		if (this->a < tem.a)return true;
		else if (this->b < tem.b)return false;
		else if (this->c < tem.c)return false;
		else return false;
	}
}line[maxn];
bool cmp(const struct line& x, const struct line& y)
{
	if (x == y)return false;
	if (x.a < y.a)return true;
	else if (x.b < y.b)return true;
	else if (x.c < y.c)return true;
	return false;
}
struct line s[size1][size1];
ll gcd1(ll a, ll b)
{
	if (b == 0) return a;
	return gcd1(b, a % b);
}
ll gcd(ll a, ll b, ll c)
{
	ll tem = gcd1(a, b);
	return gcd1(tem, c);
}
int main()
{
	int n;
	cin >> n;
	if (n <= 2)cout << n;
	else
	{
		for (int i = 1; i <= n; i++)
		{
			ll x, y;
			cin >> x >> y;
			dot[i] = { x, y };

		}
		struct line t;
		t.a = 2*INT_MAX; t.b = 2*INT_MAX; t.c = 2*INT_MAX;
		int ans = 1, num = 0;
		for (int i = 1; i <= n; i++)
		{
			ll x1 = dot[i].first, y1 = dot[i].second;
			num = 0;
			for (int j = 1; j <= n; j++)
			{
				struct line tem;
				if (i == j)tem = t;
				else
				{
					ll x2 = dot[j].first, y2 = dot[j].second;
					ll A = y2 - y1;
					ll B = x1 - x2;
					ll C = x1 * (y1 - y2) + y1 * (x2 - x1);
					ll mod = gcd(A, B, C);
					if (mod != 0)
					{
						A = A / mod; B = B / mod; C = C / mod;
					}

					tem.a = A; tem.b = B; tem.c = C;
				}
				s[i][j] = tem;
			}
		}

		//cout << "-------"<<s[i][j].a << " " << s[i][j].b << " " << s[i][j].c << " " << '\n';
		int cnt = 0;

		for (int i = 0; i <= n; i++)
		{
			s[i][0] = t;
		}

		for (int i = 1; i <= n; i++)
		{
			sort(s[i] + 1, s[i] + n + 1);/*
			for (int j = 2; j <= n; j++)
			{
				cout << s[i][j].a << " " << s[i][j].b << " " << s[i][j].c << '\n';
			}
			cout << "------------" << '\n';*/

			int cnt = 1;
			//cout << "----------" << '\n';
			for (int j = 1; j < n; j++)
			{
				//cout << i << " " << j << '\n';

			//	cout << s[i][j].a << " " << s[i][j].b << " " << s[i][j].c << " " << '\n';

				if (s[i][j - 1] == s[i][j])
				{
					cnt++;
						//cout << "A" << '\n';
						//cout << i << " " << j << " " << '\n';
				}
				else
				{
					//cout << "cnt=" << cnt << '\n';
					ans = max(ans, cnt);
					cnt = 1;
				}
			}
			ans = max(ans, cnt);
		}
		cout << ans + 1;
	}
}
/*
5
1 1
2 2
3 3
4 4
5 5
*/