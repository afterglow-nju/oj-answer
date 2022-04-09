#include <iostream>
using namespace std;
int plate[51][2000];
int f[51][2000];
int main()
{
    int n, k, p;
    cin >> n >> k >> p;
    for (int i = 1; i <= n; i++)
    {   
        int pre = 0;
        for (int j = 1; j <= k; j++)
        {
            cin>>plate[i][j];
            pre += plate[i][j];
            plate[i][j] = pre;
        }
    }
    for (int i = 1; i <= n; i++)
    {
         for (int c = 0; c <= p; c++)
         //for (int j = 1; j <= k; j++)
         {
             for (int j = 1; j <= k; j++)
             // for (int c = 0; c <= p; c++)
              {
                 if (f[i][c] == 0)
                 {
                     f[i][c] = f[i - 1][c];
                 }
                 if (c>=j)
                 {  
                     //if (i == 1 && c == 1)cout <<f[i-1][c-j] <<" "<<plate[i][j]<<'\n';
                    f[i][c] = max(f[i][c], f[i - 1][c - j] + plate[i][j]);
                   // cout << f[1][1] << '\n';
                 }
                
              }
         }

      
    }
   // cout << f[n][0]<<f[n][1];
    /*
    for (int i = 1; i <= n; i++)
    {
      //  int pre = 0;
        for (int j = 1; j <= p; j++)
        {
            cout << f[i][j] << " ";
        }
        cout << '\n';
    }*/
    cout << f[n][p];
}
//f[n][p]
