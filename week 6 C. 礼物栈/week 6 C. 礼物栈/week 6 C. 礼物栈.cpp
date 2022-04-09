#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int a[100001], b[100001],c[100001];
int main()
{   
    int n, m;
    cin >> n >> m;
  //  vector<int>a,b;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {   
        int t;
        cin >> t;
        a[t] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    int mark = 0;
    for (int i = 1; i <= m; i++)
    {
        c[i] = a[b[i]];
        mark = max(mark, c[i]);
        // cout << c[i] << " ";
        if (c[i] >= mark)
        {   
            //cout << i << " " << c[i] << " " << ans;
            ans =ans+ 2 * (c[i] - i) + 1;
        }
        else
        {
            ans ++;
        }
       // cout << i << " " << c[i] << " " << ans<<'\n';
    }
    cout << ans;
    
    
}
//孙哥yyds!!!!
//令a数组下标表示第几个

