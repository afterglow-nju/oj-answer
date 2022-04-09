#include <iostream>

using namespace std;
int main()
{
    int t, k, n;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> k >> n;
        if (n % 2 != 0) cout << k<<'\n';
        else
        {   
            int jishu = 1;
            n = n / 2;
            while (n % 2 == 0)
            {
                n = n / 2;
                jishu++;
            }
            cout << k - jishu<<'\n';
        }
    }
}

