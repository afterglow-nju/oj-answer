#include <iostream>
#include <algorithm>
#include <utility>
#include <iterator>
#include <cmath>
using namespace std;
typedef long long LL;
const int maxn = 50;
const LL INF = 1e10;

int n;
LL w[maxn], v[maxn];
LL W;
pair<LL, LL> ps[1 << (maxn / 2)];   // (重量, 价值)

void solve()
{
    //枚举前半部分
    int n2 = n / 2;
    for (int i = 0; i < (1 << n2); ++i)
    {
        LL sw = 0, sv = 0;
        for (int j = 0; j < n2; ++j)
            if ((i >> j) & 1)
            {
                sw += w[j];
                sv += v[j];
            }
        ps[i] = make_pair(sw, sv);
    }

    //去除多余的元素
    sort(ps, ps + (1 << n2));
    int m = 1;
    for (int i = 1; i < (1 << n2); ++i)
        if (ps[m - 1].second < ps[i].second)
            ps[m++] = ps[i];

    //枚举后半部分并求解
    LL res = 0;
    for (int i = 0; i < (1 << (n - n2)); ++i)
    {
        LL sw = 0, sv = 0;
        for (int j = 0; j < n - n2; ++j)
            if ((i >> j) & 1)
            {
                sw += w[n2 + j];
                sv += v[n2 + j];
            }
        if (sw <= W)
        {
            LL tv = (lower_bound(ps, ps + m, make_pair(W - sw, INF)) - 1)->second;
            res = max(res, sv + tv);
        }
    }

    printf("%lld\n", res);
}

int main()
{
    scanf_s("%d%lld", &n, &W);
    for (int i = 0; i < n; ++i)
    {
        scanf_s("%lld%lld", &w[i], &v[i]);
    }
    solve();
}

