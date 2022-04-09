#include<iostream>
#include<algorithm>
using namespace std;
int f(int n,int a);
int k;
int n;
//int b[10] = { 0 };
int main()
{
	
	cin >> n;
	if (n == 0) cout << "10";
	else
	cout << f(n, 1) + f(n, 2)+ f(n, 3) +f(n, 4) + f(n, 6) + f(n, 7) +f(n, 8) + f(n, 9) + f(n, 0);
}
int f(int n,int a)
{
	if (n == 0) return 1;
	if (a == 1) { return f(n-1,6) + f(n-1,8); }
		if (a == 2) { return f(n-1,7) + f(n-1,9); }
		if (a == 3) { return f(n-1,4) + f(n - 1, 8); }
		if (a == 4) { return f(n - 1, 3) + f(n - 1, 9) + f(n - 1, 0); }
		if (a == 6) {   return f(n - 1, 7) + f(n - 1, 1) + f(n - 1, 0); }
		if (a == 7) {  return f(n - 1, 2) + f(n-1,6); }
		if (a == 8) {   return f(n - 1, 1) + f(n - 1, 3); }
		if (a == 9) {  return f(n - 1, 2) + f(n - 1, 4); }
		if (a == 0) {    return f(n - 1, 4) + f(n - 1, 6); }
	
}
