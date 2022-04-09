#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long a[100002], b[100002], d[100002], xia[100002];
int main()
{
	int n, c = 1;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[i] = a[i];
		d[i] = 1;
	}
	int k = 1;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] < 21474836489)
		{
			d[i] = k;
			for (int j = i + 1; j <= n; j++)
			{
				if (a[j] == a[i])
				{
					d[i] = k; d[j] = k;
					a[j] = 21474836489;

				}
			}
			k++; a[i] = 21474836489;
		}
	}
	for (int i = 1; i <= n; i++) cout << d[i] << " ";
}