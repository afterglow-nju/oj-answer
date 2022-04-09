#include <iostream>
#include<queue>
using namespace std;
typedef long long ll;


ll aa[100005], a[100005], s = 0;//aa not important a前缀和
struct node
{

    ll sum;
    ll l, r;
};
priority_queue<node>q;//m ->a q->ans
priority_queue<pair<ll, ll>>m;
bool operator <(node a, node b)//why
{
    if (a.sum != b.sum)return a.sum > b.sum;
    if (a.l != b.l)return a.l < b.l;
    else return a.r < b.r;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) { cin >> aa[i]; s += aa[i]; a[i] = s; }
    pair<ll, ll> b[100];
    int num = 0;
    for (int i = 1; i <= n; i++)
    {

        if (m.size() < k) m.push(make_pair(a[i - 1], i));
        else if (a[i - 1] < m.top().first) { m.pop(); m.push(make_pair(a[i - 1], i)); }//i-1?
        while (!m.empty())
        {
            b[++num] = m.top();
            m.pop();

            if (q.size() < k) q.push(node{ a[i] - b[num].first,b[num].second,i });
            else if (node{ a[i] - b[num].first,b[num].second,i } < q.top())
            {
                q.pop();
                q.push(node{ a[i] - b[num].first,b[num].second,i });
            }


        }
        for (; num; num--)
        {
            m.push(b[num]);
        }
    }
    cout << q.top().l << " " << q.top().r;
}

/*
#include <iostream>
#include<queue>
using namespace std;
typedef long long ll;


ll aa[100005],a[100005],s=0;//aa not important a前缀和
struct node
{

    ll sum;
    ll l, r;
};
priority_queue<node>m, q;//m ->a q->ans

bool operator <(node a, node b)//why
{
    if (a.sum != b.sum)return a.sum > b.sum;
    if (a.l != b.l)return a.l < b.l;
    else return a.r < b.r;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) { cin >> aa[i]; s += aa[i]; a[i] = s; }
    node b[100];
   int num = 0;
    for (int i = 1; i <= n; i++)
    {

        if (m.size() < k) m.push(node{ a[i-1],i,0 });
        else if (a[i-1] < m.top().sum) { m.pop(); m.push(node{ a[i-1],i,0 }); }//i-1?
        while (!m.empty())
        {
            b[++num]= m.top();
            m.pop();

            if (q.size() < k) q.push(node{ a[i] - b[num].sum,b[num].l,i });
            else if (node{ a[i] - b[num].sum,b[num].l,i } < q.top())
            {
                q.pop();
                q.push(node{ a[i] - b[num].sum,b[num].l,i });
            }


        }
        for (; num; num--)
        {
            m.push(b[num]);
        }
    }
    cout << q.top().l << " " << q.top().r;
}



*/