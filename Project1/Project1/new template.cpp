#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include<ctime>
using namespace std;
#include <stdlib.h>
int a[10000];
int evalRPN(char** tokens, int tokensSize) {

    int index = 0;

    for (int i = 0; i < tokensSize; i++)
    {
        char* token = tokens[i];
        //char* token = tokens[i];
        if (token[0] == '+')
        {
            a[index - 1] = a[index] + a[index - 1];
            a[index] = 0;
            index--;
        }
        else if (token[0] == '-')
        {
            a[index - 1] = a[index - 1] - a[index];
            a[index] = 0;
            index--;
        }
        else if (token[0] == '*')
        {
            a[index - 1] = a[index] * a[index - 1];
            a[index] = 0;
            index--;
        }
        else if (token[0] == '/')
        {
            a[index - 1] = a[index - 1] / a[index];
            a[index] = 0;
            index--;
        }
        else
        {
            a[++index] = atoi(token);
        }
    }

    return a[index];
}
int main()
{   
    char** tokens;
    tokens = { "2", "1", "+", "3", "*" };

}
