﻿// 魔方.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
using namespace std;
int main()
{
    int T, m;
    cin >> T;

    vector< vector<int> > a(T, vector<int>(24, 0));
    for (int i = 0; i < T; i++)
        for (int j = 0; j < 24; j++) cin >> a[i][j];

    for (int i = 0; i < T; i++)
        for (int j = 0; j < 24; j++) cout << a[i][j];


    for (int i = 0; i < T; i++) {
        if ((a[i][1] == a[i][2] == a[i][3] == a[i][4]) && (a[i][5] == a[i][6] == a[i][7] == a[i][8]) && (a[i][9] == a[i][10] == a[i][11] == a[i][12]) && (a[i][13] == a[i][14] == a[i][15] == a[i][16]) && (a[i][17] == a[i][18] == a[i][19] == a[i][20]) && (a[i][21] == a[i][22] == a[i][23] == a[i][24])) cout << "YES" << '\n';
        else
        {
            for (int j = 0; j < 24; j++)
            {
                if ((a[i][1] == a[i][2] == a[i][23] == a[i][24]) && (a[i][21] == a[i][22] == a[i][10] == a[i][9]) && (a[i][12] == a[i][11] == a[i][19]) == a[i][20] && (a[i][5] == a[i][6] == a[i][7] == a[i][8])) cout << "YES" << '\n';
                else
                    if ((a[i][1] == a[i][2] == a[i][19] == a[i][20]) && (a[i][21] == a[i][22] == a[i][3] == a[i][4]) && (a[i][12] == a[i][11] == a[i][23] == a[i][24]) && (a[i][5] == a[i][6] == a[i][7] == a[i][8])) cout << "YES" << '\n';
                    else
                        if ((a[i][15] == a[i][16] == a[i][22] == a[i][24]) && (a[i][21] == a[i][23] == a[i][7] == a[i][8]) && (a[i][5] == a[i][6] == a[i][17] == a[i][19]) && (a[i][1] == a[i][2] == a[i][3] == a[i][4])) cout << "YES" << '\n';
                        else
                            if ((a[i][15] == a[i][16] == a[i][17] == a[i][19]) && (a[i][21] == a[i][23] == a[i][13] == a[i][14]) && (a[i][5] == a[i][6] == a[i][22] == a[i][24]) && (a[i][1] == a[i][2] == a[i][3] == a[i][4])) cout << "YES" << '\n';
                            else
                                if ((a[i][2] == a[i][4] == a[i][13] == a[i][15]) && (a[i][16] == a[i][14] == a[i][11] == a[i][9]) && (a[i][12] == a[i][10] == a[i][5] == a[i][7]) && (a[i][17] == a[i][18] == a[i][19] == a[i][20])) cout << "YES" << '\n';
                                else
                                    if ((a[i][2] == a[i][4] == a[i][5] == a[i][7]) && (a[i][16] == a[i][14] == a[i][1] == a[i][2]) && (a[i][12] == a[i][13] == a[i][15] == a[i][7]) && (a[i][17] == a[i][18] == a[i][19] == a[i][20])) cout << "YES" << '\n';
                                    else cout << "NO" << '\n';
            }


        }
    }
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
