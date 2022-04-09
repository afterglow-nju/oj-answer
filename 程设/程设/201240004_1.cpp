#include<iostream>
using namespace std;
int f(int a);
int k;
int main()
{
	int n;
	cin >> n;
	int sum = 0;
	cout << f(n);
	return 0;
}
int f(int a)
{	
	if (a == 1) return 1;
	if (a == 2) return 2;
	else 
		if (a % 2 == 0) return  1 + f(a / 2);
		else return  1+f(a-1/2);
}
