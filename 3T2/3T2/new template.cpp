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
using namespace std;


int a[40001];
int s[60001];
int b[40001];
int ab[100000];
int read() {
    int ans = 0; char c = getchar();
    while (c < '0' || c>'9') c = getchar();
    while (c >= '0' && c <= '9') ans = (ans * 10 + c - 48), c = getchar();
    return ans;
}
int main()
{
	int n, S;
    cin >> n >> S; 
    int index = 0;
	for (int i = 1; i <= n; ++i)
    {
        int tem;
        tem=read();
        if (tem < S)
            a[++index] = tem;
	}
   // n = index;
	//if(n <= 300)
	{
		for (int i = 1; i <=index; ++i)
		{
            for (int j = i + 1; j <= index; ++j)
            {
                int temm1 = a[i] + a[j];
                if (temm1 < S)
                {
                    for (int k = j + 1; k <= index; ++k)
                    {
                        int tem = temm1 + a[k];
                        if (tem <= S)
                        {
                            ++s[tem];
                        }
                    }
                }
            }
		}
		for (int i = 1;i <= S;i++)
		{
			cout << s[i] << " ";
		}
	}
	
}






