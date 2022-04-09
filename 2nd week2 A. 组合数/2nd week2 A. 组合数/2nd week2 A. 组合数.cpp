#include <iostream>
using namespace std;
long long ma = 1e9 + 7;
int n, m;
long long c[1000001];//max of m=10005

int main()
{
    cin >> n >> m;
    m = min(m, n - m);
    c[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            c[j] = (c[j] + c[j - 1])%ma;
        }
    }
    cout << c[m]%ma;
    
}//太妙了！！！！

/*
int main()
{
    
    int n, m, ji = 1;
    long long sum = 1, fm = 1;
    cin >> n >> m;
    m = min(m, n - m);
    for (int i = n - m + 1; i <= n; i++, ji++)
    {

        sum = ((sum*i / ji) % ma);乘法不可，因为如果先mod在乘除会有精度损失，而最后mod则会超出longlong 所以采用杨辉三角+滚动数组算 代码见上
    }
    //  for (int i = 1; i <= m; i++)
    //  {
     //     fm *= i;
     // }
    cout << sum%ma;

}*/

