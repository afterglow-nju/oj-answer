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
#include<cstring>
#include<stdio.h>
#include<limits>
using namespace std;
const int maxn = 100001;
int prime[2 * maxn + 10];
bool vis[2 * maxn + 10];
int a[maxn]; int index1 = 0;

const long long INF = 1e16;
const long long inf = 0x3f3f3f3f;
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

Dinic bi;


void get_prime(int n)
{
    for (int i = 2; i <= n; i++)vis[i] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (vis[i])prime[++index1] = i;
        for (int j = 1; j <= index1 && i * prime[j] <= n; j++)
        {
            vis[i * prime[j]] = 0;
            if (i * prime[j] == 0)break;
        }
    }
}



int main()
{
    get_prime(2 * maxn - 2);/*
    for (int i = 2; i <= 20; i++)
    {
        cout << i << " " << vis[i] << '\n';
    }*/
    int n;
    cin >> n;
    bool f = false; int count = 0; int index = 0;
    for (int i = 1; i <= n; i++)
    {
        int tem;
        cin >> tem;
        if (tem == 1 && f == false)
        {
            f = true;
            a[++index] = tem;
        }
        else if (f && tem == 1)
        {

            count++;
        }
        else a[++index] = tem;
    }
    n -= count;
    int s = 2*n+1; int t = s+1;//不知道为什么，s和t点取0和n+1不对，好奇怪？？
    for (int i = 1; i <= n; i++)
    {
        if (a[i] % 2 == 0)
        {
            // cout << "AA" << '\n';
            bi.AddEdge(s, a[i], 1);
        }
        else bi.AddEdge(a[i], t, 1);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int t1 = a[i] % 2;
            int t2 = a[j] % 2;
            if (t1 == 0 && t2 == 1)
            {
                // cout << a[i] + a[j] <<" "<<vis[a[i]+a[j]]<< '\n';
                if (vis[a[i] + a[j]])
                {

                    bi.AddEdge(a[i], a[j], inf);
                }
            }
        }
    }
    cout << n - bi.Maxflow(s, t);
}