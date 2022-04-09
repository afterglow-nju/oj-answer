#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<bitset>
#include<stack>
#include<utility>
#include<iomanip>
#include<vector>
#include<math.h>
#include<string>
#include<stdio.h>
#include<limits>
using namespace std;
void p1(int x, int y)
{
	cout << x << " " << y << '\n';
}
void p2(int x, int y)
{
	cout << y << " " << x << '\n';
}

void n2(int X,int Y,int n, int m,void p(int x,int y))
{
	int x = X, y = Y;
	int up = x, down = n - x - 1;
	if (y == 0)
	{
		if (up % 2)
		{
			for (int i = x; i < n; i++) p(i, 0);//先下
			bool f = true;
			for (int i = n - 1; i >= 0; i--)
			{
				if (f)
				{
					for (int j = 1; j < m; j++) p(i, j);
					f = false;
				}
				else
				{
					for (int j = m - 1; j >= 1; j--)p(i, j);
					f = true;
				}
			}
			for (int i = 0; i < x; i++)p(i, 0);
		}
		else
		{
			for (int i = x; i >= 0; i--)p(i, 0);
			bool f = true;
			for (int i = 0; i < n; i++)
			{
				if (f)
				{
					for (int j = 1; j < m; j++)p(i, j);
					f = false;
				}
				else
				{
					for (int j = m - 1; j >= 1; j--)p(i, j);
					f = true;
				}
			}
			for (int i = n - 1; i > x; i--)p(i, 0);
		}
	}
	else if (y == m - 1)
	{
		if (up % 2)
		{
			for (int i = x; i < n; i++)p(i, y);//先下
			bool f = false;

			for (int i = n - 1; i >= 0; i--)
			{
				if (f)
				{
					for (int j = 0; j < m - 1; j++) p(i, j);
					f = false;
				}
				else
				{
					for (int j = m - 2; j >= 0; j--)p(i, j);
					f = true;
				}
			}
			for (int i = 0; i < x; i++)p(i, y);
		}
		else
		{
			for (int i = x; i >= 0; i--)p(i, y);
			bool f = false;
			for (int i = 0; i < n; i++)
			{
				if (f)
				{
					for (int j = 0; j < m - 1; j++)p(i, j);
					f = false;
				}
				else
				{
					for (int j = m - 2; j >= 0; j--)p(i, j);
					f = true;
				}
			}
			for (int i = n - 1; i > x; i--)p(i, y);
		}
	}
	else
	{
		if (up % 2)
		{
			for (int i = y; i < m; i++) p(x, i);
			bool f = true;//right->left
			for (int i = x - 1; i >= 0; i--)
			{
				if (f)
				{
					for (int j = m - 1; j >= 1; j--) p(i, j);
					f = false;
				}
				else
				{
					for (int j = 1; j < m; j++) p(i, j);
					f = true;
				}
			}
			for (int i = 0; i < n; i++) p(i, 0);
			f = true;
			for (int i = n - 1; i > x; i--)
			{
				if (f)
				{
					for (int j = 1; j < m; j++) p(i, j);
					f = false;
				}
				else
				{
					for (int j = m - 1; j >= 1; j--) p(i, j);
					f = true;
				}
			}
			for (int i = 1; i < y; i++) p(x, i);
		}
		else
		{
			for (int i = y; i < m; i++) p(x, i);
			bool f = true;//right->left
			for (int i = x + 1; i < n; i++)
			{
				if (f)
				{
					for (int j = m - 1; j >= 1; j--) p(i, j);
					f = false;
				}
				else
				{
					for (int j = 1; j < m; j++) p(i, j);
					f = true;
				}
			}
			for (int i = n - 1; i >= 0; i--) p(i, 0);
			f = true;
			for (int i = 0; i < x; i++)
			{
				if (f)
				{
					for (int j = 1; j < m; j++) p(i, j);
					f = false;
				}
				else
				{
					for (int j = m - 1; j >= 1; j--) p(i, j);
					f = true;
				}
			}
			for (int i = 1; i < y; i++)
			{
				p(x, i);
			}
		}
	}

}

int main()
{
	int n, m, X, Y;
	cin >> n >> m >> X >> Y;
	if (n % 2 == 0)
	{
		n2(X, Y, n, m,p1);
	}
	else
	{
		n2(Y, X, m, n,p2);
	}
	
}
/*

	{
		if (y == 0)
		{
			if (up % 2)
			{
				for (int i = x; i < n; i++)p(i, 0);//先下
				bool f = true;
				for (int i = n - 1; i >= 0; i--)
				{
					if (f)
					{
						for (int j = 1; j < m; j++) p(i, j);
						f = false;
					}
					else
					{
						for (int j = m - 1; j >= 1; j--)p(i, j);
						f = true;
					}
				}
				for (int i = 0; i < x; i++)p(i, 0);
			}
			else
			{
				for (int i = x; i >= 0; i--)p(i, 0);
				bool f = true;
				for (int i = 0; i < n; i++)
				{
					if (f)
					{
						for (int j = 1; j < m; j++)p(i, j);
						f = false;
					}
					else
					{
						for (int j = m - 1; j >= 1; j--)p(i, j);
						f = true;
					}
				}
				for (int i = n - 1; i > x; i--)p(i, 0);
			}
		}
		else if (y == m - 1)
		{
			if (up % 2)
			{
				for (int i = x; i < n; i++)p(i, y);//先下
				bool f = false;

				for (int i = n - 1; i >= 0; i--)
				{
					if (f)
					{
						for (int j = 0; j < m - 1; j++) p(i, j);
						f = false;
					}
					else
					{
						for (int j = m - 2; j >= 0; j--)p(i, j);
						f = true;
					}
				}
				for (int i = 0; i < x; i++)p(i, y);
			}
			else
			{
				for (int i = x; i >= 0; i--)p(i, y);
				bool f = false;
				for (int i = 0; i < n; i++)
				{
					if (f)
					{
						for (int j = 0; j < m - 1; j++)p(i, j);
						f = false;
					}
					else
					{
						for (int j = m - 2; j >= 0; j--)p(i, j);
						f = true;
					}
				}
				for (int i = n - 1; i > x; i--)p(i, y);
			}
		}
		else
		{
			if (up % 2)
			{
				for (int i = y; i < m; i++) p(x, i);
				bool f = true;//right->left
				for (int i = x - 1; i >= 0; i--)
				{
					if (f)
					{
						for (int j = m - 1; j >= 1; j--) p(i, j);
						f = false;
					}
					else
					{
						for (int j = 1; j < m; j++) p(i, j);
						f = true;
					}
				}
				for (int i = 0; i < n; i++) p(i, 0);
				f = true;
				for (int i = n - 1; i > x; i--)
				{
					if (f)
					{
						for (int j = 1; j < m; j++) p(i, j);
						f = false;
					}
					else
					{
						for (int j = m - 1; j >= 1; j--) p(i, j);
						f = true;
					}
				}
				for (int i = 1; i < y; i++) p(x, i);
			}
			else
			{
				for (int i = y; i < m; i++) p(x, i);
				bool f = true;//right->left
				for (int i = x + 1; i < n; i++)
				{
					if (f)
					{
						for (int j = m - 1; j >= 1; j--) p(i, j);
						f = false;
					}
					else
					{
						for (int j = 1; j < m; j++) p(i, j);
						f = true;
					}
				}
				for (int i = n - 1; i >= 0; i--) p(i, 0);
				f = true;
				for (int i = 0; i < x; i++)
				{
					if (f)
					{
						for (int j = 1; j < m; j++) p(i, j);
						f = false;
					}
					else
					{
						for (int j = m - 1; j >= 1; j--) p(i, j);
						f = true;
					}
				}
				for (int i = 1; i < y; i++)
				{
					p(x, i);
				}
			}
		}
	}
*/