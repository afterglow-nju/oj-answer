
#include <iostream>
#include<string>

using namespace std;
int n;
int t[15][15],ba[15][15];	
int num = 2;
int jj = 1, ii = 1;
void change(int a, int b)
{
	for (int j = 1; j <= n; j++)
	{
		//int i = 1;
		t[a][j] = 1;
		t[j][b] = 1;
	}
	for (int i=1; i <= n; i++)
	{	
		if(a-i>0 && b-i>0) t[a - i][b - i] = 1;
		if (a + i <= n && b + i <= n) t[a + i][b + i] = 1;
		if (a - i > 0 && b + i <= n) t[a - i][b + i] = 1;
		if (a + i <= n && b - i > 0) t[a + i][b - i] = 1;

	}
}

void re()
{
//	for (int j = 1; j <= n; j++)
//	{
		//int i = 1;
//		t[a][j] = 0;
//		t[j][b] = 0;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		if (a - i > 0 && b - i > 0) t[a - i][b - i] = 0;
//		if (a + i <= n && b + i <= n) t[a + i][b + i] = 0;
//	}

	for (int j = 1; j <= n; j++)
	{
		int i = 1;
		for (i; i <= n; i++)
		{
			t[j][i] = ba[j][i];
		}
	}
}

void recur()
{
	bool f = false;
	for (int j = 1; j <= n; j++)
	{
		int i = 1;
		for (i; i <= n; i++)
		{
			if (t[j][i] == 0)
			{
				f = true;
				break;
			}
		}
	}
	
	if (f)
	{
		for (int j = jj+1; j <= n; j++)
		{
			int i = 1;
			for (i; i <= n; i++)
			{	
				if (t[j][i] == 0)
				{
					num++; 
					change(j,i);

				/*	for (int j = 1; j <= n; j++)
					{
						int i = 1;
						for (i; i <= n; i++)
						{
							cout << t[j][i];
						}
						cout << '\n';
					}
				cout << '\n'; */

					recur;
				}
			}
		}
	}
	else return;

}
//void c12()
//{
//	cout << "AA";
//}


int main()
{
	int  x, y, ag = 0;
	cin >> n >> x >> y;

	memset(t, 0, sizeof(t));
	memset(ba, 0, sizeof(ba));
	t[x][y] = 1;
	ba[x][y] = 1;

	//test
/*	change(x, y);
	re();
	for (int j = 1; j <= n; j++)
		{
			int i = 1;
			for (i; i <= n; i++)
			{
				cout << t[j][i];
			}
			cout << '\n';
		}
		cout << '\n';
		//
		
		*/
	change(x, y);
	for (int j = 1; j <= n; j++)
	{
		int i = 1;
		for (i; i <= n; i++)
		{
			ba[j][i] = t[j][i];
		}
	}
	/*for (int c = 1; c <= n * n; c++)
	{
		recur;
		if (num == n) { cout << "A"; ag++; }
		num = 1;
		re();
		recur;
	}*/

	for (jj = 1; jj <= n; jj++)
	{
		 ii = 1;
		for (ii; ii <= n; ii++)
		{
			if (ba[jj][ii] == 0)
			{
				change(jj, ii);
				recur(); cout << "A";
				if (num == n) { cout << "B"; ag++; }
				num = 2;
				re();
			}
		}
	}
	cout << ag;		

}
