#include <iostream>
#include<algorithm>
using namespace std;
int a_ge[50001], a_zh[50001], b_ge[50001],b_zh[50001],d[50001][1001];
int ma(int a, int b, int c)
{
    int s[3];
    s[0] = a, s[1] = b, s[2] = c;
    sort(s,s+3);
    return s[2];
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a_ge[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a_zh[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b_ge[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b_zh[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 0; j--)
        {
          //  bool f = true; 
            d[i][j] = d[i - 1][j];
            if (j >= a_ge[i])
            {
                d[i][j] = max(d[i][j], d[i - 1][j - a_ge[i]] + a_zh[i]); //f = false;
            }
            if (j >= b_ge[i])
            {
                d[i][j] = max(d[i][j], d[i - 1][j - b_ge[i]] + b_zh[i]); //f = false;
            }
           // if (f)
            /*
            if (j >= a_ge[i] && j >= b_ge[i])
            {
                d[i][j] = ma(d[i - 1][j], d[i][j - a_ge[i]] + a_zh[i], d[i][j - b_ge[i]] + b_zh[i]);
            }
            else if (j < a_ge[i] && j >= b_ge[i])
            {
                d[i][j] = max(d[i - 1][j], d[i][j - b_ge[i]] + b_zh[i]);
            }
            else if (j < b_ge[i] && j >= a_ge[i])
            {
                d[i][j] = max(d[i - 1][j], d[i][j - a_ge[i]] + a_zh[i]);
            }
            else d[i][j] = d[i - 1][j];
2 4
1 2
50 52
3 4
101  100
            */
        }
    }
    cout << d[n][m];
}
    /*
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << d[i][j] << " ";
        }
        cout << '\n';
    }
}*/

//超出的全部置0
