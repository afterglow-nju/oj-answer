#include <iostream>
#include<random>
using namespace std;
long long a[20000001];
long long arr = 0;
void mergesort(long long a[],long long l,long long r,long long h)
{
    if (l <= r)
    {
        if (h <= 1)
        {//cout << "A";
            long long m = 0;

            for (int i = l; i <= r; i++)
            {
                if (a[i]>m) {  m = a[i]; arr++; }
            }
            
        }
        else
        {
            long long m = (l + r) / 2;
            mergesort(a,l, m, h - 1);
            mergesort(a,m + 1, r, h - 1);
        }
    }
}
int main()
{
    unsigned long long seed;
    long long h, n;
    cin >> seed >> n >> h;
    mt19937_64 gen(seed);
    for (int i = 1; i <= n; i++) a[i] = i;
    for (int i = 1; i <= n; i++) {
        int u = gen() % (n - i + 1) + i;
        swap(a[u], a[i]);
    }
    mergesort(a,1, n, h);
    cout << arr;
  
}

