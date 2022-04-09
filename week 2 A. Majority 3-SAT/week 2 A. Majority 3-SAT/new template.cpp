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
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stdbool.h>
using namespace std;

const int SIZE = 100010;
bool bridge[SIZE * 2];
int head[SIZE], ver[SIZE * 2], Next[SIZE * 2];
int dfn[SIZE], low[SIZE];
int n, m, tot, num;

void add(int x, int y)
{
    ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
}
void tarjan(int x, int in_edge)
{
    dfn[x] = low[x] = ++num;
    for (int i = head[x]; i; i = Next[i])
    {
        int y = ver[i];
        if (!dfn[y])
        {
            tarjan(y, i);
            low[x] = min(low[x], low[y]);
            if (low[y] > dfn[x])
                bridge[i] = bridge[i ^ 1] = true;
        }
        else if (i != (in_edge ^ 1))
            low[x] = min(low[x], dfn[y]);
    }

}
int main()
{
    int T;
    cin >> T;
    int a[6];
    while (T--)
    {
        int n, k;
        cin >> k >> n;
       // int delt = 2 * n;
        tot = 1;//vertex n edge m
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 6; j=j+2)
            {
                int t;
                cin >> t;
                if (t < 0)
                {
                    a[j+1] = abs(t);
                    a[j] =abs(t)+k;
                }
                else
                {
                    a[j + 1] = t + k;
                    a[j] = t;
                }
                
            }
            add(a[1], a[2]);
            add(a[3], a[0]);
            add(a[3], a[4]);
            add(a[5], a[2]);
            add(a[1], a[4]);
            add(a[5], a[0]);
        }
        for (int i = 1; i <= 2*k; i++)
            if (!dfn[i]) tarjan(i, 0);
        for (int i = 2; i < tot; i += 2)
            cout<<bridge[i]<<" "
            if (bridge[i])
            {
                //cout << "A";
                int a = ver[i ^ 1], b = ver[i];
               // cout << "begin  " << a << " " << b << "end1" << '\n';
                if (a > k)
                {
                    a -= k;
                }
                if (b > k)
                {
                    b -= k;
                }
                //cout << a << " " << b << '\n';
                //cout <<"begin" <<a <<" "<< b<<"end2"<<'\n';
            }
                
    }
}


