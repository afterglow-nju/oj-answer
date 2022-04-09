#include <iostream>
#include<algorithm>
#include<string>
using namespace std;
unsigned int f(std::string s, unsigned int base, unsigned int mod) {
    unsigned int rt = 0;
    for (auto i = 0; i < s.size(); i++)
        rt = ((unsigned long long)rt * base + s[i] - 'a') % mod;
    return rt;
}
int main()
{   
   
    int base, mod, k;
    cin >> base >> mod >> k;
    string s;
    bool flag = true;
    while (1&flag)
    {
        s = "";
        for (int i = 1; i <= 50; i++)
        {
            s += rand() % 26 + 'a';
            if (f(s, base, mod) == k)
            {
                cout << s;
                flag = false;
                break;
            }
        }
    }

}

