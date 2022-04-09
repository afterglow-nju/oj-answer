#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;
long long w[10000001];
long long f(long long  x)
{
    w[0] = 0; w[1] = 1;
    if (x == 1) return 1;
    if (x == 0) return 0;
    for (long long i = 2; i <= x; i++)
    {
        w[i] = w[i - 1] % 1000000007 + w[i - 2] % 1000000007;
    }
    return w[x];
}
long long  a[10000001], b[10000001], c[10000001];
int main()
{
    long long n, m;
    long long sum = 0;
    cin >> n >> m;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    for (long long i = 1; i <= m; i++) cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    long long temp = a[1];
    long long equal = 1;
    c[0] = 1;
    long long j = 1;
    for (long long i = 1; i <= n; i++)
    {
        if (temp != a[i])
        {
            c[equal] = i - j;
            equal++;
            temp = a[i];
            j = i;
        }
    }



    c[equal] = n;
    for (long long i = 1; i <= equal - 1; i++)
        c[equal] = c[equal] - c[i];
    unique(a + 1, a + n + 1);
    // for (long long i = 1; i <= equal; i++) cout << c[i]<<" ";
    for (long long i = 1; i <= equal; i++)
    {
        long long j = 1;
        for (j; j <= m; j++)
        {
            long long q = abs(a[i] - b[j]);
            sum = sum + (f(q) % 1000000007 * c[i]) % 1000000007;
            //   if (sum > 1000000007) sum=sum%;%
        }
    }//提前除掉
    cout << sum % 1000000007;
}
//