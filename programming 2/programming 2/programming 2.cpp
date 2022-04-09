#include<iostream>
#include<math.h>
using namespace std;
long long f(int a, int m);
long long sum = 0;
int main()
{
	int m, a;
	cin >> a >> m;
	cout << f(a, m) % 12345 % 12345 % 12345 % 12345;
	return 0;
}
long long f(int a, int m)
{
	if (m == 0) return 1;
	return f(a, m - 1) * a ;
}