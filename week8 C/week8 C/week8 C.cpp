#include <iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<math.h>
using namespace std;
struct ip
{
    int ip[4];
    int zi[4];
    int wang[4];
    long long num;
};
ip c[10010];
void inpu(ip& a)
{
    scanf("%d.%d.%d.%d", &a.ip[0], &a.ip[1], &a.ip[2], &a.ip[3]);
    //cin >> a.ip[0] >> a.ip[1] >> a. ip[2] >> a.ip[3];
   // cout << a.ip[0];
    scanf("%d.%d.%d.%d", &a.zi[0], &a.zi[1], &a.zi[2], &a.zi[3]);
}
void an(ip& a)//&&
{
    for (int i = 0; i < 4; i++)
    {
        a.wang[i] = a.ip[i] & a.zi[i];
    }

}

bool compare(ip a, ip b) {

    if (a.wang[0] != b.wang[0])
    {
        if (a.wang[0] < b.wang[0]) return true;
        else return false;
    }
    else if (a.wang[1] != b.wang[1])
    {
        if (a.wang[1] < b.wang[1]) return true;
        else return false;
    }
    else if (a.wang[2] != b.wang[2])
    {
        if (a.wang[2] < b.wang[2])return true;
        else return false;
    }
    else if (a.wang[3] != b.wang[3])
    {
        if (a.wang[3] < b.wang[3])return true;
        else return false;
    }
    else if (a.zi[0] != b.zi[0])
    {
        if (a.zi[0] < b.zi[0])return true;
        else return false;
    }
    else if (a.zi[1] != b.zi[1])
    {
        if (a.zi[1] < b.zi[1])return true;
        else return false;
    }
    else if (a.zi[2] != b.zi[2])
    {
        if (a.zi[2] < b.zi[2])return true;
        else return false;
    }
    else if (a.zi[3] != b.zi[3])
    {
        if (a.zi[3] < b.zi[3])return true;
        else return false;
    }
    //  return true;
}

void num(ip& a)
{
    int count = 0;
    for (int i = 0; i < 4; ++i)
    {
        int n = a.zi[i];
        while (n > 0)
        {
            n = n & (n - 1);
            count++;
        }
    }//??1???
    int m = 32 - count;//??0???
    a.num = pow(2, m) - 2;

}
bool unique_(const ip& a, const ip& b)
{
    return (a.wang[0] == b.wang[0]) && (a.wang[1] == b.wang[1]) && (a.wang[2] == b.wang[2]) && (a.wang[3] == b.wang[3]) && (a.zi[0] == b.zi[0]) && (a.zi[1] == b.zi[1]) && (a.zi[2] == b.zi[2]) && (a.zi[3] == b.zi[3]);
}
//vector<int>ip[65];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        inpu(c[i]);

    }
    for (int i = 0; i < n; i++)
    {
        an(c[i]);
        num(c[i]);
    }
    sort(c, c + n, compare);
    int all = unique(c, c + n, unique_) - c;
    //int all=4;
    for (int i = 0; i < all; i++)
    {
        cout << c[i].wang[0] << "." << c[i].wang[1] << "." << c[i].wang[2] << "." << c[i].wang[3];
        cout << " " << c[i].num << '\n';
    }
}