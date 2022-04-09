#include <iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct mat
{
    int a[3][3];
    int num;
};
vector<mat> v;
bool check(mat b)
{
    bool f = false;
    for (auto& i : v)
    {
        f = false;
        for (int j = 0; j < 3; j++)
        {
            for (int ii = 0; ii < 3; ii++)
            {
                if (i.a[j][ii] != b.a[j][ii]) f = true;
            }
        }
        if (f == false) return false;
    }
    // if (f == false) cout << "EWRT";
    return true;
}

long long fa[20];
bool ha[380000];
void fac(int n)
{
    fa[0] = fa[1] = 1; // 0的阶乘为1
    for (int i = 2; i <= n; i++) fa[i] = fa[i - 1] * i;
}
int main()
{
    fac(9);
    //if (ha[1] == false)cout << "A";
    int  b[3][3];// = {1,2,3,8,0,4,7,6,5};
    b[0][0] = 1; b[0][1] = 2; b[0][2] = 3; b[1][0] = 8; b[1][1] = 0; b[1][2] = 4; b[2][0] = 7; b[2][1] = 6; b[2][2] = 5;
    int x[4] = { 0,0,1,-1 };
    int y[4] = { 1,-1,0,0 };
    mat t;

    for (int j = 0; j < 3; j++)
    {

        for (int i = 0; i < 3; i++) { char c = getchar(); t.a[j][i] = c - '0'; }
    }
    mat tem = t;
    int str[9];
    str[0] = tem.a[0][0]; str[1] = tem.a[0][1]; str[2] = tem.a[0][2]; str[3] = tem.a[1][0];
    str[4] = tem.a[1][1]; str[5] = tem.a[1][2]; str[6] = tem.a[2][0]; str[7] = tem.a[2][1];
    str[8] = tem.a[2][2];
    int ans = 1;  //注意，因为 12345 是算作0开始计算的，最后结果要把12345看作是第一个

    for (int i = 0; i < 9; i++) {
        int tmp = 0;//用来计数的

        for (int j = i + 1; j < 9; j++) {
            if (str[i] > str[j]) tmp++;
            //计算str[i]是第几大的数，或者说计算有几个比他小的数
        }

        ans += tmp * fa[8 - i];
    }
    ha[ans] = true;


    t.num = 0;
    queue<mat> q;
    q.push(t);
   // v.push_back(t);

    bool f = false;

    ///  if (f) cout << "!!!";*/
     // 283104765
    while (!q.empty())
    {
        mat tem = q.front(); q.pop();
        mat add = tem;
        int i = 0, j = 0;
        bool f = true;
        //cout << tem.a[1][1];
        for (int ii = 0; ii < 3; ii++)
        {
            for (int jj = 0; jj < 3; jj++)if (b[ii][jj] != tem.a[ii][jj])f = false;
        }
        if (f) { cout << tem.num; break; }
        else
        {
            for (int jj = 0; jj < 3; jj++)
            {
                for (int ii = 0; ii < 3; ii++)
                    if (tem.a[jj][ii] == 0)
                    {
                        j = jj;
                        i = ii;
                        break;
                    }
            }

            for (int ji = 0; ji < 4; ji++)
            {
                tem = add;//cout<<"C";
                int row = j + x[ji]; int col = i + y[ji];
                if (row < 0 || row>2 || col < 0 || col>2) { continue; }
                else //if (row >= 0 && row < 3 && col >= 0 && col < 3)
                {
                    // cout << "B";
                    // swap(tem.a[row][col], tem.a[j][i]);
                    int m = tem.a[row][col];
                    tem.a[row][col] = tem.a[j][i];
                    tem.a[j][i] = m;
                    //  cout << j << i << " ";
                    int str[9];
                    str[0] = tem.a[0][0]; str[1] = tem.a[0][1]; str[2] = tem.a[0][2]; str[3] = tem.a[1][0];
                    str[4] = tem.a[1][1]; str[5] = tem.a[1][2]; str[6] = tem.a[2][0]; str[7]=tem.a[2][1];
                    str[8] = tem.a[2][2];         
                    int ans = 1;  //注意，因为 12345 是算作0开始计算的，最后结果要把12345看作是第一个             
                       for (int i = 0; i < 9; i++) {
                           int tmp = 0;//用来计数的

                           for (int j = i + 1; j < 9; j++) {
                               if (str[i] > str[j]) tmp++;
                               //计算str[i]是第几大的数，或者说计算有几个比他小的数
                           }

                           ans += tmp * fa[8-i];
                       }
                       
                      // cout << ans<<" ";
                    if (ha[ans]==false)
                    {
                        /*  for (int ii = 0; ii < 3; ii++)
                          {
                              for (int jj = 0; jj < 3; jj++)cout << tem.a[ii][jj];
                              cout << '\n';
                          }
                          cout << '\n';*/

                        tem.num++; ha[ans]=true; q.push(tem);
                    }
                }
            }
        }
    }
}