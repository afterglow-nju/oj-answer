#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N = 130;
int ans, a[N][N];//a��¼ͼ
bool BronKerbosch(int R[], int P[], int X[], int nr, int np, int nx)//RPX�������ϣ�nr��R�е�ĸ�����Np��NX��������
{
    int i, j;
    if (np == 0 && nx == 0)//PXΪ�� ���������
    {
        ans++;
        if (ans > 1000)//������Ŀ���� ��������ѭ��
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
    //ѡȡһ�����ʵ�u��
    for (i = 1; i <= np; i++)
    {
        int v = P[i];//��P\N��u����ȡ��v
        if (a[v][u]) continue;
        R[1 + nr] = v;//����v���뼯��R
        int cnt1 = 0, P1[N];
        memset(P1, 0, sizeof(P1));
        for (j = 1; j <= np; j++)
            if (P[j] && a[v][P[j]])
                P1[++cnt1] = P[j];//ȡP��v�ཻ�Ĳ���
        int cnt2 = 0, X1[N];
        memset(X1, 0, sizeof(X1));
        for (j = 1; j <= nx; j++)
            if (a[v][X[j]])
                X1[++cnt2] = X[j];//ȡX��v�ཻ�Ĳ���
        if (BronKerbosch(R, P1, X1, nr, cnt1, cnt2))
            return 1;
        X[++nx] = P[i];//����v��P��������X����
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