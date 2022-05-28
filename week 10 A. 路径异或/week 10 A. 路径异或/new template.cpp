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
思路：
    DFS计算从根节点到每个节点的异或和,同时计算倍增。
    然后利用倍增可以实现O(logn)的查询。
*/

/*
小结：
    学会了树上异或和的lca优化方法、还需要熟悉和理解lca原理
*/

const int N = 1e6 + 100;
vector<int> G[N];
int pre[N], a[N], par[N];
long long bit[30];
int f[N][30];
int depth[N];

//初始化 
void init() {
    bit[0] = 1;
    for (int i = 1; i <= 29; i++) bit[i] = (bit[i - 1] << 1);
}

//倍增
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

//从根节点1出发 求每个点到根节点的路径异或和 
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
    //建图 邻接表 
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= n; i++) G[i].clear();
    for (int i = 1; i <= n - 1; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    //lca
    dfs(1, 0);
    //计算从根节点到每个结点的异或和 
    DFS1(1, 0);
    int x, y;

    while (q--) {
        cin >> x >> y;
        int c = lca(x, y); //lca求出最近公共祖先 
        int f = par[c]; //求出最近公共祖先的父节点  这里再求一次父节点的原因是: 消除祖先的父节点到根节点这段路径(异或了2次)的异或 
        cout << (pre[x] ^ pre[f] ^ pre[c] ^ pre[y]) << endl; //画图理解 树链上异或两次就等于没有异或  
    }
    return 0;
}