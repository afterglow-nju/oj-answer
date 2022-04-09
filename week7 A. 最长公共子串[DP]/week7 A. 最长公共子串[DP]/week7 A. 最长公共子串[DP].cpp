#include <iostream>
using namespace std;
char a[5001], b[5001];
int c[5001][5001],sum[5001];
int main()
{
    
    int l_b=0,l_a=0;
    gets_s(a);
    gets_s(b);
    int ans = 0,max=0;
    while (b[l_b] != '\0')
    {
        l_b++;
    }
    while (a[l_a] != '\0')l_a++;
    for (int i = l_a - 1; i >= 0; i--)a[i + 1] = a[i];
    for (int i = l_b - 1; i >= 0; i--)b[i + 1] = b[i];
    for (int t = 1; t <= l_a; t++)
    {
       
            for (int j = 1; j <= l_b; j++)
            {
                //if (j + t - 1 <= l_b)
                {
                    if (b[j + t - 1] == a[t]) sum[j]++; else sum[j] = 0;
                }
                if (sum[j] > ans) ans = sum[j];
      //          cout << sum[j] << " ";
            }
       
      //cout << '\n';
        cout << ans << " ";
    }
//    for (int t = 1; t <= l_b; t++)cout << sum[t] << " ";
}

//01101
//11110
//为什么不对？下面的是对的
/*

#include<iostream>

using namespace std;
const int maxn = 5000 + 7;

char a[maxn], b[maxn];
int dp[maxn][maxn];

int main()
{
    gets_s(a);
    gets_s(b);
    int l_a=strlen(a);
    int l_b = strlen(b);
    int max = 0;
    for (int i = 1; i <= l_a; i++)
    {
        for (int j = 1; j <= l_b; j++)
        {
            if (a[i - 1] == b[j - 1])dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = 0;
            if (dp[i][j] > max)max = dp[i][j];
        }
        cout << max << " ";
    }

}


*/