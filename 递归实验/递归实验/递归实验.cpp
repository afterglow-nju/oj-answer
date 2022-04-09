// 递归实验.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
int d[110], s[33], w[16]; int b[2], c[110];
int main()
{
	int x, xx, f, k, zero, p, changdu=3;
	f = 0;
	k = 0;
	int b[2] = { 1,3};
	while (f == 0)
	{
		x = 0;
		for (int i = 1; i <= changdu; i++)
		{
			xx = b[i] % 2;
			b[i] = (x * 10 + b[i]) / 2;
			x = xx;
		}
		k++;
		c[k] = x;
		f = 1;
		for (int i = 1; i <= changdu; i++)
		{
			if (b[i] != 0) f = 0;
		}
	}
	cout << c[0] << c[1];
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
