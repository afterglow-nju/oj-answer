#include <iostream>
#include <time.h> 
#include<iomanip>
using namespace std;
long long a[600], b[600], c[600], d[600], r[501][501];
long long mod = 1e9 + 7;
struct FastIO {
    static const int S = 1e7;
    int wpos;
    char wbuf[S];
    FastIO() : wpos(0) {}
    inline int xchar() {
        static char buf[S];
        static int len = 0, pos = 0;
        if (pos == len)
            pos = 0, len = fread(buf, 1, S, stdin);
        if (pos == len) exit(0);
        return buf[pos++];
    }
    inline int xint() {
        int s = 1, c = xchar(), x = 0;
        while (c <= 32) c = xchar();
        if (c == '-') s = -1, c = xchar();
        for (; '0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
        return x * s;
    }
    inline void wchar(int x) {
        if (wpos == S) fwrite(wbuf, 1, S, stdout), wpos = 0;
        wbuf[wpos++] = x;
    }
    inline void wstring(const char* s) {
        while (*s) wchar(*s++);
    }
    ~FastIO() {
        if (wpos) fwrite(wbuf, 1, wpos, stdout), wpos = 0;
    }
} io;
long long n;

int main()
{
    long long t;
    t = io.xint();
    while (t--)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));//初始化！！！！！！！！！！！！！！！！！！！！！！！！！！！！
        memset(d, 0, sizeof(d));
        memset(r, 0, sizeof(r));
        srand(time(0));
        n = io.xint();
        for (int i = 1; i <= n; i++)
        {
            a[i] = rand();
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int t;
                t = io.xint();
                r[i][j] = t;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int t;
                t = io.xint();
                b[i] = (b[i] + t * a[j]) % mod;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                c[i] = (c[i] + r[i][j] * b[j]) % mod;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int t;
                t = io.xint();
                d[i] = (d[i] + t * a[j]) % mod;
            }
        }
        bool f = true;
        for (int i = 1; i <= n; i++)
        {
            if (c[i] != d[i]) { f = false; break; }
        }
        if (f) io.wstring("true\n");
        else io.wstring("false\n");
    }
}


/*
#include <iostream>
#include <time.h> 
using namespace std;
long long a[600],b[600],c[600],d[600],r[501][501];
struct FastIO {
    static const int S = 1e7;
    int wpos;
    char wbuf[S];
    FastIO() : wpos(0) {}
    inline int xchar() {
        static char buf[S];
        static int len = 0, pos = 0;
        if (pos == len)
            pos = 0, len = fread(buf, 1, S, stdin);
        if (pos == len) exit(0);
        return buf[pos++];
    }
    inline int xint() {
        int s = 1, c = xchar(), x = 0;
        while (c <= 32) c = xchar();
        if (c == '-') s = -1, c = xchar();
        for (; '0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
        return x * s;
    }
    inline void wchar(int x) {
        if (wpos == S) fwrite(wbuf, 1, S, stdout), wpos = 0;
        wbuf[wpos++] = x;
    }
    inline void wstring(const char* s) {
        while (*s) wchar(*s++);
    }
    ~FastIO() {
        if (wpos) fwrite(wbuf, 1, wpos, stdout), wpos = 0;
    }
} io;
long long n;

int main()
{
    long long t; 
  //  t=io.xint();
    cin >> t;
 srand((unsigned)time(0));
    while (t--)
    {
       
        // n=io.xint();
       cin >> n;
        for (int i = 1; i <= n; i++)
        {
            a[i] = rand();
            //io.wstring('a[i]');
        }
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int t;
              //  t= io.xint();
                cin >> t;
                r[i][j] = t;
               // b[i] += t * a[j]%mod;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int t;
            //    t = io.xint();
                cin >> t;
                b[i] += t * a[j];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                c[i] += r[i][j] * b[j];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int t;
              //  t= io.xint();
                cin >> t;
                d[i] += t * a[j];
            }
        }
        bool f = true;
        for (int i = 1; i <= n; i++)
        {
            if (c[i] != d[i]) { f = false; break; }
        }
        if (f) cout << "true" << '\n';//io.wstring("true");
        else cout << "false" << '\n';//io.wstring("false");//
    }
}
*/