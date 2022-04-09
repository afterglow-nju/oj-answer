
#include <iostream>
//#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
//vector<vector<int>> map(n, vector<int>(n, 0));
int map[1001][1001];
int row[100000];//possibly that the number of the cateen of this problem is less than 100000;
int col[100000];
int outcome[100000];

int main()
{
	cin >> n;
	int temp = 1;
	for (int j = 1; j <= n; j++)
	{
		int i = 1;
		for (i = 1; i <= n; i++)
		{
			cin >> map[j][i];
			if (map[j][i] == 1) { row[temp] = j; col[temp] = i; temp++; }
		}
	}
	temp--;
	int min = 2 * n;
	int num = 1;;
	for (int j = 1; j <= n; j++)
	{
		int i = 1;
		for (i = 1; i <= n; i++)
		{	
			
			if (map[j][i] == 0)
			{	
				int ji = 1;
				min = 2 * n;
				for ( ji; ji <= temp; ji++)
				{
					int tem=abs(j -row[ji])+abs(i-col[ji]);
					//cout << tem << " ";
					if (tem < min) { min = tem; }
				}
			//	cout << min;
				outcome[num] = min; num++; //cout << '\n';
			}
		}
	}
	num--;
	sort(outcome+1, outcome+num+1);
cout << outcome[num];
	//for (int i = 1; i <= num; i++) cout << outcome[i]<<" ";
}

