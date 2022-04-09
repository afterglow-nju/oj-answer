#include <iostream>
using namespace std;
int a[101], b[101];
int main()
{
    int n, m,t=0,j1=0,j2=0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> t; a[i] = t;
    }
    for (int i = 1; i <= m; i++) { cin >> t; b[i] = t; }
    for (int i = n; i >= 1; i--)
    {
        if (a[i] != 0) {j1 = i; break; }
    }
    for (int i = m; i >= 1; i--)
    {
        if (b[i] != 0) { j2 = i; break; }
    }
  //  cout << j1 << j2;
    if (j1 < j2)cout << "Yes"; else cout << "No";
    cout << '\n';
    if (j1 <= j2) cout << "Yes"; else cout << "No"; cout << '\n';
    if (j1 == j2) cout << "Yes"; else cout << "No"; cout << '\n';
    if (j1 >= j2) cout << "Yes"; else cout << "No"; cout << '\n';
    if (j1 > j2) cout << "Yes"; else cout << "No"; cout << '\n';
    
}

