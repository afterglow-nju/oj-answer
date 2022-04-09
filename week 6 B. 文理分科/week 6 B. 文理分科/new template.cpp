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

#define maxn 40001
//#define INF //0x3f3f3f3f
//#define INFF (unsigned)-1>>1//0x3f3f3f3f
const int INFF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f3f3f3f3fll;
const int dx[6] = { 0,0,0,-1,1 };
const int dy[6] = { 0,-1,1,0,0 };
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
    Dinic cut;

    int n, m;
    cin >> n >> m;
    cut.n = m * n * 3 + 2;
    cut.init(m*n*3+2);
    int s = 0,t =3*m*n+1;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int art;
            cin >> art;
            ans += art;
            cut.AddEdge(s, i*m+j, art);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int sci;
            cin >> sci;
            ans+=sci;
            cut.AddEdge(i*m+j, t, sci);
        }
    }
    int po = n*m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int sameart;
            cin >> sameart;
            ans += sameart;
            cut.AddEdge(s, ++po, sameart);
            cut.AddEdge( po,i*m+j, sameart);

            if (i == 0)
            {
                if (j == 1)
                {
                    cut.AddEdge(po, (i + 1) * m + j, INFF);
                    cut.AddEdge(po, (i)*m + j + 1, INFF);
                }
                else if (j == m)
                {
                    cut.AddEdge(po, (i + 1) * m + j, INFF);
                    cut.AddEdge(po, (i)*m + j - 1, INFF);
                }
                else
                {
                    cut.AddEdge(po, (i + 1) * m + j, INFF);
                    cut.AddEdge(po, (i)*m + j - 1, INFF);
                    cut.AddEdge(po, (i)*m + j + 1, INFF);
                }

            }
            else if (i == n-1)
            {
                if (j == 1)
                {
                    cut.AddEdge(po, (i - 1) * m + j, INFF);
                    cut.AddEdge(po, (i)*m + j + 1, INFF);
                }
                else if (j == m)
                {
                    cut.AddEdge(po, (i - 1) * m + j, INFF);
                    cut.AddEdge(po, (i)*m + j - 1, INFF);
                }
                else
                {
                    cut.AddEdge(po, (i - 1) * m + j, INFF);
                    cut.AddEdge(po, (i)*m + j - 1, INFF);
                    cut.AddEdge(po, (i)*m + j + 1, INFF);
                }
            }
            else if (j == 1)
            {
                cut.AddEdge(po, (i-1) * m + j, INFF);
                cut.AddEdge(po, (i + 1) * m + j, INFF);
                cut.AddEdge(po, (i)*m + j + 1, INFF);
            }
            else if (j == m)
            {
                cut.AddEdge(po, (i - 1) * m + j, INFF);
                cut.AddEdge(po, (i + 1) * m + j, INFF);
                cut.AddEdge(po, (i)*m + j-1, INFF);
            }
            else
            {
                cut.AddEdge(po, (i - 1) * m + j, INFF);
                cut.AddEdge(po, (i + 1) * m + j, INFF);
                cut.AddEdge(po, (i)*m + j - 1, INFF);
                cut.AddEdge(po, (i)*m + j + 1, INFF);
            }

        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int samesci;
            cin >> samesci;
            ans += samesci;
            cut.AddEdge(++po,t,samesci);
            cut.AddEdge(i*m+j,po,samesci);

            if (i == 0)
            {
                if (j == 1)
                {
                    cut.AddEdge((i + 1) * m + j,po, INFF);
                    cut.AddEdge( (i)*m + j + 1,po, INFF);
                }
                else if (j == m)
                {
                    cut.AddEdge((i + 1) * m + j, po, INFF);
                    cut.AddEdge( (i)*m + j - 1, po, INFF);
                }
                else
                {
                    cut.AddEdge( (i + 1) * m + j, po, INFF);
                    cut.AddEdge( (i)*m + j - 1, po, INFF);
                    cut.AddEdge( (i)*m + j + 1, po, INFF);
                }

            }
            else if (i == n-1)
            {
                if (j == 1)
                {
                    cut.AddEdge((i - 1) * m + j, po, INFF);
                    cut.AddEdge( (i)*m + j + 1, po, INFF);
                }
                else if (j == m)
                {
                    cut.AddEdge((i - 1) * m + j, po, INFF);
                    cut.AddEdge( (i)*m + j - 1, po, INFF);
                }
                else
                {
                    cut.AddEdge( (i - 1) * m + j, po, INFF);
                    cut.AddEdge( (i)*m + j - 1, po, INFF);
                    cut.AddEdge( (i)*m + j + 1, po, INFF);
                }
            }
            else if (j == 1)
            {
                cut.AddEdge((i - 1) * m + j, po, INFF);
                cut.AddEdge( (i + 1) * m + j, po, INFF);
                cut.AddEdge( (i)*m + j + 1, po, INFF);
            }
            else if (j == m)
            {
                cut.AddEdge((i - 1) * m + j, po, INFF);
                cut.AddEdge( (i + 1) * m + j, po, INFF);
                cut.AddEdge( (i)*m + j - 1, po, INFF);
            }
            else
            {
                cut.AddEdge((i - 1) * m + j, po, INFF);
                cut.AddEdge( (i + 1) * m + j, po, INFF);
                cut.AddEdge( (i)*m + j - 1, po, INFF);
                cut.AddEdge( (i)*m + j + 1, po, INFF);
            }

        }
    }
    cout << ans- cut.Maxflow(s, t);


}






