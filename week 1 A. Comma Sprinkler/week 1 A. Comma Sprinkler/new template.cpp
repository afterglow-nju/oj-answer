#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<bitset>
#include<stack>
#include<utility>
#include<iomanip>
#include<vector>
#include<math.h>
#include<string>
#include<stdio.h>
#include<limits>
#include<set>
using namespace std;

int main()
{
	vector<string> s;
	//for (string t; cin >> t;)
	string t;
	getline(cin, t);
	string tem;
	for (int i = 0; i < t.length(); i++)
	{
		//cout << i << " ";
		int cnt = 0;
		if (t[i] == ' ')
		{
			s.push_back(tem);
			tem.clear();
		}
		else
		{
			tem += t[i];
		}
	}
	s.push_back(tem);
	//cout << "A";
	vector<bool> vis(s.size(), 0);
	set<string>pre, suf;
	for (int i = 0; i < s.size(); i++)//s.size�ǵ�������
	{
		//cout << s[i];
		if (s[i].back() == '.')
		{
			vis[i] = 1;
			s[i].pop_back();//ɾ�����
		}
		else if (s[i].back() == ',')
		{
			s[i].pop_back();
			pre.insert(s[i]);
		}
	}
	//cout << '\n';
	map<string, set<string>>to, from;
	for (int i = 0; i < s.size()-1; i++)
	{
		if (!vis[i])
		{
			to[s[i]].insert(s[i + 1]);
			from[s[i + 1]].insert(s[i]);
		}
	}
	queue<pair<int, string>>q;
	for (auto i : pre)q.push({ 0,i });
	while (!q.empty())
	{
		int op; string t; tie(op, t) = q.front(); q.pop();
		if (op == 0)
		{
			for (auto i : to[t])
			{
				if (!suf.count(i))
				{
					suf.insert(i);
					q.push({ 1,i });//��1��ǳ����ʣ�������Щ����ǰ���ж���
				}
			}
		}
		else
		{
			for (auto i : from[t])
			{
				if (!pre.count(i))//��ֹ�ظ�
				{
					pre.insert(i);
					q.push({ 0,i });
				}
			}
		}
		
	}
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i];
		if (vis[i])cout << ".";
		else if (pre.count(s[i]))cout << ",";
		cout << " ";
	}
	

}






