#include <iostream>
#include<algorithm>
using namespace std;
long long  x, y, z,t1,t2,t3,ans=0;
bool f = false;
int u[100000];

void bfs(int a)
{
    if (a == 0) {  f = true; return; }
    if (a < 0) return;
    bfs(a - t1);
    bfs(a - t2);
    bfs(a - t3);
}
int main()
{
    cin >> x >> y >> z;
    t1 = x * y, t2 = x * z, t3 = y * z;
    if (z <= 50)
    {
        long long a = 0;
        for (int i = 0; i <= 50; i++)
        {
            for (int ii = 0; ii <= 50; ii++)
            {
                for (int iii = 0; iii <= 20; iii++)
                {
                    a = i * t1 + ii * t2 + iii * t3;
                    u[a] = 1;
                    // cout << u[a] << " ";
                }
            }
        }
        for (long long i = 0; i < 20 * (t1 + t2 + t3) - 1; i++)
        {
            if (u[i] == 0) { ans = max(ans, i); }
        }
        cout << ans;
    }
    else
    {
        for (long long i = 2 * t1 + 1; i <= (t1 + 1) * t1; i++)
        {
            bfs(i);
            if (f == false)
            {
                ans = max(ans, i);
                //   f = true;
            }
            else
            {
                f = false;
            }
        }
        cout << ans;
    }
}
/* 
设最大不能凑出的数为A
当z小于50时直接小范围内枚举
当z较大时，可推得A属于[2*t1+1,max(2*t3-1,(t1+1)*t1)]，（不考虑A小于t1的情形，该情形额外检验）
然后在缩小的范围内验证A是否满足条件
而且似乎A一定是质数，或许可以进一步缩小范围
但最终未AC的原因可能是暴搜没有优化，导致超限
*/