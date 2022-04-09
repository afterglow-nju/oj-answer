#include<iostream>
#include<algorithm>
using namespace std;
int a[100000],b[100000],c[100000],d[100000];
int main()
{
	int n, temp, k = 1;
	cin >> n;
	for (int i = 0; i <= n - 1; i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a+1, a + n);
	for (int i = 0; i <= n-1; i++) cout << a[i];
	temp = a[0];
	for (int i = 0; i <= n - 1; i++)
	{
		if (temp != a[i]) {
			k++;
			temp = a[i];
		}

	}
	
	unique(a, a + n);
	for (int i = 0; i <= k - 1; i++) {
		c[i] = a[i];
	}
//	for (int i = 0; i <= k- 1; i++) cout << c[i];

	for (int j = 0; j <= k - 1; j++)
	{
		for (int i = 0; i <= n - 1; i++)
		{
			if (b[i] == c[j]) d[i] = j + 1;
		}
	}
	//for (int i = 0; i <= n-1; i++) cout << d[i]<<" ";
}