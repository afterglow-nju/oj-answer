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
#include<assert.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const ll mod1 = 1e6;
const ll maxn = 1e6 + 10;
ll n,p, q, x, y, z;
struct node
{
    ll val, left, right, Max, Or ;
    ll premax, preor, postmax, postor;

}A[maxn];
void cal()
{
    ll temp;
    stack <ll>S;
    while (!S.empty())S.pop();//真的需要！！！！！！
    for (ll i = 1; i <= n + 1; i++)
    {
       
        
        if (S.empty() || A[S.top()].val <= A[i].val)S.push(i);
        else
        {
            while (!S.empty() && A[S.top()].val > A[i].val)
            {
                temp = S.top();
                S.pop();
                A[temp].right = i - 1;
                A[temp].Max = max(A[temp].Max, max(A[temp].val, A[i].premax));
                A[temp].Or = A[temp].Or | A[i].preor;
                A[i].premax = max(A[temp].premax, max(A[i].premax, A[temp].val));
                A[i].preor = A[temp].preor | (A[i].preor | A[temp].val);
            }
            S.push(i);
        }
    }
    while (!S.empty())S.pop();
    for (ll i = n; i >= 0; i--)
    {

        if (S.empty() || A[S.top()].val <= A[i].val)S.push(i);
        else
        {
            while (!S.empty() && A[S.top()].val > A[i].val)
            {
                temp = S.top();
                S.pop();
                A[temp].left = i + 1;
                A[temp].Max = max(A[temp].Max, max(A[temp].val, A[i].postmax));
                A[temp].Or = A[temp].Or | A[i].postor;
                A[i].postmax = max(A[temp].postmax, max(A[i].postmax, A[temp].val));
                A[i].postor = A[temp].postor | (A[i].postor | A[temp].val);
            }
            S.push(i);
        }
    }
}
int main()
{
    ll T;
    cin >> T;
    while (T--)
    {
        cin >> n >> p >> q >> x >> y >> z;
        A[1].val = p;
        A[2].val = q;
        for (ll i = 3; i <= n; i++)
        {
            A[i].val = (x * A[i - 2].val + y * A[i - 1].val + z) % mod1+1;
        }
        //initial
        for (ll i = 1; i <= n; i++)
        {
            A[i].left = A[i].right = i;
            A[i].Max = A[i].Or = A[i].val;
            A[i].postmax = A[i].postor = A[i].premax = A[i].preor = 0;
        }
        A[n + 1].val = -1;
        A[n + 1].left = A[n + 1].right = n + 1;
        A[n + 1].Max = A[n + 1].Or = A[n + 1].val;
        A[n + 1].premax = 0, A[n + 1].preor = 0;
        A[n + 1].postmax = 0, A[n + 1].postor = 0;

        A[0].val = -1;
        A[0].left = 0, A[0].right = 0;
        A[0].Max = A[0].val, A[0].Or = A[0].val;
        A[0].premax = 0, A[0].preor = 0;
        A[0].postmax = 0, A[0].postor = 0;
         cal();
        ll ans0 = 0, ans1 = 0;
        ll tem0, tem1;
        for (ll i = 1; i <= n; i++)
        {
           
            tem0 = 0, tem1 = 0;
            tem0 = A[i].val * (A[i].Max - A[i].val) * (A[i].right - A[i].left + 1);// *A[i].Or;
         //   if (tem0 > ans0)ans0 = tem0;
// cout << A[i].Max<<" "<<A[i].val << '\n';
           tem1 = tem0 / mod;
            tem0 = tem0 % mod;
            tem1 *= A[i].Or;
            tem0 *= A[i].Or;
            tem1 += tem0 / mod;
            tem0 %= mod;

            if (tem1 > ans1 || (tem1 == ans1 && tem0 > ans0))
            {
               // cout << ans0 << " " << ans1<<'\n';
                ans1 = tem1; ans0 = tem0;
            }
            
        }
        cout << ans0<<'\n';
    }
}
//thanks to hls
/*

ll a[maxn];
class UnionFindSet {
private:
    vector<ll> f;
    ll _setid(ll x) {
        if (f[x] == x) return x;
        return f[x] = _setid(f[x]);
    }

    void _merge(ll x, ll y) {
        if (setid(x) < setid(y)) f[setid(y)] = setid(x);
        else f[setid(x)] = setid(y);
    }

    ll _minm()
    {
        return *min_element(f.begin(), f.end());
    }

    ll _maxn()
    {
        return *max_element(f.begin(), f.end());
    }

    ll _or()
    {
        ll tem = 0;
        for (auto i : f)
        {
            tem |= i;
        }
        return tem;
    }

public:
    UnionFindSet(ll n = 0) {
        f = vector<ll>(n);
        for (ll i = 0; i < n; i++) f[i] = i;
    }

    ll setid(ll x) {
        return _setid(x);
    }

    void merge(ll x, ll y) {
        _merge(x, y);
    }

    ll minm()
    {
        return _minm();
    }

    ll maxn()
    {
        return _maxn();
    }

    ll oor()
    {
        return _or();
    }
};

ll main()
{
	ll T;
	cin >> T;
	while (T--)
	{
		memset(a, 0, sizeof(a));
		ll n;
		cin >> n;
		ll p, q, x, y, z;
		cin >> p >> q >> x >> y >> z;
		a[1] = p;
		a[2] = q;
		for (ll i = 3; i <= n; i++)
		{
			a[i] = ((x * a[i - 2] + y * a[i - 1] + z) % mod1) + 1;
		}


	}
}*/