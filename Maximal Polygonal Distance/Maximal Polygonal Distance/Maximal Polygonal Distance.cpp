#include <iostream>
#include<math.h>
#include<iomanip>
using namespace std;
struct node
{
    long long  x;
    long long  y;
}d[100001];
double line(long long x1, long long y1, long long x2, long long y2)
{   
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
bool judge(long long x, long long y,double k,long long n)
{   
   // v a;
  //  a.x=(d[x].x-d[x])
   /* double temp1 = asin(((d[x].x -d[x-1].x)* (d[x + 1].x -d[x].x)+ (d[x].y - d[x -1].y)*(d[x+1].y-d[x].y)) / (line(d[x].x, d[x].y, d[x - 1].x, d[x - 1].y) * line(d[x].x, d[x].y, d[x + 1].x, d[x + 1].y)));
    double temp2= asin(((d[x].x - d[ x- 1].x) * (d[y+1].x - d[y].x) + (d[x].y - d[x - 1].y) * (d[y + 1].y - d[y].y)) / (line(d[x].x, d[x].y, d[x - 1].x, d[x - 1].y) * line(d[y].x, d[y].y, d[y + 1].x, d[y+ 1].y)));
    if (temp1 < 0) temp1 += acos(-1);
    if (temp2 < 0) temp2 += acos(-1);*/
    bool f = false;
    double tan_ = 0;
    if (k == 1.79e308) tan_=acos(0),f=true;
    double temp1 = 0,temp2=0;
    double k1=atan(k);
    if (k1< 0) k1 += acos(-1);

   if (d[x].x - d[x + 1].x == 0) temp1 = abs(acos(0) - k1);//temp1 = 1.79e308;
   else
   {
       double minus1 = atan((d[x].y - d[x + 1].y) / (d[x].x - d[x + 1].x));
       if (minus1 < 0) minus1 += acos(-1);
       if (f == false) temp1 = abs(k1 -minus1); 
       else temp1 = abs(tan_ - minus1);
   }
   if (d[y].x - d[(y + 1) % n].x == 0) temp2 = abs(acos(0) - k1);// temp2 = 1.79e308;
   else
   {    
       double minus2 = atan((d[y].y - d[(y + 1) % n].y) / (d[y].x - d[(y + 1) % n].x));
       if (minus2 < 0) minus2 += acos(-1);
       if (f == false) temp2 = abs(k1 -minus2);
       else temp2 = abs(tan_ - minus2);
   }
    if (temp1 < temp2) return true;
    else return false;
    
}
int main()
{
   // cout << atan(-1);//+2*acos(-1);
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++)
    {
        cin >> d[i].x>>d[i].y;
    }

    double k,ji;
    long long mark1;
    if (d[0].x - d[1].x == 0) k = 1.79e308,ji= 1.79e308;
    else
    {
        k = (d[0].y - d[1].y) / (d[0].x - d[1].x);
        ji = -1 * k * d[1].x + d[1].y;
    }
    mark1 = 1;
    double far = 0;
    long long mark2;
    for (long long i = 0; i < n; i++)
    {
        double temp = -1 * k * d[i].x + d[i].y;//ll->double
        double temp_ = abs(temp - ji);//ll->double
        if (far < temp_) { far = temp_, mark2 = i; }
    }
    double max_s = 0;
    for (long long i = 0; i < n*n; i++)//mark1=1
    {   
        int k = 1;
        if (i > k * n) mark2++, k++;
        mark1 = mark1%n;// 1th %n->n
        mark2 = mark2%n;
        bool f = judge(mark1, mark2, k,n);
        f = true;
        if (f)
        {
            double temp1= line(d[mark2].x, d[mark2].y, d[mark1].x, d[mark1].y);
            double temp2 = line(d[mark2].x, d[mark2].y, d[(mark1+1)%n].x, d[(mark1+1)%n].y);
            double temp3 = max(temp1, temp2);
            if (max_s < temp3) max_s = temp3;//cout<<max_s<<" "<<temp3<<'\n',

           /* if (d[mark1].x == d[(mark1 + 1)%n].x) k = 1.79e308;
            else
            {
                k = (d[mark1].y - d[(mark1 + 1)%n].y) / (d[mark1].x - d[(mark1 + 1)%n].x);
            }
            */

            if (d[mark1].x == d[(mark1 + 1)%n].x) k = 1.79e308;
            else
            {
                k = (d[mark1].y - d[(mark1 + 1)%n].y) / (d[mark1].x - d[(mark1 + 1)%n].x);
            }
            mark1++;
        }
        
        else
        {
            double temp1 = line(d[mark2].x, d[mark2].y, d[mark1].x, d[mark1].y);
          //  double temp2 = line(d[mark2 + 1].x, d[mark2 + 1].y, d[mark1].x, d[mark1].y);
            double temp2 = line(d[(mark2+1) % n].x, d[(mark2+1) % n].y, d[mark1].x, d[mark1].y);
            double temp3 = max(temp1, temp2);
            if (max_s < temp3)max_s = temp3;// cout << max_s << " " << temp3 << '\n',

            if (d[mark2].x == d[(mark2+1)%n].x) k = 1.79e308;
            else
            {
                k = (d[mark2].y - d[(mark2 + 1)%n].y) / (d[mark2].x - d[(mark2 + 1)%n].x);
            }
            mark2++;
        }
       // cout << max_s<<" ";
    }//mod n;
    cout << fixed<<setprecision(30)<<max_s;


}

