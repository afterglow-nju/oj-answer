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
const int maxn = 100000;
struct Edge {
	int v, w;
};
vector<Edge> edge[maxn];
int dis[maxn], cnt[maxn], vis[maxn];
queue<int> q,t;
void addedge(int x, int y, int z)
{
    edge[x].push_back(Edge{y,z});
}
bool spfa(int n, int s)//n���ܱ�����s��Դ��
{
    memset(dis, 63, sizeof(dis));
    dis[s] = 0, vis[s] = 1;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop(), vis[u] = 0;
        for (auto ed : edge[u]) {
            int v = ed.v, w = ed.w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;  // ��¼���·�����ı���
                if (cnt[v] >= n) return false;  // �ڲ���������������£����·���ྭ�� n - 1 ����
                // �����������˶��� n ���ߣ�һ��˵�������˸���
                if (!vis[v]) q.push(v), vis[v] = 1;
            }
        }
    }
    return true;
}
int main()
{
	int T;
	cin >> T;
    while (T--)
    {   
        memset(edge, 0, sizeof(edge));
        memset(dis, 0, sizeof(dis));
        memset(cnt, 0, sizeof(cnt));
        memset(vis, 0, sizeof(vis));
        q = t;
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 1; i <= k; i++)
        {
            int x, y, c;
            cin >> x >> y >> c;
            addedge(x, y+n, -c);
            addedge(y+n, x, c);
        }
        for (int i = 1; i <= n + m; i++)addedge(0, i, 0);
        if (spfa(n+m+2*k, 0))cout << "Yes";
        else cout << "No";
        cout << '\n';
    }
}
//https://oi-wiki.org/graph/diff-constraints/#p49261007