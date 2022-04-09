#include <iostream>
#include<utility>
#include<algorithm>
#include<vector>
//pair<long long ,long long> w[100001];
//pair<int, int> w;

using namespace std;
struct tim
{
    long long kind;
    long long t;
}w[200010];
bool com(tim a, tim b)
{   
  //  if (a == b) return false;
    if (a.t == b.t) return a.kind < b.kind;
    return a.t < b.t;
}

int main()
{
    int n;
    cin >> n;
    long long ss, ee;
    int ans = 0;

    for (int i = 1; i <= n; i++)
    {   
        cin >> ss >> ee;
        w[i].kind = -1;
        w[i].t = ee;
        w[i + n].kind = 1;
        w[i + n].t = ss;
    }
    sort(w+1, w+2*n+1, com);
    int icu = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        if (w[i].kind == -1)icu--;
        else icu++;
        ans = max(icu, ans);
    }
    cout <<ans ;
   
}

