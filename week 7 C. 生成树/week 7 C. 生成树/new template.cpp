
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
#define N 100010
#define ll long long
int n, m, fa[N], f[11];
ll ans;
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void merge(int x, int y, ll w)
{
    if (find(x) != find(y))
    {
        fa[find(x)] = find(y);
        ans += w;
    }
}
struct edge
{
    int from, to; ll w;
    bool operator<(edge b) const { return w < b.w; }
}e[N * 50];

void kruskal()
{
    for (int i = 1; i <= n; i++) fa[i] = i;
    std::sort(e, e + m);
    for (int i = 0; i < m; i++) merge(e[i].from, e[i].to, e[i].w);
}

struct oo { int x; int y; bool operator<(oo b)const { return x < b.x; } }a[N];
#define sq(x) (ll)(x)*(x)
inline ll calc(int x, int y) { return sq(a[x].x - a[y].x) + sq(a[x].y - a[y].y); }
void run(int x)
{
    for (int j = 0; j <= 10; j++) if (f[j])
        e[m++] = edge{ f[j],x,calc(x,f[j]) };
    f[a[x].y] = x;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
    std::sort(a + 1, a + 1 + n);
    f[a[1].y] = 1;
    for (int i = 2; i <= n; i++) run(i);

    for (int i = 0; i <= 10; i++) f[i] = 0;
    f[a[n].y] = n;
    for (int i = n - 1; i >= 1; i--) run(i);
    kruskal();
    cout << ans;
}
/*#include<iostream>
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
class UnionFindSet {
private:
    vector<int> f;
    int _setid(int x) {
        if (f[x] == x) return x;
        return f[x] = _setid(f[x]);
    }

    void _merge(int x, int y) {
        if (setid(x) < setid(y)) f[setid(y)] = setid(x);
        else f[setid(x)] = setid(y);
    }

public:
    UnionFindSet(int n = 0) {
        f = vector<int>(n);
        for (int i = 0; i < n; i++) f[i] = i;
    }

    int setid(int x) {
        return _setid(x);
    }

    void merge(int x, int y) {
        _merge(x, y);
    }
};
const long long maxn = 1e6 + 1;
pair<int, int> dot[maxn];
map<pair<int, int>, double> edge;
double dis(int x1, int y1,int x2, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int d[11][maxn];
int main()
{
    int n;
    cin >> n;
    int xbound = 0;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;

        xbound = max(xbound, x);
        dot[i].first = x;
        dot[i].second = y;
    }
    sort(dot + 1, dot + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        cout<<dot[i].first;
        cout<<" "<<dot[i].second <<'\n';
    }
    UnionFindSet u(maxn << 1);
    int id = 1;
    for (int i = 0; i <= xbound; i++)
    {
        while (dot[id].first == i)
        {
            for (int j = 0; j < dot[id].second; j++)
            {
                for(int k=id)
            }
            id++;
        }
        
    }

}
*/