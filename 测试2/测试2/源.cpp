#include <iostream>
using namespace std;
int main()
{
	 int a = 1;
	int b;
	for (a; a <= 10; a++) {
		b = (a << 3);
		cout << b << '\n';
	}
}