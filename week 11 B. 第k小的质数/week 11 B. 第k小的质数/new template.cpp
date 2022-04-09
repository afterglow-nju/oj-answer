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

const long long N = 100000001;

bool is_prime[N];
int primes[N];

void sieve(int n)
{
    is_prime[0] = 1;
    is_prime[1] = 1;
    is_prime[2] = 1;
    for (int i = 3; i <= n; i = i + 2)
    {
        is_prime[i] = true;
    }
    for (int i = 2; i * 3 <= n; i++)
    {
        is_prime[3 * i] = 0;
    }

    int cnt = 1;
    primes[0] = 2;
    primes[1] = 3;                     //把3的倍数预处理，就过了?!! 好唉!!!!
    for (int i = 5; i <= n; i = i + 2) //6->8
    {
        if (is_prime[i])
        {
            primes[++cnt] = i;
        }
        for (int j = 1; j <= cnt && i * primes[j] <= n; j++) //j=0->j=1 偶数不用再考虑了
        {
            is_prime[i * primes[j]] = 0;
            if ((i % primes[j]) == 0)
                break;
        }
    }
    primes[++cnt] = 0;

}
int main()
{
    float a = -2147483647;
    printf("0x%d", a);
    int n, q;
    cin >> n >> q;
    sieve(n);
    while (q--)
    {
        int k;
        cin >> k;
        cout << primes[k - 1]<<'\n';
    }
}






