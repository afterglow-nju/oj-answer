
#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
	long long num=1;
	int n,jishu=0;
	int a[10];
	cin >> n;
	for (int i = 1; i <= n; i++) num *= i;
	bool flag = true;
	for (int i = 1; i <= n; i++) a[i] = i;
	while (flag==true)
	{
		for (int i = 1; i <= n; i++) cout<<a[i]<<" ";
		next_permutation(a+1, a + n+1);
		
		jishu++;
		if (num == jishu) flag=false;
		cout << '\n';
	}
}

