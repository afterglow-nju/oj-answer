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
const long long maxn = 100001;
bool is_prime[maxn];
int prime[maxn];
int phi[maxn];
int n;
void pre() {
    memset(is_prime, 1, sizeof(is_prime));
    int cnt = 0;
    is_prime[1] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            prime[++cnt] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= cnt && i * prime[j] <= n; j++) {
            is_prime[i * prime[j]] = 0;
            if (i % prime[j])
                phi[i * prime[j]] = phi[i] * phi[prime[j]];
            else {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
        }
    }
}
int main()
{
    
	cin >> n;
    long long ans=0;
    pre();
  //  cout << phi[1] << '\n' << phi[2];
    for (int i = 1; i <= n; i++)
    {
        ans += phi[i];
    }
   // ans++;
    ans = 2*ans+1;
    cout << ans;
}
//线性筛求欧拉函数，phi[1]=1?





