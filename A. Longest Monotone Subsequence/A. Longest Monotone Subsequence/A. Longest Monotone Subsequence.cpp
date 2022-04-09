// A. Longest Monotone Subsequence.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
//int a[100];
//int longest(int n) {
//	int j, b[100]{ 0 };//(b计数
//	for (int i = 1; i <= n; i++) {
//		j = i + 1;
//		for (j; j <= n; j++) {
//			if (a[i] <a[j]) {
//				b[i]++;
//			}
//		}
//	}
//}
int main()
{
	int a[100], n, j, b[100]{ 0 };//(b计数
	int f[100], g[100];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}




	for (int i = 1; i <= n; i++) {
		j = i + 1;
		for (j; j <= n; j++) {
			if (a[i] < a[j]) {
				b[i]++;
			}
		}
	}

	
	//从小到大排b[i]
	int max = -1, d = 1;
	for (d; d <= n; d++) {
		int i = 1;
		max = 0;
		for (int i = 1; i <= 10; i++) {
			if (b[i] > max) {;
				max = b[i];
				//b[i] =0;
			}
		}//找到b[i]中max
		

		//f[10 - d + 1] = max;
		//cout << max<<'\n';
		for (int i = 1; i <= 20; i++) {
			if (max == b[i]) {
				b[i] = 0;
			}
		}
		b[20-d+1] = max;
		//cout << max << '\n';


	}
	
	

	int k = 0, m = 0;
	for (int i=11; i <= 20; i++) {
		if (b[i] >= k) {
			k++;
			m++;
		}
	}

















	int p[100]{ 0 };

	for (int i = 1; i <= n; i++) {
		j = i + 1;
		for (j; j<= n; j++) {
			if (a[i] > a[j-1]) {
				p[i]++;
			}
		}
	}
	//从小到大排p[i]
	 max = -1, d = 1;
	for (d; d <= n; d++) {
		int i = 1;
		max = -1;
		for (int i = 1; i <= 10; i++) {
			if (p[i] > max) {
				max = p[i];
			}
		}//找到b[i]中max
		//cout << max;

		for (int i = 1; i <=20; i++) {
			if (max == b[i]) {
				p[i] = 0;
			}
		}
		p[i] = p[n - d + 1];
		p[20-d+1] = max;
	}


	k = 0;
	int q = 0;
	for (int i = 11; i <= 20; i++) {
		if (p[i] >= k) {
			k++;
			q++;
		}
	}







	if (q > m) {
	cout << q;
	}
	else
		cout << m;


	//计数比它大的数成功
	//for (int i = 1; i <= n; i++) {
	//	cout<<b[i];
//	}
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
