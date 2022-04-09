#include <iostream>
#include<algorithm>
using namespace std;
	//cout << maxValue[n][m];
//int f[103][103];

int total_weight = 103;
	int w[6] = { 0,10,20,20,8,7 };
	int jiazhi[6] = { 0,17,42,35,16,15 };
	int num[6] = { 0,3,1,4,5,1 };
	int dp[104] = { 0 };
int f[103][6] = { 0 };

int main()
{
	
	//int mount[6] = { 0,3,1,4,5,1 };
	
	for (int i = 1; i <= 5; i++)
	{
		//int temp1 = dp[103];
		for (int k = 1; k <= num[i]; k++)
		{
			for (int j = 103; j >= w[i]; j--)
			{
				int temp = max(dp[j], dp[j - w[i]] + jiazhi[i]);
				if (dp[j] == temp);
				else
				{	
					for (int ii = 1; ii <= 5; ii++) f[j][ii] = f[j - w[i]][ii];
					f[j][i]++;
					dp[j] = temp;

				}
				
			}
		}
		//cout << dp[103] << " ";
	}
	

	//  cout << "总的价值为: " << dp[103] << endl;
	for (int i = 1; i <= 5; i++) cout << f[103][i] << " ";



}











