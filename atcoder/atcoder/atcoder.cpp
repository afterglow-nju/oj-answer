#include<iostream>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
map<int, int> m;
int a[1000001],b[1000001];

int main()
{	
	deque<int> q,t;
	int n,k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		m[a[i]] = i;
	}
	
	for (int i = 1; i <= k; i++)b[i] = a[i];
	sort(b + 1, b + 1 + k);
	q.push_back(b[1]);
	for (int i = 2; i <= k; i++)
	{
		if (m[b[i]] < m[b[i - 1]])
			continue;
		else
		{
			q.push_back(b[i]);
		}
	}
	cout << q.front() << " ";
	
	for (int i = 2; i + k - 1 <= n; i++)
	{
		while (!q.empty() && m[q.front()] < i)
		{
			//if (q.front() == 24)cout << "A";
			q.pop_front();
		}
		if (!q.empty())
		{
			if (a[i + k - 1] < q.front())
			{
				while (!q.empty())
				{	
				//	if (q.front() == 24)cout << "B";
					q.pop_front();
				}
				q.push_back(a[i + k - 1]);
			}
			else
			{
				while (!q.empty() && a[i+k-1] < q.back())
				{	
					//if (q.back() == 24)cout << "C";
					q.pop_back();
				}
				q.push_back(a[i + k - 1]);
			}
		}
		else
		{
			q.push_back(a[i + k - 1]);
		}
	
		cout << q.front() << " ";
	}
	cout << '\n';
	q.clear();
	q.push_back(b[k]);
	for (int i = k-1; i>=1; i--)
	{
		if (m[b[i]] < m[b[i + 1]])
			continue;
		else
		{
			q.push_back(b[i]);
		}
	}
	cout << q.front()<<" ";
	for (int i = 2; i + k - 1 <= n; i++)
	{
		while (!q.empty() && m[q.front()] <i)
		{	
			//cout << i << " " << q.front() << '\n';
			q.pop_front();
		}
		if (!q.empty())
		{
			if (a[i + k - 1] > q.front())
			{
				while (!q.empty() )
				{	
					//if (q.front() == 5) cout << "B";
					q.pop_front();
				}
				q.push_back(a[i + k - 1]);
			}
			else
			{
				while (!q.empty() && a[i+k-1] > q.back())
				{	
					//if (q.back() == 5) cout << "A";
					q.pop_back();
				}
				q.push_back(a[i + k - 1]);
			}
		}
		else
		{
			q.push_back(a[i + k - 1]);
		}
		cout << q.front()<<" ";
	}
}