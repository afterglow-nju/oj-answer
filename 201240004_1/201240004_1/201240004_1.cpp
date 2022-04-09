#include <iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

bool comp_as(int  a, int b)
{
    if (a <= b) { return true; }
    else {return false;
}
//    return a < b;
}
bool comp_des(int a, int b)
{
    if (a >= b) { return true; }
    else
    {return false;}
}
void mergesort(int arr[], int le, int m, int ri, bool (*compr)(int x,int y))
{
    int i, j, k;
    int n1 = m - le + 1;
    int n2 = ri - m;
   // vector<int>L(n1, 0);
    int L[101] = { 0 }, R[101] = { 0 };
   // memset(L, 0, sizeof(L));
   // memset(R, 0, sizeof(R));
    //vector<int>R(n2, 0);
    for (i = 0; i < n1; i++) L[i] = arr[le + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = le;
    while (i < n1 && j < n2)
    {
        if((*compr)(L[i], R[j]))//if ((*compr)(L[i], R[i]))//L[i] <= R[j]
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        k++;
        j++;
    }
}

void merge(int arr[], int s, int e, bool (*compr)(int x, int y))
{

    if (s < e)
    {
        int m = s + (e - s) / 2;
        merge(arr, s, m, (*compr));
        merge(arr, m + 1, e, (*compr));
        mergesort(arr, s, m, e, (*compr));
    }
}


int main()
{
    int n;//n=total number;
    cin >> n;
    int arr1[100], arr2[100];
  //  vector<int> arr1(n, 0);
  //  vector<int> arr2(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
        arr2[i] = arr1[i];
    }
    merge(arr1, 0, n - 1,comp_as);
    merge(arr2, 0, n - 1,comp_des);
    for (int i = 0; i < n; i++) cout << arr1[i] << " ";
    cout << '\n';
    for (int i = 0; i < n; i++) cout << arr2[i] << " ";
}


