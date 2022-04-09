#include <iostream>
#include<queue>
#include<algorithm>

typedef long long ll;
pair<int, int> tem;
struct com
{
    bool operator()(const pair<int, int>& p, const pair<int, int>& q)
    {
        return p.first > q.first;
    }
};
priority_queue< pair<int, int>, vector<pair<int, int>>, com> q;

ll n, k, m[100001], a[100001];
using namespace std;
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
    int di = 2, a1 = 0;
    for (int i = k; i > 0; i--)
    {
        if (q.top().first == a1)
        {
            pair<int, int>t = q.top();
            q.pop();
            di++;
            a1 = (t.second - 1) / di + 1;
            q.push({ a1, t.second });
        }
        else
        {
            di = 2;
            pair<int, int>t = q.top();
            q.pop();
            a1 = (t.first - 1) / di + 1;//向上取整
            q.push({ a1,t.second });
            //cout << t<<" "<<a1 << " ";
        }
    }

    cout << q.top();

}