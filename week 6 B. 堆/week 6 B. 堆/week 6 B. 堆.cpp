#include <iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> a;
int main()
{
	int n;
	cin >> n;
	//vector<int>a;
	while (n--)
	{
		string s;
		cin >> s;
		//s[0] = 1;
		char i = s[0];
		if (s.size() == 1)
		{	
		//	for (auto i : s)
			
				if (i == '-')
				{
					if (!a.empty())
					{
						a.pop();
					}
				}
				else if (i == '?')
				{
					if (!a.empty())
					{
						cout << a.top() << '\n';
						//a.pop();
					}
					else
					{
						cout << "Error." << '\n';
					}
				}
			
		}
		else
		{	
			int x = 0;
			for (auto i : s)
			{
				if (i != '+')
				{
					int t = i - '0';
					x = x * 10 + t;
				}
			}
			a.push(x);
			
		}
		//sort(a.begin(), a.end());
	}
}
//要用优先队列，也就是堆，不要用vector然后sort
//明明人家题目名字就叫堆，为什么一开始还要用数组，我是小傻子，嘿嘿嘿
//小傻子想找女朋友了
//女朋友也想找小傻子了
//傻瓜吉姆佩尔

