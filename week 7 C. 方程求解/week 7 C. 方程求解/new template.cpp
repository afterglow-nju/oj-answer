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
using namespace std;
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
    int k;
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

const long long MAXN = 2097153;
Complex x1[MAXN], x2[MAXN];
long long  s1[MAXN / 2], s2[MAXN / 2];
long long sum[MAXN];

long long v[5000001];
const int maxn = 500000;
int main()
{
	int T;
	cin >> T;
    v[0] = 0;
	for (int i = 1; i <= maxn; i++)
	{
		for (int j = 1; j * i <= maxn; j++)
		{
			v[j * i]++;
		}
	}
  //  for (int i = 0; i <= maxn; i++) { s1[i] = v[i]; s2[i] = v[i]; }
    int len1 = maxn + 1;
    int len2 = maxn + 1;
    int len = 1048576;
    while (len < len1 * 2 || len < len2 * 2) len *= 2;
    //cout << "len" << len << '\n';
    for (int i = 0; i < len1; i++) x1[i] = Complex(v[len1 - 1 - i], 0);
    for (int i = len1; i < len; i++) x1[i] = Complex(0, 0);

    fft(x1, len, 1);

    for (int i = 0; i < len; i++) x1[i] = x1[i] * x1[i];
    fft(x1, len, -1);
    for (int i = 0; i < len; i++) sum[i] = int (x1[i].x + 0.5);//不知道为什么，x是double
    //for (int i = 1; i <= 10; i++)cout <<"v=" <<v[i] << '\n';
   // for (int i = 1; i <= 10; i++)cout <<"sum="<< sum[i] << '\n';
    /*for (int i = 1; i <= MAXN; i++)
    {
        if (sum[i] == 0)
        {
            cout << i << '\n';
            break;
        }
    }*/
	while (T--)
	{
		int n;
		cin >> n;
		cout << sum[2*maxn-n] << '\n';//算完两式相乘后阶数是2*n，而sum[i]是第i位的系数，所以最终x^n的系数为2*maxn-n
	}
}






