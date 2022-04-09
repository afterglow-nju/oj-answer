#include <iostream>
#include<string.h>
#include<cstring>
#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;
using namespace std;

int k;
char buf[512], a[512], b[512], c[512];
map<string, string> m;

string typeof(string str) {
    for (char ch : str) if (ch == '"') return "string"; else if (ch == '.') return "float";
    return "integer";
}

void printval(string x) {
    cout << x << '(' << typeof(x) << ')' << endl;
}

int main() {
    int n; scanf_s("%d\n", &n);
    while (n--) {
        gets_s(buf);
        k = sscanf_s(buf, "%s %s %s", a, b, c);
        if (strcmp(a, "GET") == 0) {
            if (m.find(string(b)) == m.end()) cout << "None" << endl;
            else printval(m[string(b)]);
            cout << endl;
        }
        else if (strcmp(a, "SET") == 0) {
            m[string(b)] = string(c);
        }
        else if (strcmp(a, "GETALL") == 0) {
            for (auto kvp : m)
                if (k == 1 or typeof(kvp.second) == string(c))
                    cout << kvp.first << ':', printval(kvp.second);
            cout << endl;
        }
    }
    return 0;
}
/*char c[100][51], a[100][51], b[100][51];//a操作 b读入类型 c读入数据
char save[100][51], t[100][51], ty[100],z[100][51];

int main()
{   
    cin >> save[0] >> save[1];
    cout << save[0] << save[1];
    int q1 = strlen(save[0]);
    int q2 = strlen(save[1]);
    for (int i = 0; i <= q1 - 1; i++)
    {
        z[0][i] = save[0][i];
    }
    for (int i = 0; i < q2; i++)
    {
        save[0][i] = save[1][i];
    }
    for (int i = 0; i < q1; i++)
    {
        save[1][i] = z[0][i];
    }
    for (int i = min(q1, q2); i <= max(q1, q2); i++)
    {
        save[0][i] = ' ';
        remove(save[1][1], save[1][2],20);
    }
    int n;
    cin >> n;
    int total = 0;
    for (int i = 1; i <= n; i++)
    {
        //cout << t[0][0] << t[0][1] << t[0][2] << t[0][3] << t[0][4] << "AA";
        cin >> a[i];
        if (a[i][0] == 'S')
        {
            cin >> b[i];
            int s = strlen(b[i]);
            bool f = false;
            int jj = 0;
            for (int j = 0; j <= total-1; j++)
            {
                f = true;
                for (jj = 0; jj <= s - 1; jj++)
                {
                    if (b[i][jj] != save[j][jj])
                    {
                        f = false;
                        break;
                    }
                }
                if (f)
                {
                    cin >> c[i];
                    // cout << c[i]<<"b"<<c[i][0];
                    int s = strlen(c[i]);
                    for (int num = 0; num <= s; num++)t[j][num] = c[i][num];//, cout << c[j][num]<<"AA";//根据jj找到哪一个
                    if (c[i][1] >= 'a' && c[i][1] <= 'z') ty[j] = 1;
                    else
                    {
                        bool f = false;
                        for (int j = 0; j <= s - 1; j++)
                        {
                            if (c[i][j] == '.')
                            {
                                f = true; break;
                            }
                        }
                        if (f) ty[j] = 2;
                        else ty[j] = 3;//1== string 2== float 3== int
                    }
                    break;
                }
                // for (int num = 0; num <= s; num++)cout << t[j][num] << "AA";
            }
            if (f == false)
            {
                cin >> c[i];
                for (int j = 0; j <= s - 1; j++)
                {
                    save[total][j] = b[i][j];
                }
                // cout << b[i];
                for (int j = 0; j <= strlen(c[i]) - 1; j++)  t[total][j] = c[i][j];
                if (c[i][1] >= 'a' && c[i][1] <= 'z') ty[total] = 1;
                else
                {
                    bool f = false;
                    for (int j = 0; j <= strlen(c[i]) - 1; j++)
                    {
                        if (c[i][j] == '.')
                        {
                            f = true; break;
                        }
                    }
                    if (f) ty[total] = 2;
                    else ty[total] = 3;//1== string 2== float 3== int
                    
                }
                total++;
            }
        }
        else if (a[i][3] != 'A')
        { // cout << "AAA";
            cin >> b[i];
            int s = strlen(b[i]);
            bool f = true;
            for (int j = 0; j <= total; j++)
            {
                // cout << "qq";
                f = true;
                for (int q = 0; q <= s - 1; q++)
                {
                    if (b[i][q] != save[j][q])
                    {
                        f = false; break;
                    }
                    //   cout << "bbb";
                }
                if (f)
                {
                    //    cout << "CCC";
                        //printf_s("%s", t[j]);
                    cout << t[j];
                    if (ty[j] == 1) cout << "(string)";
                    if (ty[j] == 2) cout << "(float)";
                    if (ty[j] == 3) cout << "(integer)";
                    cout << '\n';
                    break;
                }
            }
            if (f == false) cout << "None" << '\n';
        }
        else if (a[i][7] != 'W')
        {
        for (int j = 0; j <= total - 2; j++)
        {
            
            for (int q = 0; q <= total - 2; q++)
            {
                for (int m = 1; m <= 51; m++)
                {
                    if (save[q][m] > save[q + 1][m])
                    {

                    }
                }
            }
        }




            for (int j = 0; j <= total - 1; j++)
            {
                cout << save[j] << ":" << t[j];
                if (ty[j] == 1) cout << "(string)";
                if (ty[j] == 2) cout << "(float)";
                if (ty[j] == 3) cout << "(integer)";
                cout << '\n';
            }
        }

    }
   // cout << total;
    
}
*/
