#include <iostream>
#include<math.h>
using namespace std;
int prime[17985];
int a[200001];
long long  total(int n)
{
    long long t = 0;
    int j = (n / 3);
    if (j % 2 == 0) j += 1;
    for (j; j >= 3; j = j - 2)
    {
        bool f = false;
        if (n % j == 0)
        {
            n = n / j;
            t = t + a[j];
            f = true;
            while (f)
            {

                if (n % j == 0 && n != 1)
                {
                    n = n / j;
                    t = t + a[j];
                }
                else
                {
                    f = false;
                }
            }
            if (n == a[j] && a[j] == 1) { n = 1; break; }
        }
    }
    if (n != 1)
    {

        int k = 0;
        while (n >= prime[k])
        {
            //  cout << t;
            bool f = false;
            if (n % prime[k] == 0)
            {
                n = n / prime[k];

                t++;
                //cout << t;
                f = true;
            }
            while (f)
            {

                if (n % prime[k] == 0 && n != 1)
                {
                    n = n / prime[k];
                    t++;
                }
                else
                {
                    f = false;
                }
            }
            if (n == 1) { break; }
            k++;

        }
    }

    return t;
}
void p(int n)
{
    //  cout << "b";
    int k = 0;

    for (int i = 2; i <= n; i++)
    {
        bool f = true;
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0) { f = false; break; }
        }
        if (f)
        {
            prime[k] = i;
            k++;
            a[i] = 1;
            //   cout << i << ",";
        }
    }
    k--;

}
int main()
{

    int n, w, num = 0;
    cin >> n >> w;
    p(n);
    int k1 = 0;
    for (int i = pow(2, w); i <= n; i++)
    {
        bool f = true;
        int temp = i;
        int k = 0;
        if (i % 2 == 0 && i != 2) { a[i] = a[i / 2] + 1; }
        else
        {
            if (a[i] == 1);
            else
            {
                while (temp != 1)
                {
                    while (temp % prime[k] == 0)
                    {
                        temp = temp / prime[k]; a[i]++;
                        if (a[i] > w)
                        {
                            f = false;
                            break;
                        }
                    }
                    k++;
                    if (f == false) break;
                }
            }

        }
        if (a[i] == w)num++;
    }
    cout << num;
}
