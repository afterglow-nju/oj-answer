#include <iostream>
#include<queue>
#include<algorithm>
typedef long long ll;
using namespace std;
pair<int, int>tem;
struct com
{
    bool operator()(const pair<int, int>& p, const pair<int, int>& q)
    {
        return p.first <q.first;
    }
};
priority_queue< pair<int,int>,vector<pair<int,int>>,com> q;

ll n, k, m[100001],a[100001];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        m[i] = t;
    }

    for (int i = 2; i <= n; i++)
    {   
        tem.first = m[i] - m[i - 1];
        tem.second = tem.first;
        q.push(tem);
    }
    /*
    while (!q.empty())
    {
        cout << q.top().first << " " << q.top().second<< '\n';
        q.pop();
    }*/
    int a1 = 0;
    pair<int, int>t;
    for (int i = k; i > 0; i--)
    {
        /*
        if (q.top().second ==t.second )
        {   
            pair<int, int>tt = q.top();
            q.pop();
            //di++;
            int divide = (tt.second - 1) / tt.first + 2;
            a1 = (tt.second - 1) / di + 1;
            q.push({ a1, tt.second });
        }
        else
        {
            di = 2;
            t = q.top();
            q.pop();
            a1 = (t.first - 1) / di + 1;//向上取整
            q.push({ a1,t.second });
            //cout << t<<" "<<a1 << " ";\
            
            5 6
9 10 20 26 30
            
            */
        
        t = q.top();
        q.pop();
        int divide = (t.second - 1) / t.first + 2;
        a1 = (t.second - 1) / divide + 1;
       // cout << a1 << " " << t.second<<'\n';

        q.push({ a1, t.second });
    }
    
    cout << q.top().first;
  
}