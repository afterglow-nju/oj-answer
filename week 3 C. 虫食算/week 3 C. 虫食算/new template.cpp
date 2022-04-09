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
int n;
int a[26], b[26], c[26], used[26],order[26],num[26];
void in(int tem[])
{	
	char t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		tem[i] = t - 'A';
	}
	return;
}
bool isok()
{
	int x = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		int A = num[a[i]], B = num[b[i]], C = num[c[i]];
		if (A == -1 || B == -1 || C == -1)return false;
		if ((A + B+x) % n != C)return false;
		x = (A + B+x) / n;
	}
	return true;
}
bool check()
{
	if (num[a[0]] + num[b[0]] >= n)return false;
	for (int i = n - 1; i >= 0; i--)
	{
		int A = num[a[i]], B = num[b[i]], C = num[c[i]];
		if (A == -1 || B == -1 || C == -1)continue;
		 if (((A + B) % n != C) && ((A + B + 1) % n != C))
		{
			//cout << A << " " << B << " " << C << '\n';
			return false;
		}
	}
	return true;
}
//bool f = false;

void dfs(int x)
{
	//	if (f)return;
		//cout << x << '\n';
	if (check() == false)return;
	if (x == n)
	{
		//f = true;
		
		if (isok())
		{

			for (int i = 0; i < n; i++) cout << num[i] << " ";
			exit(0);
			return;
		}
	}

	for (int i = n - 1; i >= 0; i--)
	{
		if (used[i] == false)
		{
			num[order[x]] = i;
			used[i] = true;
			/*if (num[0] == 1)
			{
				for (int i = 0; i < n; i++) cout << num[i] << " ";
				cout << '\n';
			}*/
			dfs(x + 1);

			num[order[x]] = -1;
			used[i] = false;
		}
	}
}
int Index = 0;
void getnext(int t)
{
	if (used[t] == false)
	{
		order[Index++] = t;
		//cout << t << " ";
		used[t] = true;
	}
}
int main()
{
	cin >> n;
	char t;
	in(a); in(b); in(c);
	//for (int i = 0; i < n; i++)cout << c[i] << " ";

	for (int i = n - 1; i >= 0; i--)
	{
		getnext(a[i]);
		getnext(b[i]);
		getnext(c[i]);
		num[i] = -1;
	}
	//for (int i = 0; i < n; i++)cout<<order[i]<<" ";
	memset(used, 0, sizeof(used));
	dfs(0);
	//for (int i = 0; i < n; i++) cout << num[i] << " ";
	
}






