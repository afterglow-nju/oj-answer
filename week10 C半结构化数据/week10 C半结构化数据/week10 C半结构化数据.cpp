#include <iostream>
#include<algorithm>
#include<math.h>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
string type(string a)
{
    bool f = true;
    for (char ch : a)
    {

        if (ch == '"') { return "(string)"; break; }
        if (ch == '.') { f = false; break; }
    }
    if (f) { return "(integer)"; }
    else { return "(float)"; }
}
int main()
{
    map<string, string> bb, t;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string op, name, value;
        cin >> op;
        if (op == "SET")
        {
            cin >> name >> value;
            bb[name] = value;
        }
        if (op == "GET")
        {
            cin >> name;
            if (bb.find(name) == bb.end()) cout << "None" << endl;
            else { cout << bb[name]; cout << type(bb[name]); cout << '\n'; }
        }
        if (op == "GETALL")
        {

            if (getchar() == ' ')
            {
                cin >> op;
                cin >> op;
                if (op == "float")
                {
                    for (auto it : bb)
                    {
                        if (type(it.second) == "(float)")
                        {
                            // t[it.first] = it.second;
                            cout << it.first << ":" << it.second;
                            cout << type(it.second); cout << '\n';
                        }
                    }
                }
                if (op == "integer")
                {
                    for (auto it : bb)
                    {
                        if (type(it.second) == "(integer)")
                        {
                            // t[it.first] = it.second;
                            cout << it.first << ":" << it.second;
                            cout << type(it.second); cout << '\n';
                        }
                    }
                }
                if (op == "string")
                {
                    for (auto it : bb)
                    {
                        if (type(it.second) == "(string)")
                        {
                            // t[it.first] = it.second;
                            cout << it.first << ":" << it.second;
                            cout << type(it.second); cout << '\n';
                        }
                    }
                }
            }
            else
            {
                for (auto it : bb)
                {
                    cout << it.first << ":" << it.second;
                    cout << type(it.second); cout << '\n';
                }
            }
        }

    }
}
//10
//0 1 1 1 1 1 0 0 0 0
/* if (a[14] == 'f')
            {
                for (auto it : bb)
                {
                    if (type(it.second) == "float")
                    {
                        t[it.first] = it.second;
                    }
                }
                for (auto it : t)
                {
                    cout << it.first << ":" << it.second;
                    cout << type(it.second); cout << '\n';
                }
            }*/

