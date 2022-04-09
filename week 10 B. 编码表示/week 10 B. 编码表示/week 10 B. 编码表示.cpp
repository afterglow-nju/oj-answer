#include <iostream>
#include<algorithm>
#include<queue>
using namespace std;
long long a[12];
priority_queue<long long, vector<long long>, greater<long long>>q;
//优先队列默认从大到小排  greater<long long>从小到大
//hdu5884
int main()
{
	long long n, k;
	cin >> n >> k;
	long long point = 0, num = n;
	while (num > k)
	{
		num = num - k + 1;
		point++;
	}
	point++;
	int pre = (n - 1) % (k - 1);
	if (pre != 0)pre++;
	//很重要，构造k叉树，if pre！=0 说明不能正好构成k叉树，就先将pre个数合起来，而且最先和起来，这样代价最小
	for (long long i = 1; i <= n; i++)
	{
		long long t;
		cin >> t;
		q.push(t);
	}
	long long ans = 0;
	long long t = 0;

	if (k == 2)
	{

		while (!q.empty())
		{
			long long a = 0, b = 0;
			while (q.size() > 1)
			{
				a = q.top();
				q.pop();
				b = q.top();
				q.pop();
				q.push(a + b);
				ans += a + b;
			}
			while (!q.empty())
			{
				q.pop();
			}
		}
		cout << ans;
	}
	else
	{
		for (long long i = 1; i <= pre; i++)
		{
			a[i] = q.top();
			q.pop();
		}
		for (long long i = 1; i <= pre; i++)
		{
			t += a[i];
			ans += a[i];
		}
		q.push(t);
		t = 0;
		memset(a, sizeof(a), 0);


		for (int j = 2; j <= point; j++)
		{
			for (long long i = 1; i <= k; i++)
			{
				a[i] = q.top();
				q.pop();
			}
			for (long long i = 1; i <= k; i++)
			{
				t += a[i];
				ans += a[i];
			}
			q.push(t);
			t = 0;
			memset(a, sizeof(a), 0);
		}
		while (!q.empty())
		{
			//cout<<q.top()<<" ";
			q.pop();
		}

		//   4 3 
		//   1 2 3 4
		//5 9 12 13 16 45
		cout << ans;
	}
}
/*
#include <iostream>
#include<algorithm>
#include<queue>
using namespace std;
long long a[12];
priority_queue<long long, vector<long long>, greater<long long>>q;
//优先队列默认从大到小排  greater<long long>从小到大
//hdu5884
int main()
{
	long long n, k;
	cin >> n >> k;
	long long point = 0, num = n;
	while (num > k)
	{
		num = num - k + 1;
		point++;
	}
	point++;
	int pre = (n - 1) % (k - 1);
	if (pre != 0)pre++;
	//很重要，构造k叉树，if pre！=0 说明不能正好构成k叉树，就先将pre个数合起来，而且最先和起来，这样代价最小
	for (long long i = 1; i <= n; i++)
	{
		long long t;
		cin >> t;
		q.push(t);
	}
	long long ans = 0;
	long long t = 0;
	if (k == 2)
	{

		while (!q.empty())
		{
			long long a = 0, b = 0;
			while (q.size() > 1)
			{
				a = q.top();
				q.pop();
				b = q.top();
				q.pop();
				q.push(a + b);
				ans += a + b;
			}
			while (!q.empty())
			{
				q.pop();
			}
		}
		cout << ans;
	}
	else
	{
		for (long long i = 1; i <= pre; i++)
		{
			a[i] = q.top();
			q.pop();
		}
		for (long long i = 1; i <= pre; i++)
		{
			t += a[i];
			ans += a[i];
		}
		q.push(t);
		t = 0;
		memset(a, sizeof(a), 0);


		for (int j = 2; j <= point; j++)
		{
			for (long long i = 1; i <= k; i++)
			{
				a[i] = q.top();
				q.pop();
			}
			for (long long i = 1; i <= k; i++)
			{
				t += a[i];
				ans += a[i];
			}
			q.push(t);
			t = 0;
			memset(a, sizeof(a), 0);
		}
		cout << ans;
	}
}




*/


