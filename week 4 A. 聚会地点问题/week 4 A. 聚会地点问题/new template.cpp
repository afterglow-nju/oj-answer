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
typedef long long ll;
const int maxn=1e5;
ll disx[maxn], disy[maxn];
int main()
{	
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> disx[i] >> disy[i];
	}
	sort(disx, disx + n);
	sort(disy, disy + n);
	if (n % 2)
	{
		cout << disx[n >> 1] << " " << disy[n >> 1];
	}
	else
	{
		cout << disx[(n >> 1) - 1] << " " << disy[(n >> 1) - 1];
	}
}






