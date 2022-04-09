#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{	
	string n, m;
	cin >> n >> m;
//	n = " " + n;
//	m = " " + m;
	int length_n = n.size();
	int length_m = m.size();
	int length = max(length_m, length_n);
	//cout << length_n << length_m;
	vector<int> a(length+1,0);
	vector<int> b(length+1,0);
	vector<int> t(length+1,0);
	for (int i = 1; i <= length_n; i++)
	{
		for (int j = 1; j <= length_m; j++)
		{	
			
			if (n[i-1]== m[j-1])
			{	
				 a[j] = b[j - 1] + 1;
			}
			else
			{
				a[j] = max(a[j-1],b[j]);
			}
			
		}b = a;
	}
	cout << b[length_m];
}