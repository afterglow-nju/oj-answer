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
const long long di = 30000000;
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
long long a[200], b[200], c[200],l[200],r[200],sta[200];
long long ans;
Dinic dinic;
int main()
{   
    //Dinic dinic;
    
    long long n, m;
    cin >> n >> m;
    l[0] = 0; r[0] = -1;
    long long s, t;
    s = 1; t = 2; sta[0] = 2;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    for (long long i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
        long long sum = 0;
        for (long long j = l[i]; j <= r[i]; j++)
        {
            sum += a[i] * j * j + b[i] * j + c[i];
        }
        ans += sum;
        sta[i] += sta[i - 1] + r[i - 1] - l[i - 1] + 1;
        dinic.AddEdge(s, sta[i] + 1, sum - (a[i] * l[i] * l[i] + b[i] * l[i] + c[i]) + di);
        for (long long j = l[i] + 1; j <= r[i]; j++)
        {
            dinic.AddEdge(sta[i] + j - l[i], sta[i] + j - l[i] + 1, sum - ( a[i] * j * j + b[i] * j + c[i]) + di);
        }
        dinic.AddEdge(sta[i] + r[i] - l[i] + 1, t, INF);

    }
    for (long long i = 1; i <= m; i++)
    {
        long long x, y, d;
        cin >> x >> y >> d;
        if (l[y] < l[x] - d && l[x] - d - 1 < r[y])
            dinic.AddEdge(s, sta[y] + l[x] - d - l[y], INF);
        if (l[x] - d - 1 >= r[y])
            dinic.AddEdge(s, sta[y] + r[y] - l[y] + 1, INF );
        for (long long j = l[x] + 1; j <= r[x]; ++j)
        {
            if (l[y] <= j - d - 1 && j - d - 1 <= r[y])
            {
                dinic.AddEdge(sta[x] + j - l[x], sta[y] + j - d - l[y], INF);
            }
            if (j - d - 1 > r[y]) dinic.AddEdge(sta[x] + j - l[x], sta[y] + r[y] - l[y] + 1, INF);
        }
    }
    cout<<ans - dinic.Maxflow(s, t) + di*n;
}






