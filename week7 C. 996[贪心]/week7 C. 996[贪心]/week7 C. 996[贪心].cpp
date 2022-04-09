#include <iostream>
#include<utility>
#include<algorithm>
using namespace std;
bool com(pair<int, int>a, pair<int, int>b)
{
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

 pair<int, int >a[100001];
int main()
{   
    int n,sum=0;
    cin >> n;
    int t = n;
   
    for (int i=1;i<=n;i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n+1, com);
    
     int j = 1;
    while (t > 0)
    {
        //bool f = false;
        int s = 0;
        
        for (; j <= n; j++)
        {
            if (a[j].second != -1)
            {
                s = a[j].second; 
                a[j].second = -1;
                a[j].first = -1;
                t--;
                break;
            } 
        }
        for (int i = j-1; i <= n; i++)
        {
            if (a[i].first >= s)
            {
                s = a[i].second;
                t--; //cout << "A";
                a[i].second = -1;
                a[i].first = -1;
            }
        }
        sum++; 
    }
    cout << sum;
   
}

