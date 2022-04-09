#include <iostream>
#include<utility>
#include<algorithm>
#include<vector>
#include<queue>
typedef long long ll;
using namespace std;
ll a[100002];
ll m[200002];
int main()
{
    ll n,b,t,lo,ans=0,t1=0,t2=0;
    cin >> n >> b;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        if (t < b)a[i] = -1;
        else if (t > b)a[i] = 1;
        else { a[i] = 0; lo = i; }
    }
    for (int i = lo + 1; i < n; i++)
    {   
        t1 += a[i];
       // a[i] = a[i] + a[i - 1];
        
        m[t1+n]++;
        if (t1 == 0)ans++;
    }
    for (int i = lo-1; i >=0 ; i--)
    {
        t2 += a[i];
       // a[i] = a[i] + a[i +1];
        ans += m[n - t2];
       // m[n - t2]++;
        if (t2==0)ans++;
    }
    cout << ans+1;
}





