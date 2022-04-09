#include <iostream>
using namespace std;
int temp = 0;
int f(int n,int m)
{	
	//if (m == 1) return n;
	//if (n == 1) return 1;
	if (m <= 0 || n <= 0) return 0;
	if (n == m) return 1 + f(n, m-1);
	if (n < m) return f(n, n);
	else return f(n - m, m) + f(n, m - 1);
}



int main()
{
	//cout << f(3, 2);//<<f(3,1)<<f(3,0);
	int n;
	cin >> n;
    cout << f(n,n);
}

