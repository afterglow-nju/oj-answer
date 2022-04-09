#include <iostream>

using namespace std;
int su[10][10];
bool only_one = true;
bool isok(int n, int row, int col)
{
    for (int i = 0; i <= 8; i++)
    {
        if (su[row][i] == n && i != col) return false;
        if (su[i][col] == n && i != row) return false;
    }
    int k1 = row / 3, k2 = col / 3;
    for (int i = k1 * 3; i <= k1 * 3 + 2; i++)
    {
        for (int j = k2 * 3; j <= k2 * 3 + 2; j++)
        {
            if ((su[i][j] == n) && ((i != row) || (j != col)))return false;
        }
    }
    return true;
}
void output()
{
    for (int j = 0; j <= 8; j++) {
        for (int i = 0; i <= 8; i++) {
            cout << su[j][i] << " ";
        }
        cout << '\n';

    }
}
void dfs(int n)
{
    if (n < 0)
    {
        if (only_one)
        {
            output();
            only_one = false;
        }
        return;
    }
    if (only_one)
    {
        if (su[n / 9][n % 9] == 0)//行列的表示 (row-1)*9+n%9=n (n-n%9)/9+1
        {
            int temp = 1;
            for (temp; temp <= 9; temp++)
            {
                su[n / 9][n % 9] = temp;
                if (isok(temp, n / 9, n % 9)) { dfs(n - 1); }
                su[n / 9][n % 9] = 0;
            }
        }
        else
        {
            dfs(n - 1);
        }
    }
    else return;
}
//必须一维数组


int main()
{
    // for (int i = 1; i <= 81; i++) cin >> so[i];
    for (int j = 0; j <= 8; j++) {
        for (int i = 0; i <= 8; i++) {
            cin >> su[j][i];
        }
    }
    //  for (int j = 1; j <= 81; j++) cout << su[j]<<" ";
    dfs(81);


}

//反搜大法好