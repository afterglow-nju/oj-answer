#include <iostream>
#include<queue>
using namespace std;
int a[21];
long long f[1 << 20];
bool v[1 << 20];
int n;
bool check(int i,long long sta)
{
    if (i>0)
    {
        if (a[i] > a[i-1])
        {
            if (!(sta & (1 << i-1)))
                return 0;
        }
        else
        {
            if ((sta & (1 << i-1)))
                return 0;
        }
    }
    if (i < n - 1)
    {
        if (a[i] > a[i + 1])
        {
            if (!(sta & (1 << i+1)))
                return 0;
        }
        else
        {
            if ((sta & (1 << i+1)))
                return 0;
        }
    }


    return 1;

}
int main()
{   
    //if (v[1])cout << "AA";
    cin >> n;
    for (int i = 0; i < n; i++)cin >> a[i];
    f[0] = 1;//why??
    queue<long long> q;
    q.push(0);
    while (!q.empty())
    {
        long long sta = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (!(sta & (1 << i)) && check(i,sta)) //attention i don't know clearly
            {
                f[sta | (1 << i)] += f[sta];
                if (v[sta | (1 << i)]==false)
                {
                    q.push(sta | (1 << i));
                    v[sta | (1 << i)] = true;
                }
            }
        }
       
    }
 cout << f[(1 << n)-1];
}

