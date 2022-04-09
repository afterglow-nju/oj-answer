#include <iostream>
#include<algorithm>
#include<queue>
using namespace std;
long long w[1001],f[1001][31],v[1001];
priority_queue<int, vector<int>>q,em;
int main()
{
    int T, n, vo,k;
    cin >> T;
    while (T--)
    {
        cin >> n >> vo>>k;
        memset(w, 0, sizeof(w));
        memset(f, 0, sizeof(f));
        memset(v, 0, sizeof(v));
        if (n == 0)cout << 0;
        else
        {
            for (int i = 1; i <= n; i++)
            {
                cin >> v[i];
            }
            for (int i = 1; i <= n; i++)
            {
                cin >> w[i];
            }
            for (int i = 1; i <= n; i++)
            {
                for (int j = vo; j >= 0; j--)
                {   
                    q = em;
                    for (int index = 1; index <= k; index++)
                    {
                        q.push(f[j][index]);
                        if (j >= w[i])
                        {
                            q.push(f[j - w[i]][index] + v[i]);
                        }
                    }
                    int index = 1;
                    for (index = 1; !q.empty()&&index<=k; index++)
                    {   
                        f[j][index] = q.top();
                        q.pop();
                        while (!q.empty()&&q.top() == f[j][index])
                        {
                            q.pop();
                        }
                    }
                    index--;
                    if (index<k)
                    {
                        for (index; index<=k; index++)
                            f[j][index] =0;
                    }
                }
            }
            cout << f[vo][k] << '\n';
        }
    }
}

