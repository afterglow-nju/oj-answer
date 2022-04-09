#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N = 130;
int ans, a[N][N];//a记录图
bool BronKerbosch(int R[], int P[], int X[], int nr, int np, int nx)//RPX三个集合，nr是R中点的个数，Np，NX依次类推
{
    int i, j;
    if (np == 0 && nx == 0)//PX为空 输出极大团
    {
        ans++;
        if (ans > 1000)//超过题目限制 跳出所有循环
            return 1;
        return 0;
    }
    int u, max = 0;
    u = P[1];
    for (i = 1; i <= np; i++)
    {
        int cnt = 0;
        for (j = 1; j <= np; j++)
        {
            if (a[P[i]][P[j]])
                cnt++;
        }
        if (cnt > max)
        {
            max = cnt;
            u = P[i];
        }
    }
    //选取一个合适的u点
    for (i = 1; i <= np; i++)
    {
        int v = P[i];//从P\N（u）中取点v
        if (a[v][u]) continue;
        R[1 + nr] = v;//将点v加入集合R
        int cnt1 = 0, P1[N];
        memset(P1, 0, sizeof(P1));
        for (j = 1; j <= np; j++)
            if (P[j] && a[v][P[j]])
                P1[++cnt1] = P[j];//取P与v相交的部分
        int cnt2 = 0, X1[N];
        memset(X1, 0, sizeof(X1));
        for (j = 1; j <= nx; j++)
            if (a[v][X[j]])
                X1[++cnt2] = X[j];//取X与v相交的部分
        if (BronKerbosch(R, P1, X1, nr, cnt1, cnt2))
            return 1;
        X[++nx] = P[i];//将点v从P集合移入X集合
        P[i] = 0;
    }
    return 0;
}
int main()
{
    int n, i, m, x, y;
    cin >> n >> m;
    int P[N], X[N], R[N];
    memset(a, 0, sizeof(a));
    while (m--)
    {
        cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    ans = 0;
    memset(P, 0, sizeof(P));
    memset(X, 0, sizeof(X));
    memset(R, 0, sizeof(R));
    for (i = 1; i <= n; i++)
        R[i] = i;
    BronKerbosch(P, R, X, 0, n, 0);
    cout << ans;

    return 0;
}