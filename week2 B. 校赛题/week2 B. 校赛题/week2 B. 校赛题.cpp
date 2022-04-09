#include <iostream>

using namespace std;
int a[100000000000001];
int main()
{
    /*long long  n, f = 1, row = 1, th = 0;
    long long sum = 0;
    a[1] = 1;
    cin >> n;
    if (n == 1) cout << 1;
    else
    {
        n = (1 + n + 1 )* (n + 1) / 2 - 2;
        for (long long i = 1; i <= n; i++)
        {
            
            if (f == 0)
            {
                
                row++;
                f = row;
            }
            if (a[i] == 0 || a[i] == -1 || a[i]==1) { a[i] = 1; sum++; }
            else a[i] = 0;
            long long st = (1 + row) * row / 2;
            th = i - st;//+1-1 抵消
            long long next_st = st + row;
            if (a[i] == 1)
            {
                a[next_st + th] = a[next_st + th] - 1;
                a[next_st + th + 1] = a[next_st + th + 1] - 1;
            }
            else
            {
                a[next_st + th] = a[next_st + th] + 1;
                a[next_st + th + 1] = a[next_st + th + 1] + 1;
            }
            f--;
        }
        cout << sum;
    }*/
    int n;
    cin >> n;
    if (n == 1) cout << 2;
    else
    {
        long long sum = 0;
        for (int i = 1; i <= n; i++)
        {   
            int temp = 1;
            int t = i;
            while (t >= 1)
            {
                int g = t % 2;
                if (g == 1 || t==1) temp *= 2;
                //t >>= 1;
                t = t / 2;
            }
            sum += temp;
        }
        cout << sum;
    }
}
//967 46616
