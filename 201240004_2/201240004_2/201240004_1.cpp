#include <iostream>
using namespace std;
int main()
{
    int row = 20, col = 20;
    int** arr = new int* [row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    //遍历边框
    bool f = true;
    for (int i = 0; i < n; i++)
    {
        if (arr[0][i] == 0) arr[0][i] = 2, f = false;
        if (arr[i][0] == 0) arr[i][0] = 2, f = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[n - 1][i] == 0) arr[n - 1][i] = 2, f = false;
        if (arr[i][n - 1] == 0) arr[i][n - 1] = 2, f = false;
    }
    if (f)
    {
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                if (arr[i][j] == 0)
                {
                    arr[i][j] = 1;
                }
            }
        }
    }
    else
    {
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                if (arr[i][j] == 0)
                {
                    if (arr[i - 1][j] == 2 || arr[i][j - 1] == 2)
                    {
                        arr[i][j] = 2;
                    }
                }
            }
        }
        for (int i = n - 1; i > 0; i--)
        {
            for (int j = n - 1; j > 0; j--)
            {
                if (arr[i][j] == 0)
                {
                    if (arr[i + 1][j] == 2 || arr[i][j + 1] == 2)
                    {
                        arr[i][j] = 2;
                    }
                }
            }
        }

        //repeat
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                if (arr[i][j] == 0)
                {
                    if (arr[i - 1][j] == 2 || arr[i][j - 1] == 2)
                    {
                        arr[i][j] = 2;
                    }
                }
            }
        }
        for (int i = n - 1; i > 0; i--)
        {
            for (int j = n - 1; j > 0; j--)
            {
                if (arr[i][j] == 0)
                {
                    if (arr[i + 1][j] == 2 || arr[i][j + 1] == 2)
                    {
                        arr[i][j] = 2;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (f == false)
            {
                if (arr[i][j] == 2)
                {
                    cout << "0 ";
                }
                else
                {
                    if (arr[i][j] == 0) arr[i][j] = 1;

                    cout << arr[i][j] << " ";
                }
            }
            else cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    for (int i = 1; i < row; i++)
    {
        delete[]arr[i];
    }
    delete[]arr;
}
