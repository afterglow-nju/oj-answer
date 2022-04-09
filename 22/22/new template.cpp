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
long long a[500001];
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++)
		{
			bool f = true;
			int j = n;
			for ( j = n; j >i; j--)
			{
				if (a[j] < a[i])
				a{	
					f = false;
					break;
				}
			}
			if (f)cout << -1 << " ";
			else cout << j - i - 1 << " ";
		}
		cout << '\n';
	}
}






