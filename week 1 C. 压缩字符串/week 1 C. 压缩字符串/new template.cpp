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
using namespace std;
string unzip(string s)
{
	if (s.length() == 0)return s;
	int sum = 0, i = 0;
	string ans;
	//cout << "??";
	//cout << i << " " << s.length();
	while (i < s.length())
	{	//3{a2{d}}
		if (s[i] >= '0' && s[i] <= '9')
		{
			sum = sum * 10 + (s[i] - '0');
			i++;
			cout << i << " ";
		}
		else if (s[i] == '{')
		{
			cout << "!!";
			int right = i + 1;
			int time = 1;
			while (right++ < s.length())//这里left已经固定住了，不像第一次left还在变
			{
				if (s[right] == '{')
				{
					time++;
				}
				else if (s[right] == '}')
				{
					time--;
				}
				if (time == 0)
				{
					break;
				}
			}
			cout << i << " " << right<<'\n';
			string subs = s.substr(i + 1, right - 1 - i);
			cout << subs;
			string tem = unzip(subs);
			cout << "here?";
			for (int j = 1; j <= sum; j++)
			{
				ans.append(tem);
			}
			sum = 0; i = right + 1;
		}
		else
		{
			ans.append(s.substr(i++,1));
		}
	}
	cout << ans << '\n';
	return ans;
}
int main()
{
	string tem;
	cin >> tem;
	cout << unzip(tem);
}
	/*
	string a("{"), b("}");
	while (1)
	{
		//if ((left = tem.rfind('{') != string::npos))
		int leftnum = 0, rightnum = 0;
		for (int i = 0; i < tem.length(); i++)
		{
			//cout << tem.compare(i, 1, a) << " ";

			if (tem.compare(i, 1, a) == 0)
			{
				//	cout << "???";
				leftnum++;
				left = i;
			}
			else if (tem.compare(i, 1, b) == 0)
			{
				rightnum++;
				right = i;
			}
			if ((leftnum - rightnum == 1 || leftnum == rightnum) && leftnum != 0 && rightnum != 0)
			{
				break;
			}
		}
		//cout << "nmsl";
		//right = tem.rfind('}');
		if (leftnum == 0)break;
		cout << left << " " << right;
		int num = tem[left - 1] - '0';
		string s;
		s.assign(tem, left + 1, right - 1 - left);
		tem.erase(left - 1, right - left + 2);
		for (int i = 1; i <= num; i++)
		{
			tem.insert(left - 1, s);
		}//cout << num << '\n';
		cout << tem << '\n';
		//a2[12]

	}
	cout <<"???"<< tem;
}
	
	*/






