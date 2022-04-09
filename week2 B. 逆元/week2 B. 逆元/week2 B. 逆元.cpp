#include <iostream>

using namespace std;

long long qp(long long a, long long b, long long m)//a^b mod m
{
    if (b == 0) return 1;
    if (b == 2) return a * a % m;
    if (b == 1) return a;
    if (b % 2 == 0) {
        long long temp = (qp(a, b / 2, m)) % m;
        return (temp * temp) % m;
    }
    else {
        long long temp1 = (qp(a, b / 2, m)) % m;
        return (temp1 * temp1 % m * a) % m;
    }
}


int main()
{
    long long a, m;
    // cin >> a >> b >> m;
    long long n, b;
    cin >> n >> b;
    m = n - 2;
    cout << qp(b % m, m, n);
}

/*
long long a, m;
   // cin >> a >> b >> m;
    long long n, b;
    cin >> n >> b;
    m = n - 2;
    cout << qp(b%m, m, n);
    
    long long a, b, m;
    cin >> a >> b >> m;
    cout << qp(a % m, b, m);
*/