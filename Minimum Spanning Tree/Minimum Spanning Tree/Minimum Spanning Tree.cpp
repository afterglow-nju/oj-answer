#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class UnionFindSet {
private:
    vector<int> f;
    int _setid(int x) {
        if (f[x] == x) return x;
        return f[x] = _setid(f[x]);
    }

    void _merge(int x, int y) {
        if (setid(x) < setid(y)) f[setid(y)] = setid(x);
        else f[setid(x)] = setid(y);
    }

public:
    UnionFindSet(int n = 0) {
        f = vector<int>(n);
        for (int i = 0; i < n; i++) f[i] = i;
    }

    int setid(int x) {
        return _setid(x);
    }

    void merge(int x, int y) {
        _merge(x, y);
    }
};
struct node
{
    long long d1;
    long long d2;
    long long w;
}a[500001];
bool cmp(node a, node b)
{
    return a.w < b.w;
}
//long long w[500001];
int main()
{
    int n, m;
    long long min_ = 0;
    cin >> n >> m;
    int k = 0;
    UnionFindSet u(n+1);
    for (int i = 0; i < m; i++)
    {
      /*  long long temp1, temp2,temp3;
        cin >> temp1 >> temp2>>temp3;
        if (temp1 != temp2)
        {   
            u.merge(temp1, temp2);
            a[k].d1 = temp1;
            a[k].d2 = temp2;
            w[k] = temp3;
            k++;
        }*/
        cin >> a[i].d1 >> a[i].d2 >> a[i].w;
    }
    k--;
    sort(a,a+m,cmp);
    for (int i = 0; i< m; i++)
    {
        int s1 = u.setid(a[i].d1);
        int s2 = u.setid(a[i].d2);
        if (s1 != s2)
        {
            
            min_ += a[i].w;
            u.merge(a[i].d1, a[i].d2);
        }
    }
    cout << min_;
}
