// 最长子数列 yyc.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
#include<vector>
using namespace std;


int max(int* arr, int count) {
    int temp = arr[0];
    for (int i = 1; i < count; i++) {
        
        if (temp < arr[i]) {
            temp = arr[i];
        }
    }
    return temp;
}

int n[1000];

//int longest(vector <int> n)
//{  
 //   int j, i;
  //  if (j > i) {
  //      vector <int> L;
  //      L(j) = max(L(i), i) + 1
  //  }
//}
int numsSize = 10;
int lengthOfLIS_01(int* nums) {

    int lis[10];
    //    printf("OriginalArray:");
    //    printArray(nums, numsSize);
    //    // 此for循环只是为了log美观 无意义
    //    for (int i =0; i < numsSize; i++) {
    //        lis[i] = 0;
    //    }
    int i, j, result = 0;
    for (i = 0; i <10; i++) {
        lis[i] = 1;
        for (j = 0; j < i; j++) {
            if (nums[i] > nums[j] && lis[j] + 1 > lis[i]) {
                lis[i] = lis[j] + 1;
            }
        }
        result = result > lis[i] ? result : lis[i];
        //        printArray(lis, numsSize);
    }
    return result;
}

int main()
{  
 
    int a[12],d[12];
    int n,b,k=0,p,q,longest=9999999;
    cin>> b;
    for (int i = 1; i <= b; i++) {
        cin >> a[i];
    }
    for (int j = 1; j <= b; j++) {
        d[1]= 1;
        for (int i = 1; i <= j; i++) {
            if (a[j] > a[i]&&d[j]+1>(d[i])) {
                d[j] = d[i] + 1;
            }
        }
        k = k > d[j] ? k : d[j];
     
    }
    cin >> nums;
   cout<< lengthOfLIS_01(int* nums);









    for (int j = 1; j <= b; j++) {
        k = 1;
        for (int i = 1; i <= j; i++) {
            if (a[j] > a[i]) {
                k++;
            }
        }
        d[j] = k;
    }
    
    for (int j = 1; j <= b; j++) {
      //  cout << d[j];
    }
    for (int j = 1; j <= b; j++) {
        int i = 1;
        for (i; i <=j; i++) {
            p = d[1];
            if (d[i] >= p) {
                p = d[i];
                q = i;
                }
        }
      //  cout << d[i]<<"\n";
    //    if ((a[j] > a[i])) {
    //        longest = d[i] + 1;
     //   }
    }
   // cout << longest;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
