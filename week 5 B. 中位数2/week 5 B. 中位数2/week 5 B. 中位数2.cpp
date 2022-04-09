#include <iostream>
#include<queue>
#include<algorithm>
typedef long long ll;
using namespace std;
ll a[100001];
priority_queue<ll>l;
priority_queue<ll,vector<ll>,greater<ll>>r;
void make_balance()
{
	if (l.size() > r.size()+1)//不能l.size-r.size>1!!!!!!!!!!!!!!!!!!!!!因为size是unsigned int如果是负数就会溢出，就肯定大于1 如1-2=41234123521351
	{
		r.push(l.top());
		l.pop();
	}
	else if (r.size() > l.size())
	{
		
		l.push(r.top());
		r.pop();
	}

}
void find(int i)
{	
	if (l.empty()&&r.empty())
	{
		l.push(a[i]);
		return;
	}
	else
	{
		ll t = l.top();
		if (a[i] > t)
		{
			r.push(a[i]);
		}
		else
		{
			l.push(a[i]);
		}
		make_balance();
	}
}

int main()
{
	ll n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{	
		cin >> a[i];
		find(i);
		if (i % 2 == 1)
		{
			cout << l.top()<<'\n';
		}
	}
}

