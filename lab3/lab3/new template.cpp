#include<iostream>
#include<cstdio>
#include<ctime>
#include<cmath>
#define inf 100000001
using namespace std;
int n;
//bool a[inf + 1];
bool num[100000010] = { 1,1 };
//bool num[inf + 1] = { 1,1 };
int prime[6000010] = { 0 }, number = 0;

void kuaisushaifa()
{
	for (int i = 2; i <= n; ++i)
	{
		if (!num[i])
			prime[number++] = i;
		for (int j = 0; j < number && i * prime[j] <= n; j++)
		{
			num[i * prime[j]] = 1;
			if (!(i % prime[j]))
				break;
		}
	}
	//	end = clock();
		/*for(int i=0;i<number;i++)
		{
			if(i%10==0) printf("\n");
			printf("%3d",prime[i]);
		}  */
		//printf("¿ìËÙÉ¸·¨-Time used:%d ms\n", end - begin);
	return;
}

int main()
{
	int q;
	cin >> n >> q;
	kuaisushaifa();	//n = 10000000;
	for (int i = 1; i <= q; i++)
	{
		int k;
		cin >> k;
		cout << prime[k - 1] << '\n';;
		//for (int i = 0; i <= 1000000; i++)cout << prime[i] << " ";

	}

}