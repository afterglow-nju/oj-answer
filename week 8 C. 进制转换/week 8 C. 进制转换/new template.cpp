#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<bitset>
#include<stack>
#include<utility>
#include<iomanip>
#include<vector>
#include<math.h>
#include<string>
#include<stdio.h>
#include<limits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int M = 1600011;

const double PI = acos(-1.0);
struct Complex {
    double x, y;
    Complex(double _x = 0.0, double _y = 0.0) {
        x = _x;
        y = _y;
    }
    Complex operator-(const Complex& b) const {
        return Complex(x - b.x, y - b.y);
    }
    Complex operator+(const Complex& b) const {
        return Complex(x + b.x, y + b.y);
    }
    Complex operator*(const Complex& b) const {
        return Complex(x * b.x - y * b.y, x * b.y + y * b.x);
    }
};
/*
 * 进行 FFT 和 IFFT 前的反置变换
 * 位置 i 和 i 的二进制反转后的位置互换
 *len 必须为 2 的幂
 */
void change(Complex y[], int len) {
    int i, j, k;
    for (int i = 1, j = len / 2; i < len - 1; i++) {
        if (i < j) swap(y[i], y[j]);
        // 交换互为小标反转的元素，i<j 保证交换一次
        // i 做正常的 + 1，j 做反转类型的 + 1，始终保持 i 和 j 是反转的
        k = len / 2;
        while (j >= k) {
            j = j - k;
            k = k / 2;
        }
        if (j < k) j += k;
    }
}
/*
 * 做 FFT
 *len 必须是 2^k 形式
 *on == 1 时是 DFT，on == -1 时是 IDFT
 */
void fft(Complex y[], int len, int on) {
    change(y, len);
    for (int h = 2; h <= len; h <<= 1) {
        Complex wn(cos(2 * PI / h), sin(on * 2 * PI / h));
        for (int j = 0; j < len; j += h) {
            Complex w(1, 0);
            for (int k = j; k < j + h / 2; k++) {
                Complex u = y[k];
                Complex t = w * y[k + h / 2];
                y[k] = u + t;
                y[k + h / 2] = u - t;
                w = w * wn;
            }
        }
    }
    if (on == -1) {
        for (int i = 0; i < len; i++) {
            y[i].x /= len;
        }
    }
}

const int MAXN = 1600011;//350000
Complex x1[MAXN], x2[MAXN];
char str1[MAXN / 2];
int s[MAXN];
int A[21][M], Len[21];
int Rev[M];
int Data[M];
int Ans[M];
void Solve(int l, int r, int* Res, int& Len)
{
    //printf("yes\n");
    if (l == r) {
        Len = 0;
        int A = Data[l];
        while (A)
            Res[Len++] = A % 27, A /= 27;
        return;
    }
    int Llen, Rlen;
    int C = 0, B = 1;
    while (B < (r - l + 1)) B *= 2, C++;
    B /= 2, C--;
    int fd = 4 << (C + 1), L[4 << (C + 1)], R[4 << (C + 1)];
    for (int i = 0; i < fd; i++)L[i] = R[i] = 0;
    Solve(l, l + B - 1, L, Llen); Solve(l + B, r, R, Rlen);
    int t = C;
    int ll = 0, rr = 0;
    while ((1 << ll) < Llen)ll++;
    while ((1 << rr) < Llen)rr++;
    C = max(max(ll, rr), ::Len[C]) + 1;
    for (int i = 0; i < (1 << C); i++)
        x2[i] = { R[i],0 };
    for (int i = 0; i < (1 << C); i++)
        x1[i] = { A[t][i],0 };
    fft(x2, 1 << C, 1); fft(x1, 1 << C, 1);
    for (int i = 0; i < (1 << C); i++)
        x1[i] = x1[i] * x2[i];
    fft(x1, 1 << C, -1);
    for (int i = 0; i < (1 << C); i++)
        Res[i] = L[i] + (int)(x1[i].x + 0.5);
    Len = 0;
    for (int i = 0; i < (1 << C); i++)
        if (Res[i])
            Res[i + 1] += Res[i] / 27, Res[i] %= 27, Len = i + 1;
}
int main() {
    A[0][0] = 10, A[0][1] = 0;
    Len[0] = 1;
    for (int i = 1; i <= 18; i++) {
        int C = 0;
        C = Len[i] = Len[i - 1] + 1;
        if (i == 1) C = Len[i] = Len[i - 1];
        for (int j = 0; j < (1 << C); j++)
            x1[j].x = A[i - 1][j], x1[j].y = 0;
        fft(x1, 1 << C, 1);
        for (int j = 0; j < (1 << C); j++)
            x1[j] = x1[j] * x1[j];
        fft(x1, 1 << C, -1);
        for (int j = 0; j < (1 << C); j++)
            A[i][j] = (int)(x1[j].x + 0.5);
        for (int j = 0; j < (1 << C); j++)
         //   if (A[i][j]) A[i][j + 1] += A[i][j] / 243, A[i][j] %= 243;
            if (A[i][j]) A[i][j + 1] += A[i][j] / 27, A[i][j] %= 27;
    }


    cin >> str1;
    int len1 = strlen(str1);
    for (int i = 0; i < len1; i++)
        Data[i] = str1[len1 - i - 1] - '0';
    int tt;
    Solve(0, len1 - 1, Ans, tt);
    bool okay = 0;
    while (tt--) {
      //  if (okay || Ans[tt] / 81)putchar('0' + Ans[tt] / 81), okay = 1;
      //  if (okay || Ans[tt] / 27 % 3)putchar('0' + Ans[tt] / 27 % 3), okay = 1;
        if (okay || Ans[tt] / 9)putchar('0' + Ans[tt] / 9 % 3), okay = 1;
        if (okay || Ans[tt] / 3 % 3)putchar('0' + Ans[tt] / 3 % 3), okay = 1;
        if (okay || Ans[tt] % 3)putchar('0' + Ans[tt] % 3), okay = 1;
        //okay=0;
    }

}