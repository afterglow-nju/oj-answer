// week7 A1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
bool f1 = true, f2 = true, f3 = true, f4=true,flag=true;
int t[15][15];
int n, num = 0;
int  x, y;



bool isok(int x, int y)
{
	for (int j = 1; j <= n ; j++)
	{
		if (t[j][y] == 1 && j != x) { return false; }
	}
	for (int tem = 1; tem <= n; tem++)
	{
		if (x - tem > 0 && y - tem > 0)
		{
			if (t[x - tem][y - tem] == 1) { return false; }
		}
		if (x + tem <= n && y + tem <= n)
		{
			if (t[x + tem][y + tem] == 1)
			{
				return false;
			}
		}
		if (x - tem > 0 && y + tem <= n)
		{
			if (t[x - tem][y + tem] == 1) { return false; }
		}
		if (x + tem <= n && y - tem > 0)
		{
			if (t[x + tem][y - tem] == 1)
			{
				return false;
			}
		}


	}
	return true;
}
void queue(int hang,int lie)
{
	/*for (int j = 1; j <= n && j != hang; j++)
	{
		int i = 1;
		flag = true;
		for (i; i <= n && flag && i!=lie; i++)
		{
			if (t[j][i] == 0)
			{
				if (isok(j, i))
				{
					t[j][i] = 1;
					num++;
					queue(j,i);
					t[j][i] = 0;
					flag=false;
				}
			}
		}

	}*/


}
void search(int col) {
	if (col == x) col++;
	if (col == n + 1) {
		num++;
		return;
	}
	for (int i = 1; i <= n; i++) 
	{
		t[col][i] = 1;
		if (isok(col, i))
		{
			//if (col == 1 && i == 1) cout << "A";
			search(col + 1);

		/*	for (int row = 1; row <= n; row++)
			{
				int colu = 1;
				for (colu = 1; colu <= n; colu++) { cout << t[row][colu]; }
				cout << '\n';
			}
			cout << '\n';
			*/

			//cout <<i<<" "<<col<<endl;
		}
		t[col][i] = 0;
	}
}


int main()
{
	cin >> n >> x >> y;
	t[x][y] = 1;
	//queue(x, y);
	//if (num == n) out++;

	search(1);
	cout << num;
}

