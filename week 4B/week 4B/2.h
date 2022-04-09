#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string.h>
#include <string>
using namespace std;

int d[110],s[33],w[16];
int l,j;

void subset(int n)
{
	if (n==0)
	{ // 2 to 10 
	    int sz,i,yushu,t;
	    int e[l+1];
	    for (int p=0;p<=l;p++) e[p]=d[p];
	    i=1;
	    sz=0;
        while (i<=l)
	    { 
            yushu=0;
            for(int h=i;h<=l;h++)
			{
                t=(e[l+1-h]+yushu*2)%10;
                e[l+1-h]=(e[l+1-h]+yushu*2)/10; 
                yushu=t;
            }
            sz++;
            s[sz]=yushu; 
            while (e[l+1-i]==0) i++; 
        }
        for (int i=sz;i>0;i--) cout << s[i];
		cout << " "; 
	}
	else
	{
		d[w[n]]=0;
		subset(n-1);
		d[w[n]]=1;
		subset(n-1);
	}
}

int main()
{
    int x,xx,f,k,zero,p,changdu;
    j=0;
    string a[33];
    int b[33],c[110];
    for (int i=0;i<=109;i++)
    {
    	c[i]=0;
    	d[i]=0;
	}
	d[0]=1;
	for (int i=0;i<=32;i++) s[i]=0;
    string y;
    cin >> y;
    changdu=y.length();
    for (int i=1;i<=changdu;i++) a[i]=y.substr(i-1,1);
    for (int i=1;i<=changdu;i++)
    {
        stringstream ss;
        ss << a[i];
        ss >> b[i];
	}
	// string to int
	
	f=0;
	k=0;
	while(f==0)
	{
     	x=0;
    	for (int i=1;i<=changdu;i++)
    	{
	    	xx=b[i]%2;
			b[i]=(x*10+b[i])/2;
			x=xx;
    	}
    	k++;
	    c[k]=x;	
	    f=1;
	    for (int i=1;i<=changdu;i++)
		{
	    	if (b[i]!=0) f=0;
		}
	}
	cout << c[1] << c[2];
	// 10 to 2
	// c[i]倒序存放二进制数 
	
	l=109;
	zero=0;
	while (zero==0)
	{
		if (c[l]==1) zero=1;
		else l--;
	}
	// l为二进制数的位数 (或许可以省略？） 
	
	for (int i=1;i<=l;i++)
	{
		if (c[i]==1)
		{
			j++;
			w[j]=i;
		}
	}
	// j为1的个数，w[i]为1的坐标 
//	subset(j);
    return 0;
}
