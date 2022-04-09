// 程设考试1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int fib(int n) 
{
	if (n == 1 || n == 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}

void Move(int n, char A, char B, char C)
{
	if (n == 1)
	{
		//圆盘只有一个时，只需将其从A塔移到C塔
		cout << "move " << n << " from " << A << " to " << C << endl;
	}
	else
	{
		Move(n - 1, A, C, B);//递归，把A塔上编号1~n-1的圆盘移到B上，以C为辅助塔
		cout << "move " << n << " from " << A << " to " << C << endl;//把A塔上编号为n的圆盘移到C上
		Move(n - 1, B, A, C);//递归，把B塔上编号1~n-1的圆盘移到C上，以A为辅助塔
	}
}

void Hanoi(int n)
{
	if (n <= 0)
		return;
	Move(n, 'A', 'B', 'C');
}

//int main()
//{
///	int n;
//	cin >> n;
//	Hanoi(n);
//	return 0;
//}

int main()
{

	double x1, y1, x2, y2, k, b, n;
	cin >> x1 >> y1 >> x2 >> y2 >> k >> b;
	bool a, b1, c, d, flag1, flag2, flag3, flag4, flag5, flag6, flag7;
	a = (y1 <= k * x2 + b && k * x2 + b <= y2);
	b1 = (y1 <= k * x1 + b && k * x1 + b <= y2);
	c = (x1 <= ((y1 - b) / k) && ((y1 - b) / k) <= x2);
	d = (x1 <= ((y2 - b) / k) && ((y2 - b) / k) <= x2);
	flag1 = a & b1;
	flag2 = a & c;
	flag3 = a & d;
	flag4 = b1 & c;
	flag5 = b1 & d;
	flag6 = c & d;
	flag7 = flag1 | flag2 | flag3 | flag4 | flag5 | flag6;
	if (flag1) {
		n = sqrt((x2 - x1) * (x2 - x1) + k * k * (x1 - x2) * (x1 - x2));
		!flag1;
	}
	else {
		if (flag2) {
			n = sqrt((x2 - (y1 - b) / k) * (x2 - (y1 - b) / k) + (k * x2 + b - y1) * (k * x2 + b - y1));
			!flag2;
		}

		else {
			if (flag3) {
				n = sqrt((x2 - (y2 - b) / k) * (x2 - (y2 - b) / k) + (k * x2 + b - y2) * (k * x2 + b - y2));
				!flag3;
			}
			else {
				if (flag4) {
					n = sqrt((x1 - (y1 - b) / k) * (x1 - (y1 - b) / k) + (k * x1 + b - y1) * (k * x1 + b - y1));
					!flag4;
				}
				else {
					if (flag5) {
						n = sqrt((x1 - (y2 - b) / k) * (x1 - (y2 - b) / k) + (k * x1 + b - y2) * (k * x1 + b - y2));
						!flag5;
					}
					else {

						if (flag6) {
							n = sqrt(((y2 - b) / k - (y1 - b) / k) * ((y2 - b) / k - (y1 - b) / k) + (y1 - y2) * (y1 - y2));
							!flag6;
						}
					}
				}
			}
		}
	}if (!flag7) cout << "0";
						else cout <<fixed<<setprecision(2)<< n;
					//cout << flag1 << flag2 << flag3 << flag4 << flag5 << flag6 << flag7;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
