#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long merge_count(int b, int e, int m, vector<int>& a)
{
    long long sum = 0, k = 0, i = 0;
    vector<int>t1(m - b + 1); vector<int>t2(e - m);
    for (int i = 0; i < m - b + 1; i++)t1[i] = a[i+b];
    for (int i = 0; i < e - m; i++)t2[i] = a[i + m + 1];
 /*   for (int i = 0; i < m - b + 1; i++)
    {
        for (int j = 0; j < e - m; j++)
        {
            if (t1[i] > t2[j])sum++;
        }
    }*/
       sort(t1.begin(), t1.end()); sort(t2.begin(), t2.end());
      // for (int i = 0; i < m - b + 1; i++)
       while(i<m-b+1 && k<e-m)
       {
           if (t1[i] <= t2[k])
           {
               i++;
           }
           else
           {
               sum += m - b + 1 - i;
               k++;
           }
       }
      
    return sum;
}
long long merge(int b, int e, vector<int>& a)
{
    if (b == e) return 0;
    int m = (b + e) / 2;
    long long sum = 0;
    sum+=merge(b, m, a);
    sum+=merge(m + 1, e, a);
    sum+=merge_count(b, e, m, a);
    return sum;
}

int main()
{
    int n,t=0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> t;
        a[i] = t;
    }
  cout<<  merge(0, n - 1, a);
}


