#include <iostream>  
#include <algorithm>  
using namespace std;
int main()
{
    int num[11];
    int i = 1;
    num[0] = 1;
    while (num[i - 1] != -1)
    {
        cin >> num[i];
        i++;
    }
    do
    {
        for (int j = 1; j <= i - 2; j++) cout << num[j];
        cout << " ";
    } while (next_permutation(num+1, num + i-1));
    return 0;
}