#include <iostream>
#include<algorithm>
#include<string>
using namespace std;
double a[5], t=0,c[13];
bool flag = false,b[5];
string s;
void dfs(int n)
{
    if (n == 4)
    {
        if (abs(t - 24) < 0.000000000001)
        {
            flag = true;
            for (int i = 2; i <= 4; i++)if (b[i] == true)cout << "A";
            return;
        }
        else return;
    }
    if (flag == false)
    {
        for (int i = 2; i <= 4; i++)
        {
            if (b[i])
            {
                t += a[i];
                b[i] = false;
                s = s + "+";
                dfs(n + 1);
                if (flag == false)
                {
                    s.erase(s.end() - 1);
                    b[i] = true;
                    t -= a[i];
                }
            }
            if (b[i])
            {
                t *= a[i];
                b[i] = false;
                s = s + "*";
                dfs(n+1);
                if (flag == false)
                {
                    s.erase(s.end() - 1);
                    b[i] = true;
                    t = t / a[i];
                }
            }
            if (b[i])
            {
                t -= a[i];
                b[i] = false;
                s = s + "-";
                dfs(n + 1);
                if (flag == false)
                {
                    s.erase(s.end() - 1);
                    b[i] = true;
                    t = t + a[i];
                }
            }
            if (b[i])
            {
                t = a[i]-t;
                b[i] = false;
                s = "-" + s;
                dfs(n+1);
                if (flag == false)
                {
                    s.erase(s.end() - 1);
                    b[i] = true;
                    t = a[i] - t;
                }
            }
            if (b[i])
            {
                t = t / a[i];
                b[i] = false;
                s = s + "/";
                dfs(n + 1);
                if (flag == false)
                {
                    s.erase(s.end() - 1);
                    b[i] = true;
                    t = t * a[i];
                }
            }
            if (b[i] && t != 0)
            {
                t = a[i] / t;
                b[i] = false;
                s = "/" + s;
                dfs(n + 1);
                if (flag == false)
                {
                    s.erase(s.end() - 1);
                    b[i] = true;
                    t = a[i] / t;
                }
            }

        }
    }
    else return;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
   
    
    {
        for (int i = 1; i <= 4; i++) { cin >> a[i]; b[i] = true; }
        sort(a + 1, a + 5);
        do 
        {
           // for (int i = 1; i <= 4; i++) { cout << a[i]; }
           // cout << '\n';
            
            t = a[1]; flag = false; b[1] = false;
           dfs(1);
           c[1] = a[1] + a[2];
           c[2] = a[3] + a[4];
           c[3] = a[1] - a[2];
           c[4] = a[3] - a[4];
           c[5] = a[2] - a[1];
           c[6] = a[4] - a[3];
           c[7] = a[1] * a[2];
           c[8] = a[3] * a[4];
           c[9] = a[1] / a[2];
           c[10] = a[3] / a[4];
           c[11] = a[2] / a[1];
           c[12] = a[4] / a[3];
           for (int i = 1; i <= 6; i++)
           {
               for (int j = 1; j <= 6; j++)
               {
                   double t1 = c[2*i-1], t2 = c[2*j];
                   t = t1 + t2;
                   if (abs(t - 24) < 0.000000000001) { flag = true; cout << "A" << i << " "<<j; }
                   else
                       t = t1 - t2;
                   if (abs(t - 24) < 0.000000000001) { flag = true; cout << "B" << t1 <<" "<< t2; }
                   t = t1 * t2;
                   if (abs(t - 24) < 0.000000000001) { flag = true; cout << "c" << t1 << " "<<t2; }
                   else if(t2!=0)
                       t = t1 / t2;
                   if (abs(t - 24) < 0.000000000001) { flag = true; cout << "D" << t1 << " " << t2; }
                   else if(t1!=0)
                       t = t2 / t1;
                   if (abs(t - 24) < 0.000000000001) { flag = true; cout << "E" << t1 << " " << t2; }
               }
           }
        } while (next_permutation(a+1, a + 5)&&flag==false);
        

    /*    for (int i = 1; i <= 4; i++) 
        {
            if (b[i] == true) cout << "A";
            else cout << "b";
        }*/
        if (flag)
        {
            cout << "true";
            //for (auto i : s)cout << i;
        }
        else cout << "false";
        cout << '\n';
    }
}

//精度要改成7位