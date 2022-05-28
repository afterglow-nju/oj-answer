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
/*
˼·��
    DFS����Ӹ��ڵ㵽ÿ���ڵ������,ͬʱ���㱶����
    Ȼ�����ñ�������ʵ��O(logn)�Ĳ�ѯ��
*/

/*
С�᣺
    ѧ�����������͵�lca�Ż�����������Ҫ��Ϥ�����lcaԭ��
*/

const int N = 1e6 + 100;
vector<int> G[N];
int pre[N], a[N], par[N];
long long bit[30];
int f[N][30];
int depth[N];

//��ʼ�� 
void init() {
    bit[0] = 1;
    for (int i = 1; i <= 29; i++) bit[i] = (bit[i - 1] << 1);
}

//����
void dfs(int u, int par) {
    depth[u] = depth[par] + 1;
    f[u][0] = par;
    for (int i = 1; bit[i] <= depth[u]; i++) f[u][i] = f[f[u][i - 1]][i - 1];
    for (int v : G[u]) {
        if (v != par) dfs(v, u);
    }
}

//lca
int lca(int x, int y) {
    if (depth[x] < depth[y]) swap(x, y);
    for (int i = 29; i >= 0; i--) {
        if (depth[x] - depth[y] >= bit[i]) {
            x = f[x][i];
        }
    }
    if (x == y) return x;
    for (int i = 29; i >= 0; i--) {
        if (depth[x] >= (1 << i) && f[x][i] != f[y][i]) {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}

//�Ӹ��ڵ�1���� ��ÿ���㵽���ڵ��·������ 
void DFS1(int u, int fa) {
    par[u] = fa;
    pre[u] = pre[fa] ^ a[u];
    for (int v : G[u]) {
        if (v == fa) continue;
        DFS1(v, u);
    }
}

int main() {
    int n, u, v, q;
    cin >> n>>q;
    init();
    //��ͼ �ڽӱ� 
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= n; i++) G[i].clear();
    for (int i = 1; i <= n - 1; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    //lca
    dfs(1, 0);
    //����Ӹ��ڵ㵽ÿ���������� 
    DFS1(1, 0);
    int x, y;

    while (q--) {
        cin >> x >> y;
        int c = lca(x, y); //lca�������������� 
        int f = par[c]; //�������������ȵĸ��ڵ�  ��������һ�θ��ڵ��ԭ����: �������ȵĸ��ڵ㵽���ڵ����·��(�����2��)����� 
        cout << (pre[x] ^ pre[f] ^ pre[c] ^ pre[y]) << endl; //��ͼ��� ������������ξ͵���û�����  
    }
    return 0;
}