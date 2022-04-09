#include <iostream>
#include<algorithm>
#include<math.h>

using namespace std;
int s[30];

 int n, k, ans = 0, check;
 int f(int n,int k)
 {
     if (n == 1 && k > 0) return 2;
     else if (n == 1 && k == 0) return 1;
     else if (k == 0) return f(n - 1, k + 1);
     else return f(n - 1, k + 1) + f(n - 1, k - 1);
 }
int main()
{
   
    cin >> n >> k;
    check = k;
  //  bool f = true;
    
    cout << f(n,k);
  /*  for (int j = 0; j <= (n - k) / 2 + 1; j++)
    {   
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == 0)
            {
                check++;
            }
            else
            {
                check--;
                if (check < 0)
                {
                    f = true;
                    break;
                }
            }
        }
        if (f) ans++;
    }*/
}

