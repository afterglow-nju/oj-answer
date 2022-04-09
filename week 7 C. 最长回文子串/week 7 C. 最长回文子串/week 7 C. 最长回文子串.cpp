#include <iostream>

using namespace std;

char s[2000001];
int ans = 0, n;
int left_length, right_length;
void dc(int length)
{
   // cout << length << " ";
    bool f = false;
    if (length == 0) { ans = 0; return; }
    //if(length==n)
    for (int i = 1; i <= n + 1 - length; i++)
    {
        int left = i, right = length + i - 1;
        while (s[left] == s[right] && left < right)
        {
            left++;
            right--;
        }//i-x>=m
        if (left == right)
        {
            // cout << length << " " << left << '\n';
            f = true;
            break;
        }

    }
    if (f)
    {
        f = false;
        ans = length;
        left_length = length;
        if ((right_length - length) / 2 == 0)
        {
            ans = right_length;
            return;
        }
        else
        {
            dc((length + right_length) / 2);
        }
    }
    else
    {
        right_length = length;
        ans = length;
        if ((length - left_length) / 2 == 0)
        {
            ans = left_length;
            return;
        }
        else
        {
            dc((length + left_length) / 2);
        }
    }

}
int main()
{   
    char c='a';
    int i = 1;
    while ((c = getchar()) != '\n')
    {
        s[i] = c;
        i++;
    }
    i--;
    n = i;
    right_length = n;
    left_length = 1;
    dc(n);
    cout <<'\n'<< ans;
}
