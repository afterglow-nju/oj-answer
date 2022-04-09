#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
    long long n, jishu = 0;
    cin >> n;
   // int s = sqrt(n);

    long long a = sqrt(n);
    //int jishu = n % 233;
    for (long long i = 1; i <= a; i++)
    {
        jishu += n / i % 233;
       // cout << jishu<<" ";
    }
   // cout << '\n';
    int i = 2;
    for (i;n/i>=a; i++)
    {
       // long long temp = ceil(n / i);
        long long temp1 = ceil(n / (i - 1));
        long long temp2 = ceil(n / i);
        jishu += (temp1-temp2)*(i-1)%233;
       // cout << jishu<<" ";
    }
    for (int j = a + 1; j <= n / (i - 1); j++)
    {
        for (int x = a; x <= j; x++)
        {
            if (j % x == 0)jishu++;
        }
        cout << "AA";
    }
    cout <<jishu%233;
}