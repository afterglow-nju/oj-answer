#include <iostream>
/*
/*const int MAXN = 15;   //申明常数MAXN
bool used[MAXN];    //标记数字是否用过。
int ans[MAXN];
int n;

void PaiLie(int k)   //当前讨论到第k的一位
{
    if (k == n + 1)        //此时表示前n个位置都填充好了，可以输出答案。
    {
        for (int i = 1; i <= n; i++) cout << ans[i];
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++) //讨论第k个位置，可以填哪些数字
    {
        if (used[i] == 0)        //used[i]==0，表示数字i没有被用过，可以填到k位置
        {
            used[i] = true;      //将数字i标记为已使用
            ans[k] = i;            //记录答案
            PaiLie(k + 1);     //继续讨论下一位
         //   ans[k] = 0;           //还原现场，将i标记为未使用
            used[i] = 0;
        }
    }
}
int main()
{
    cin >> n;
    PaiLie(1);//填充第1个位置到第n个位置
}

*/



/*
int n;
//int* p = new int[n+1];
//bool* used = new bool[n+1];
bool used[100]; int p[100];
void dfs(int k)
{
    if (k == n + 1)
    {
        for (int i = 1; i <= n; i++) cout << p[i];
        cout << '\n';
        return;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (used[i] == true)
            {
                p[k] = i;
                used[i] = false;
                dfs(k + 1);
                used[i] = true;
                //p[i] = 0;
            }
            
        }
    }
}

int main()
{  
     cin >> n;
    
    for (int i = 1; i <= n; i++)
    {
       
        used[i] = true;
    }
    dfs(1);
   // delete []p;
    //delete[]used;
}
*/

#include<queue>
using namespace std;
typedef long long ll;
ll read() {
    ll ans = 0; char c = getchar();
    while (c < '0' || c>'9') c = getchar();
    while (c >= '0' && c <= '9') ans = ans * 10 + c - 48, c = getchar();
    return ans;
}
int n;
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };
struct node {
    int x, y;
};
queue<node> q;
int maxn = 0;
int dist[1011][1011];
bool check(int x, int y) {
    if (x<1 || x>n || y<1 || y>n)
        return 0;
    return 1;
}
int main() {
    n = read();
    memset(dist, -1, sizeof(dist));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x = read();
            if (x) {
                q.push({i, j });
                dist[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {

            cout << dist[i][j] << " ";

        }cout << '\n';
    }
   /* while (!q.empty()) {
        node s = q.front();
        q.pop();
        maxn = max(maxn, dist[s.x][s.y]);
        for (int i = 0; i < 4; ++i) {
            int tx = s.x + dx[i], ty = s.y + dy[i];
            if (check(tx, ty) && dist[tx][ty] == -1) {
                dist[tx][ty] = dist[s.x][s.y] + 1;
                q.push({ tx,ty });
            }
        }
    }
    cout << maxn << endl;*/
    return 0;
}
