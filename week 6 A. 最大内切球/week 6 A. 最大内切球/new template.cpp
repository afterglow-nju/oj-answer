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
// m个约束，n个变量
// 第i个约束，sum(a[i][j]*x[j])+a[i][0]>=0
// solve函数返回约束是否有解
// 若有解，则使得目标函数 sum(a[0][j]*x[j]) 最大化
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define REP(i,n) FOR(i,1,n)
#define REP_0N(i,n) FOR(i,0,n)
using namespace std;
typedef long double ld;
#define maxn 505
#define N 1505
ld a[N][N];
int n, m, id[N], tp[N],x[N], nn;
const ld eps = 1e-9;
const ld inf = 1e12;
int T;
void pivot(int r, int c) {
    swap(id[r + n], id[c]);
    ld t = -a[r][c];
    a[r][c] = -1;
    REP_0N(i, n) a[r][i] /= t;
    REP_0N(i, m)
        if (a[i][c] && r != i) {
            t = a[i][c];
            a[i][c] = 0;
            REP_0N(j, n) a[i][j] += t * a[r][j];
        }
}
bool solve() {
    ld t;
    REP(i, n) id[i] = i;
    while (true) {
        int i = 0, j = 0; ld w = -eps;
        REP(k, m) if (a[k][0] < w) w = a[i = k][0];
        if (!i) break;
        REP(k, n) if (a[i][k] > eps) { j = k; break; }
        if (!j) return false;
        pivot(i, j);
    }
    while (true) {
        int i = 0, j = 0; ld w = eps;
        REP(k, n) if (a[0][k] > w) w = a[0][j = k];
        if (!j) break;
        w = inf;
        REP(k, m) if (a[k][j] < -eps && (t = -a[k][0] / a[k][j]) < w) w = t, i = k;
        if (!i) return true;
        pivot(i, j);
    }
    FOR(i, n + 1, n + m) tp[id[i]] = i - n;
    REP(i, n) x[i] = tp[i] ? a[tp[i]][0] : 0;
    return true;
}
ld b[N][N];
int main()
{

    cin >> T;
    n = 3;
    while (T--)
    {
        int n;
        cin >> n;
        m = n;
        for (int i = 1; i <= n; i++)
        {
            int A, B, C, D;
            cin >> A >> B >> C >> D;
            b[i][1] = a[i][1] = -A; b[i][2] = a[i][2] = -B; b[i][3] = a[i][3] = -C; b[i][0] = a[i][0] = D;

        }
        if (!solve())
        {
            cout << "0.0000" << '\n';
        }
        else
        {
            ld r = 1e10;
            ld l = 0;
            while (r - l >= eps)
            {
                ld mid = (l + r) / 2;
                for (int i = 1; i <= n; ++i)
                {
                    for (int j = 0; j <= 3; ++j)
                    {
                      /*  if (a[i][j] != b[i][j])
                        {
                            cout << a[i][j] << "    " << b[i][j] << '\n';
                        }*///用单纯形时会改变a中的值
                        a[i][j] = b[i][j];
                    }
                }
                for (int i = 1; i <= n; i++)
                {
                    ld sqr = sqrt(a[i][1] * a[i][1] + a[i][2] * a[i][2] + a[i][3] * a[i][3]);
                    a[++m][0] = a[i][0] - mid * sqr;
                    a[m][1] = a[i][1]; a[m][2] = a[i][2]; a[m][3] = a[i][3];

                }
                a[++m][1] = 1; a[m][2] = 0; a[m][3] = 0; a[m][0] = -mid;
                a[++m][1] = 0; a[m][2] = 1; a[m][3] = 0; a[m][0] = -mid;
                a[++m][1] = 0; a[m][2] = 0; a[m][3] = 1; a[m][0] = -mid;
                if (solve())
                {
                    l = mid;
                }
                else
                {
                    r = mid;
                }
                m -= n; m -= 3;//把新增的限制删掉
            }
            if (l > 1e9)
            {
                cout << "Infinity" << '\n';
            }
            else
            {
                printf("%.4lf\n", (double)l);
            }
        }

    }
}





