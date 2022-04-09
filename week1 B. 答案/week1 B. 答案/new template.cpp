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
char q[60];
int iindex = -1;
void hint(char * out)
{
	for (int i = 0; i <= iindex; i++)
	{
		cout << out[i];
	}
}
int main()
{	

	char tem;
	char qback[60];
	char aeiou[10] = { 'a','e','i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
	while (1)
	{
		tem = getchar();
		if (tem != '\n')
		{
			q[++iindex] = tem;
			qback[iindex] = tem;
		}
		else break;
	}
	int num = 0;
	for (int i = 0; i <= iindex; i++)
	{
		if ((q[i] >= 'a' && q[i] <= 'z') || (q[i] >= 'A' && q[i] <= 'Z'))
		{
			q[i] = '.';
			num++;
		}
	}
	
	hint(q);
	double numm = (double)num / 3;
	int hint2 = 0;
	int inte = num / 3;
	float tnnd = numm - inte;
	if (tnnd<= 0.5)hint2 = inte;
	else hint2 = inte + 1;
	
	int ae = 0;
	for (int i = 0; i <= iindex; i++)
	{
		if ((qback[i] >= 'a' && qback[i] <= 'z') || (qback[i] >= 'A' && qback[i] <= 'Z'))
		{
			if (hint2 <= 0)
			{
				ae = i;
				break;
			}
			q[i] =qback[i];
			hint2--;
		}
	}
	cout << '\n';
	hint(q);
	bool flag = 0;
	for (int i = ae; i <= iindex; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (aeiou[j] == qback[i])
			{
				q[i] = qback[i];
				flag = 1;
			}
		}
	}
	cout << '\n';
	if (flag)hint(q);
	else
	{
		double numm = 2*(double)num / 3;
		//cout << numm;
		int hint3 = 0;
		int inte = 2*num / 3;
		float tnnd = numm - inte;
		if (tnnd<= 0.5)hint3 = inte;
		else hint3 = inte + 1;
	//	cout << inte<<" "<<numm;
		for (int i = 0; i <= iindex; i++)
		{
			if (hint3>0&&((qback[i] >= 'a' && qback[i] <= 'z') || (qback[i] >= 'A' && qback[i] <= 'Z')))
			{
				
				q[i] = qback[i];
				hint3--;
			}
		}
		hint(q);
	}

	
}






