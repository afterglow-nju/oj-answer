#include <iostream>
#include<math.h>
#include<algorithm>
#include<iomanip>
using namespace std;
double m, n, sum = 0, a = 0;
int main()
{
	cout << sizeof(int);
	cin >> n >> m;
	for (double i = 1; i <= m; i = a + 1)
	{
		a = min(n / (n / i), m);
		sum +=  (n / i) * (a - i + 1);
	}
	cout << fixed<<setprecision(0)<<sum;

}


