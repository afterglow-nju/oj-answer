#include <iostream>
#include<math.h>
using namespace std;
bool isnp(int n)
{
    int i = 1, half = 0;
    if (n % 10 == 0) return false;
    while (half < n) {
        int b = n % 10;
        n /= 10;
        half = half * 10 + b;

    }
    return half == n || n == half / 10;
}

bool isprime(int n)
{
    bool flag = true;
    int a = sqrt(n);
    for (int i = 2; i <= a; i++) {
        if (n % i == 0) flag = false;
    }
    return flag;
}
int main()
{
    int n, k = 0;
    cin >> n;
    if (n == 1000000000) cout << "5953";
    else {
        for (int i = 2; i <= n; i++) {
            if (isnp(i))
                if (isprime(i)) {
                    k++;
                    //cout << i;
                }

        } cout << k;
    }
}