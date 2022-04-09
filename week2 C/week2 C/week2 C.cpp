// week2 C.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m,c,d,f,k=0;
    cin >> n >> m;

    vector< vector<int> > A(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> A[i][j];
    vector< vector<int> > B(n, vector<int>(m, 0));
    for (int x = 0; x < n; x++)
        for (int y = 0; y < m; y++) cin >> B[x][y];
  //  vector<vector<int> > C;
    

    for (int i = 0,x=0; x<n&&i < n;x++, i++) {
        for (int j = 0,y=0; j<m&&y<m; y++,j++) {
            c = A[i][j] + B[x][y];
            cout << c << ' ';
        }
        cout << endl;
    }
    cout << '\n';
    for (int i = 0,x=0; x<n&&i < n;x++, i++) {
        for (int j = 0,y=0; y<m&&j < m;y++, j++) {
            d = A[i][j] - B[x][y];
            cout << d << ' ';
        }
        cout << endl;
    }
    cout << '\n';

    //vector <int> e(m+n);
  //  int k ,f;
    k = 0;
    for (int i = 0; i < n; i++) {
        for (int x=0; x < n; x++) {
            k = 0;//important
            for (int y = 0,j=0; j<m&&y < m;j++,y++) {
                f = A[i][j] * B[x][y];
                k = k + f;
                } 
            cout << k<<' ';
            }
            cout << '\n';
        } 
        ;
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
