#include <iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
    long long x, y, r;
    cin >> r >> x >> y;
    double dis = x * x + y * y;
    // cout << dis << " ";
    dis = sqrt(dis);
    // cout << dis;
    if (dis < r)
    {
        cout << 2;
    }
    else
    {
        long long num = ceil(dis / r);
        cout << num;
    }
}


