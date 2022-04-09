#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
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
int main()
{	
	
    int n, m,x,y;
    cin >> n >> m;
	UnionFindSet u(n);  //初始化出 5 个单元素集合, {0}, {1}, {2}, {3}, {4}
    while (m > 0)
    {   
        cin >> x >> y;
        u.merge(x, y);
        m--;
    }
//	u.merge(1, 3); // 合并 1 和 3 所在的集合, 现在集合变成 {0}, {1, 3}, {2}, {4}
//	u.merge(2, 4); // 合并 2 和 4 所在的集合, 现在集合变成 {0}, {1, 3}, {2, 4}
//	u.merge(3, 4); // 合并 3 和 4 所在的集合, 现在集合变成 {0}, {1, 2, 3, 4}
    int temp=u.setid(0);
    int q = 1;
    int a[1001];
    memset(a, 10001, sizeof(a));
    for (int i = 0; i < n; i++)
    {
        a[i] = u.setid(i);
    //   cout << u.setid(i)<<" ";
    }// 输出每个元素所在集合里面的最小元素, 会输出 0, 1, 1, 1, 1
    sort(a, a + 1001);
    for (int i = 0; i < n-1; i++)
    {
        if (a[i] != a[i + 1])
            q++;
    }
    cout << q;
}

