// programming.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<cmath>
using namespace std;
int b[100];
//void f(int n)
//{
  //  int i = 1;
  //  if (n == 0) cout << "2(0)+";
  //  if (n == 1)cout << "2+";
   // if (n == 2) cout << "2(2)+";
   // if (n > 2)
   //// {
  //      while (n > 0)
  ///      {
  ///          b[i] = log2(n);
 ///           n = n - pow(2, b[i]);
 ///           i++;
 //       } cout << "2(";
 //       for (int j = 1; j <= i - 1; j++)
 //       {
//
 //           f(b[j]);
//
//        }cout << ")";
//    }
//}
void f(int n)
{
    int a = log2(n); 
    if (a == 0)
    { cout << "2(0)";
      return;
    }
    if (a == 1) cout << "2";
    else
    {
        cout << "2(";
        f(a);
        cout << ")";
    }
    int re = n - pow(2, a);
    if (re >= 1)
    {
        cout << "+";
        f(re);
        //cout << ")";
    }
}
int main()
{
    int n,i=1;
    cin >> n;
    f(n);
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
