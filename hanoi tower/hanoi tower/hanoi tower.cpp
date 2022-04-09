#include<iostream>
using namespace std;
void hanoi(char A, char B, char C, int n)
{
	if (n == 1)
		cout << "move " <<1<<" from "<< A << " to " << B<<'\n';
	else
	{
		hanoi(A, C, B, n - 1);
		cout << "move " <<n<< " from "<<A << " to " << B<<'\n';
		hanoi(C, B, A, n - 1);
	}
}
void hanoi(int n)
{
	hanoi('A', 'B', 'C', n);
}
int main()
{
	int n;
	cin >> n;
	hanoi(n);
}