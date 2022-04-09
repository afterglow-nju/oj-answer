// week 6 D.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include<cstring>
using namespace std;
long long add[1000];
int main()
{
    int temp = 0, sum = 0;
    memset(add, 0, sizeof(add));
    int i = 0, j = 0, jishu = 0;
    char s = 'q', aa[1000];
    while (s != '\n')
    {
        s = getchar();
        if (s != ' ') { aa[jishu] = s; jishu++; }
    }

    while (i <= jishu - 2)
    {
        if (aa[i] != '*' && aa[i] != '+')
        {
            temp = aa[i] - '0';
            add[j] = 10 * add[j] + temp;
            //cout << a[i];
        }
        else
        {
            j++;
            if (aa[i] == '*') add[j] = -1;
            else add[j] = -2;
            j++;
        }
        i++; //cout << "A";
    }

    //cout << i;
    //temp = a[0] - '0';
   // cout << add[;
   // for (int x = 0; x <= j; x++)cout << add[x];
    int a1, a2;
    bool flag = false;
    for (int x = 0; x <= j; x++)
    {
        if (add[x] == -2 || add[x] == -1)  flag=true;
    }
    if (flag)
    {
        for (int x = 0; x <= j; x++)
        {
            if (add[x] == -1)
            {
                int   x1 = 0, x2 = 0;
                for (x1 = x - 1; x1 >= 0; x1--)
                    if (add[x1] != -3)
                    {
                        a1 = add[x1]; break;
                    }
                for (x2 = x + 1; x2 <= j; x2++)
                    if (add[x2] != -3) {
                        a2 = add[x2]; break;
                    }
                //  cout << a1 << a2;
                sum = a1 * a2;
                // cout << sum << '\n';
                add[x1] = -3;
                add[x] = sum;
                add[x2] = -3;
                //  sum += add[x - 1] * add[x + 1];
                 // add[x - 1] = 0;
                //  add[x] = -2;
                 // add[x + 1] = sum;
                //  cout << sum;
                 // cout << add[x] << " ";
            }
        }
        // for (int x = 0; x <= j; x++)cout << add[x] << " ";
      //   for (int x = 0; x <= j; x++)cout << add[x]<<" ";
         // cout << add[0] << add[1] << add[2];
        int a3 = 0, a4 = 0;
        for (int x = 0; x <= j; x++)
        {
            //  for (int x = 0; x <= j; x++)cout << add[x] << " ";
            if (add[x] == -2)
            {
                int x3, x4;
                for (x3 = x - 1; x3 >= 0; x3--)
                    if (add[x3] != -3) {
                        a3 = add[x3]; break;
                    }
                for (x4 = x + 1; x4 <= j + 1; x4++)
                    if (add[x4] != -3) { a4 = add[x4]; break; }
                sum = a3 + a4;
                //cout << a3<<a4<< " ";
                add[x3] = -3;
                add[x4] = -3;
                // add[x - 1] = -3;
                add[x] = sum;
                // add[x + 1] = -3;
                // sum += a3 + a4;


            }
            // cout << '\n';
        } // for (int x = 0; x <= j; x++)cout << add[x] << " ";
    }
    else sum = add[0];
   cout << sum; 
   
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
