#include <iostream>
using namespace std;
int main()
{
    int n, top1 = 0, top2 = 0, x = 0, t1 = 0, t2 = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (top1 == 0)
        {
            t1 = x;
        }
        else if (top2 == 0) t2 = x;
        if (x == t1) { top1++; }
        else  if (x == t2) {
            top2++;
        }
        else if (x != t1 && x != t2) { top1--; top2--; }
        
    }
    if (t1 < t2)
        cout << t1 <<" "<< t2;
    else
        cout << t2 << " "<<t1;
}

