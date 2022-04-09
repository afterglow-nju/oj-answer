#include <iostream>
#include<vector>
using namespace std;
int v[2001];
//感觉用bitset更简单一点
//需要检查是否连通，用union and find
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
int main()
{
    int n, m;
    cin >> n >> m;
    UnionFindSet u(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x] = (v[x] + 1)%2;
        v[y] = (v[y] + 1)%2;
        u.merge(x, y);
    }
    bool f = true;

    for (int i = 1; i <= n; i++)
    {
        if (u.setid(i) != 1)
        {
            f = false;
            cout << "NO";
            break;
        }
    }
    if (f)
    {
        for (int i = 1; i <= n; i++)
        {
            if (v[i]!=0)
            {
                //cout << "NO";
                f = false;
                break;
            }
        }
        if (f) cout << "YES";
        else cout << "NO";
    }
}
