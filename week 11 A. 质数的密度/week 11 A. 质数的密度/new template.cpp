#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<bitset>
#include<stack>
#include<utility>
#include<iomanip>
#include<vector>
#include<math.h>
#include<string>
#include<stdio.h>
#include<limits>
using namespace std;

const long long N = 46350;

bool is_prime[N];
long long primes[N];

long long sieve(long long n)
{
    is_prime[0] = 1;
    is_prime[1] = 1;
    is_prime[2] = 1;
    for (long long i = 3; i <= n; i = i + 2)
    {
        is_prime[i] = true;
    }
    for (long long i = 2; i * 3 <= n; i++)
    {
        is_prime[3 * i] = 0;
    }

    long long cnt = 1;
    primes[0] = 2;
    primes[1] = 3;                     //把3的倍数预处理，就过了？！！！好唉！！！！！！！！！
    for (long long i = 5; i <= n; i = i + 2) //6->8
    {
        if (is_prime[i])
        {
            primes[++cnt] = i;
        }
        for (long long j = 1; j <= cnt && i * primes[j] <= n; j++) //j=0->j=1 偶数不用再考虑了
        {
            is_prime[i * primes[j]] = 0;
            if ((i % primes[j]) == 0)
                break;
        }
    }
    primes[++cnt] = 0;
    return cnt;
}
bool a[1000001];
int main()
{
    long long l, r;
    long long ans = 0;
    cin >> l >> r;
    long long num=sieve(sqrt(r)+2);
    //cout << primes[0];
    for (long long i = 0; i < r - l + 1; i++)a[i] = 1;
    for (long long i = 0; i <num; i++)
    {
        cout << max(2ll, (l - 1) / primes[i] + 1) << '\n';
        for (long long j = max(2ll,(l-1)/primes[i]+1)*primes[i]; j <= r; j += primes[i])
        {   
            //why (l - 1) / primes[i] + 1)直接2为什么不行
            a[j-l] = 0;
            
        }
    }
    for (long long i = 0; i <r - l + 1; i++)
    {
        if (a[i])ans++;
    }
    cout << ans;
}






