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

#define maxn 204
#define INF 0x3f3f3f3f
struct Edge {
    int from, to, cap, flow;
    Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};
struct Dinic {
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    int d[maxn], cur[maxn];
    bool vis[maxn];

    void init(int n) {
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from, int to, int cap) {
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    bool BFS() {
        memset(vis, 0, sizeof(vis));
        queue<int> Q;
        Q.push(s);
        d[s] = 0;
        vis[s] = 1;
        while (!Q.empty()) {
            int x = Q.front();
            Q.pop();
            for (int i = 0; i < G[x].size(); i++) {
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

    int DFS(int x, int a) {
        if (x == t || a == 0) return a;
        int flow = 0, f;
        for (int& i = cur[x]; i < G[x].size(); i++) {
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

    int Maxflow(int s, int t) {
        this->s = s;
        this->t = t;
        int flow = 0;
        while (BFS()) {
            memset(cur, 0, sizeof(cur));
            flow += DFS(s, INF);
        }
        return flow;
    }
};

int main()
{
    pair<int, int >red[101];
    pair<int, int> b[101];

    Dinic a;
    int n;
    cin >> n;
    a.init(2 * n+2);
    a.n = 2 * n + 2;
    a.s = 0;
    a.t = 2 * n + 1;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        red[i] = make_pair(x,y);
    }
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        b[i] = make_pair(x, y);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (red[i].first < b[j].first && red[i].second < b[j].second)
            {
                a.AddEdge(i, n+j, 1);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        a.AddEdge(0, i, 1);
        a.AddEdge(n + i,2*n+1, 1);
    }
    int ans = a.Maxflow(0, 2 * n + 1);
    cout << ans;
}






