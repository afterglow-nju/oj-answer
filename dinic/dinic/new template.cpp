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
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int M = 300;
struct MCMF
{
    struct Edge
    {
        int from, to, cap, flow, cost;
        Edge(int u, int v, int c, int f, int w) : from(u), to(v), cap(c), flow(f), cost(w) {}
    };
    vector<Edge>edges;
    vector<int>G[M];
    int inq[M], p[M], a[M], d[M];
    void addEdge(int from, int to, int cap, int cost)
    {
        edges.push_back(Edge(from, to, cap, 0, cost));
        edges.push_back(Edge(to, from, 0, 0, -cost));
        G[from].push_back(edges.size() - 2);
        G[to].push_back(edges.size() - 1);
    }
    bool spfa(int s, int t, int& flow, ll& cost)
    {
        memset(d, 127, sizeof(d));
        memset(inq, 0, sizeof(inq));
        d[s] = 0;
        inq[s] = 1;
        p[s] = 0;
        a[s] = INF;
        queue<int>Q;
        Q.push(s);
        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            inq[u] = 0;
            for (int i = 0; i < (int)G[u].size(); i++)
            {
                Edge& e = edges[G[u][i]];
                if (e.cap > e.flow && d[e.to] > d[u] + e.cost)
                {
                    d[e.to] = d[u] + e.cost;
                    p[e.to] = G[u][i];
                    a[e.to] = min(a[u], e.cap - e.flow);
                    if (!inq[e.to])
                    {
                        Q.push(e.to);
                        inq[e.to] = 1;
                    }
                }
            }
        }
        if (d[t] >= INF) return false;
        flow += a[t];
        cost += (ll)d[t] * (ll)a[t];
        for (int u = t; u != s; u = edges[p[u]].from)
        {
            edges[p[u]].flow += a[t];
            edges[p[u] ^ 1].flow -= a[t];
        }
        return true;
    }
    pair<int, ll> solve(int s, int t)
    {
        int flow = 0; ll cost = 0;
        while (spfa(s, t, flow, cost));
        return { flow, cost };
    }
}mcmf,mcmf1;
int record[205][205];
int main()
{
    int n;
    cin >> n;
    int s = 0, t = 2 * n + 1;
    for (int i = 1; i <= n; i++)
    {
        mcmf.addEdge(s, i, 1, 0);
        for (int j = 1; j <= n; j++)
        {
            int ex;
            cin >> ex;
            record[i][j] = ex;
            mcmf.addEdge(i, j+n, 1, ex);

        }
        mcmf.addEdge(i + n, t, 1, 0);
    }
    pair<int, ll> tem=mcmf.solve(s,t);
    int minm = tem.first - tem.second;
    cout << tem.second << '\n';
    for (int i = 1; i <= n; i++)
    {
        mcmf1.addEdge(s, i, 1, 0);
        for (int j = 1; j <= n; j++)
        {
           mcmf1.addEdge(i, j + n, 1, -record[i][j]);
        }
        mcmf1.addEdge(i + n, t, 1, 0);
    }
    tem = mcmf1.solve(s, t);
    int maxm = tem.first - tem.second;
    cout << -tem.second << '\n';
    // cout << minm << '\n' << maxm;

}






