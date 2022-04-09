// week 4 D.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdlib.h> 
#include<string>
using namespace std;
char a[100000], b[100000];
int c[100000], d[100000], e[1000000];
//char a[100000], b[100000];
int main()
{

    cin >> a >> b;
    int i = 0, j = 0;
    memset(c, 0, sizeof(c));
    memset(d, 0, sizeof(d));
    while (a[i] != '\0') {
        c[i] = a[i] - '0';

        i++;
    }
    while (b[j] != '\0') {
        d[j] = b[j] - '0';
        j++;
        // cout << d[j];
    }
    // for (i; i >= 1; i--) cout << c[i-1];
    j--;
    i--;
    int k = i - j;
    int m = i, n = j;
    

    if (k == 0)
    {

        while (i >= 0)
        {
            if (c[i] + d[i] >= 10)
            {
                if (i - 1 < 0) cout << "1";
                else
                {
                    c[i - 1]++;
                }
                e[i] = (c[i] + d[i]) % 10;
                i--;
            }
            else
            {
                e[i] = c[i] + d[i];
                i--;
            }
        
           // cout << "c";
        }
    }


    if (k > 0)
    {
        while (j >= 0)
        {
            if (c[i] + d[j] >= 10)
            {
                c[i - 1]++;
                e[i] = (c[i] + d[j]) % 10;
            }
            else e[i] = c[i] + d[j];
            i--;
            j--;
        }
        while (i >= 0)
        {
            if (c[i] >= 10)
            {
                if (i - 1 < 0) cout << "1";
                else c[i - 1]++;
                e[i] = (c[i]) % 10;
                i--;
                /// cout << "aaa";
            }
            else {
                e[i] = c[i];
                i--;
                //  cout << "bbb";
            }
        }
    }

    if (k < 0)
    {
        while (i >= 0)
        {
            if (c[i] + d[j] >= 10)
            {
                //       if (i - 1 < 0) cout << "1";
                //       else 
                 //      {
                d[j - 1]++;
                e[j] = (c[i] + d[j]) % 10;
                //     }
            }
            else e[j] = c[i] + d[j];
            i--;
            j--;
        }
        while (j >= 0)
        {
            if (d[j] >= 10)
            {
                if (j - 1 < 0) cout << "1";
                else d[j - 1]++;
                e[j] = (d[j]) % 10;
                j--;
                /// cout << "aaa";
            }
            else {
                e[j] = d[j];
                j--;
                //  cout << "bbb";
            }
        }
    }

  //  cout << i;
    if (k >= 0) {
        i++;
        for (i; i <= m; i++) cout << e[i];
    }
    else {
        j++;
        for (j; j <= n; j++) cout << e[j];
    }
    //cout << m << n;

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
