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
#define N 30100
#define M 480010
#define int long long
const int INF = 0x3f3f3f3f;
const int INFF = 0x3f3f3f3f3f3f3f3fll;

int n, m, art[105][105], sci[105][105];
int art_ex[105][105], sci_ex[105][105];

int node(int x, int y) { return (x - 1) * m + y; }
int same_art(int x, int y) { return n * m * 1 + node(x, y); }
int same_sci(int x, int y) { return n * m * 2 + node(x, y); }

int mv[5][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

bool in_map(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= m;
}

int cnt = -1, head[N];

struct edge {
	int nxt, to, f;
}e[M];

void add_edge(int from, int to, int flw) {
	e[++cnt].nxt = head[from];
	e[cnt].to = to;
	e[cnt].f = flw;
	head[from] = cnt;
}

queue <int> q;
#define fpop(x) x.front();x.pop()

int cur[N], deep[N];

bool bfs(int s, int t) {
	memcpy(cur, head, sizeof(head));
	memset(deep, 0x3f, sizeof(deep));
	deep[s] = 1; q.push(s);
	while (!q.empty()) {
		int u = fpop(q);
		for (int i = head[u]; ~i; i = e[i].nxt) {
			int v = e[i].to;
			if (e[i].f && deep[v] == INFF) {
				deep[v] = deep[u] + 1;
				q.push(v);
			}
		}
	}
	return deep[t] != INFF;
}

int dfs(int u, int t, int lim) {
	if (u == t || !lim) {
		return lim;
	}
	int tmp = 0, flow = 0;
	for (int& i = cur[u]; ~i; i = e[i].nxt) {
		int v = e[i].to;
		if (deep[v] == deep[u] + 1) {
			tmp = dfs(v, t, min(lim, e[i].f));
			lim -= tmp;
			flow += tmp;
			e[i ^ 0].f -= tmp;
			e[i ^ 1].f += tmp;
			if (!lim) break;
		}
	}
	return flow;
}

int Dinic(int s, int t) {
	int min_cut = 0;
	while (bfs(s, t)) {
		min_cut += dfs(s, t, INFF);
	}
	return min_cut;
}

signed main() {
	memset(head, -1, sizeof(head));
	cin >> n >> m;
	int s = n * m * 3 + 1, t = n * m * 3 + 2;
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) cin >> art[i][j];
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) cin >> sci[i][j];
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) cin >> art_ex[i][j];
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) cin >> sci_ex[i][j];

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			add_edge(s, node(i, j), art[i][j]); add_edge(node(i, j), s, 0);
			add_edge(node(i, j), t, sci[i][j]); add_edge(t, node(i, j), 0);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			add_edge(s, same_art(i, j), art_ex[i][j]); add_edge(same_art(i, j), s, 0);
			add_edge(same_sci(i, j), t, sci_ex[i][j]); add_edge(t, same_sci(i, j), 0);
			for (int k = 0; k < 5; ++k) {
				int tx = i + mv[k][0], ty = j + mv[k][1];
				if (in_map(tx, ty)) {
					add_edge(same_art(i, j), node(tx, ty), INFF); add_edge(node(tx, ty), same_art(i, j), 0);
					add_edge(node(tx, ty), same_sci(i, j), INFF); add_edge(same_sci(i, j), node(tx, ty), 0);
				}
			}
		}
	}
	int ans = 0;// n * m * INF;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			ans += art[i][j] + sci[i][j] + art_ex[i][j] + sci_ex[i][j];
		}
	}
	cout << ans<<" "<< Dinic(s, t) << endl;
}