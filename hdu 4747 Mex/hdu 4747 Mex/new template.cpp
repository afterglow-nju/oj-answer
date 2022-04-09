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
struct node
{
	long long key;
	long long index;
	friend bool operator <(const node& a, const node& b)
	{
		return a.key < b.key;
	}
};
node a[200001];
long long b[200001];
int id = 0;
long long solve(int left, int right, int mid)
{
	if (left == right) return 0;
	else
	{
		long long tem=(right - mid + 1)* (mid - left);
		
	}
}
long long solve_2(int left, int right)
{	
	if (left > right) return 0;
	long long tem = b[left];
	int index = left;
	for (int i = left+1; i <= right; i++)
	{
		if (tem > b[i])
		{
			tem = b[i];
			index = i;
		}
	}
	long long ans= (right - index + 1) * (index - left+1)*b[index];
	return ans + solve_2(left, index - 1) + solve_2(index + 1, right);

}
int main()
{	
	int n;
	while (1)
	{
		cin >> n;
		if (n == 0) break;
		for (int i = 1; i <= n; i++)
		{	
			cin >> b[i];
			//cin >> a[i].key;
		//	b[i] = a[i].key;
			//a[i].index = i;
		}
		cout<<solve_2(1, n)<<'\n';
	}
}






