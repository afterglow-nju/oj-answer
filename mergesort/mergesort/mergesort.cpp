#include <iostream>
#include<algorithm>
#include<vector>
const int N = 5;
using namespace std;
void mergesort(vector<int> &arr,int le,int m,int ri)
{
    int i, j, k;
    int n1 = m - le + 1;
    int n2 = ri - m;
    vector<int>L(n1, 0);
    vector<int>R(n2, 0);
    for (i = 0; i < n1; i++) L[i] = arr[le+ i];
    for (j = 0; j < n2; j++) R[j] = arr[m+1 + j];
    i = 0; 
    j = 0;
    k = le;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
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



void merge(vector<int>& arr,int s,int e)
{   

    if (s <e)
    {
        int m = s + (e - s) / 2;
        merge(arr,s, m);
        merge(arr,m + 1, e);
        mergesort(arr,s, m, e);
    }
}
int main()
{
    int n;//n=total number;
    cin >> n;
    vector<int> arr(n,0);
    for (int i = 0; i < n; i++) cin >> arr[i];
    merge(arr,0,n-1);
    for (int i = 0; i < n; i++) cout << arr[i]<<" ";
    cout << '\n';
    for (int i = 0; i <n; i++) cout << arr[i] << " ";
}


/*

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int>L(n1, 0);
    vector<int>R(n2, 0);

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
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
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}


int main()
{
    for (int i = 0; i < N; i++) cin >> arr[i];
    mergeSort(arr,0, N - 1);
    // for (int i = 0; i < N; i++) cout << f[i]<<" ";
     //cout << '\n';
    for (int i = 0; i < N; i++) cout << arr[i] << " ";
}
*/