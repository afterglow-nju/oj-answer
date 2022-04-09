#include <iostream>
#include<queue>
//单调队列，与优先队列不同之处：单调队列针对于滑动窗口，通过删除元素得到递增/递减序列，而不是如优先队列一样，元素数量是在不断增加的
using namespace std;
int a[1000001];
int main()
{
    deque<int> q;//q->max qmin->min
    deque<int>qmin;
    deque<int> t;
    int n,k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        while (!qmin.empty() && i - qmin.front() >= k)
        {
            qmin.pop_front();
        }
        while (!qmin.empty() && a[i] <= a[qmin.back()])
        {
            qmin.pop_back();
        }
        qmin.push_back(i);
        t = qmin;
    //    while (!t.empty())
    //    {
    //        cout << t.front() << " ";
    //        t.pop_front();
    //    }
    //    cout << '\n';
        if (i >= k) cout << a[qmin.front()] << " ";
    }
    cout << '\n';
    for (int i = 1; i <= n;i++)
    {
        while (!q.empty() && i - q.front() + 1 > k)
        {
            q.pop_front();
        }
        while (!q.empty() && a[i] >= a[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);
        if (i >= k) cout << a[q.front()]<<" ";
    }
}

