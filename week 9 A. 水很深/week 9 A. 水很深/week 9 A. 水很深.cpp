#include <iostream>
#include<bitset>
#include<stdio.h>
using namespace std;
long long v[400001];
bitset<400001> bs;
bitset<400001> a;

int main()
{  
    int t, n, m;

    a = 1;

    cin >> t;
    while (t--)
    {   
        memset(v,0,sizeof(v));
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
        }
        long long s = 1;
        bs = 1;
        for (int i = 1; i <= n; i++)
        {
            bs |= bs << v[i];
           // cout<<bitset<15>(s);
           // cout  << '\n';
        }
        bs = ((bs >> m) & a);
        cout <<bs[0]<<'\n';
    }
}
//不能直接用s位数不够，要用bitset