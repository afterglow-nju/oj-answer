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
#define maxn 400011
const long long INF = 1e16;
const long long delt = 1e11;//yjh
const long long inf = 0x3f3f3f3f;
long long read() {
    long long ans = 0, f = 1; char c = getchar();
    while (c < '0' || c>'9') { if (c == '-')f = -f; c = getchar(); }
    while (c >= '0' && c <= '9') ans = ans * 10 + c - 48, c = getchar();
    return ans * f;
}
struct Edge {
    long long from, to, cap, flow;
    Edge(long long u, long long v, long long c, long long f) : from(u), to(v), cap(c), flow(f) {}
};
struct Dinic {
    long long  n, m, s, t;
    vector<Edge> edges;
    vector<long long> G[maxn];
    long long d[maxn], cur[maxn];
    bool vis[maxn];
    

    void init(long long n) {
        memset(d, 0, sizeof(d));
        memset(cur, 0, sizeof(cur));
        memset(vis, 0, sizeof(vis));
        for (long long i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }

    void AddEdge(long long from, long long to, long long cap) {
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    bool BFS() {
        memset(vis, 0, sizeof(vis));
        queue<long long> Q;
        Q.push(s);
        d[s] = 0;
        vis[s] = 1;
        while (!Q.empty()) {
            long long x = Q.front();
            Q.pop();
            for (long long i = 0; i < G[x].size(); i++) {
                Edge& e = edges[G[x][i]];
                if (!vis[e.to] && e.cap > e.flow) {
                    vis[e.to] = 1;
                    d[e.to] = d[x] + 1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    long long DFS(long long x, long long a) {
        if (x == t || a == 0) return a;
        long long flow = 0, f;
        for (long long& i = cur[x]; i < G[x].size(); i++) {
            Edge& e = edges[G[x][i]];
            if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0) {
                e.flow += f;
                edges[G[x][i] ^ 1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0) break;
            }
        }
        return flow;
    }

    long long Maxflow(long long s, long long t) {
        this->s = s;
        this->t = t;
        long long flow = 0;
        while (BFS()) {
            memset(cur, 0, sizeof(cur));
            flow += DFS(s, INF);
        }
        return flow;
    }
};
long long in[10001], out[10001];

void solve()
{
    Dinic m;
    int n=read(), w = read(), p = read(), q = read();
   // cin >> n >> w >> p >> q;
    m.init(maxn);
    m.n = n + 2;
    for (int i = 1; i <= n; i++)
    {
        in[i] = -w;
        out[i] = w;
    }
    for (int i = 1; i <= p; i++)
    {
        int x = read(), y = read(), z = read(), a = read(), b = read(), c = read(), d = read(), e = read(), f = read();
       // cin >> x >> y >> z >> a >> b >> c >> d >> e >> f;
        m.AddEdge(x, y, 2 * a * w);
        m.AddEdge(y, x, 2 * a * w);
        m.AddEdge(y, z, 2 * b * w);
        m.AddEdge(z, y, 2 * b * w);
        m.AddEdge(x, z, 2 * c * w);
        m.AddEdge(z, x, 2 * c * w);
        in[x] += (d - f) * (-w); out[x] += (d - f) * (w);
        in[y] += (e - d) * (-w); out[y] += (e - d) * w;
        in[z] += (f - e) * (-w); out[z] += (f - e) * w;
    }
    for (int i = 1; i <= q; i++)
    {
        int x = read(), y = read(), r = read();
       // cin >> x >> y >> r;
        if (r == 0) m.AddEdge(x, y, INF);
        if (r == 1) m.AddEdge(y, x, INF), m.AddEdge(x, y, INF);
        if (r == 2)out[x] = INF, in[y] = INF;
    }
    int s = 0, t = n + 1;
    m.s = s; m.t = t;
    for (int i = 1; i <= n; i++)
    {
        m.AddEdge(s, i, delt + in[i]);
        m.AddEdge(i, t, delt + out[i]);
    }
    cout << m.Maxflow(s, t) - 1LL * n * delt << '\n';
}
int main()
{
    int T = read();
   // cin >> T;
    while (T--)
    {
        solve();
    }
}






