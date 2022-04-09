#include <iostream>
#include<stack>
using namespace std;
int pre[600], in[600];
int n;
stack<int> ans;
void pos(int pre_left, int pre_right, int in_left, int in_right)
{
    int i, j;
    ans.push(pre[pre_left]);
    for ( i = in_left; i <= in_right; i++)
    {
        if (pre[pre_left] == in[i])break;
    }
    j = (i-in_left+ 1) + pre_left;
    if(j<=pre_right&& i+1<=in_right)
         pos(j, pre_right, i + 1, in_right);
    if (pre_left + 1 <= j - 1 && in_left <= i - 1)
         pos(pre_left + 1, j - 1, in_left, i - 1);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> pre[i];
    for (int i = 1; i <= n; i++)cin >> in[i];
    pos(1, n, 1, n);
    while (!ans.empty())
    {
        cout << ans.top() << " ";
        ans.pop();
    }


}

/*
struct tree
{
    int key;
    tree* left;
    tree* right;
};

void find(int i,tree*node)
{
    int index = 0;
    for (int j = 1; j <= n; j++)
    {
        if (pre[i] == in[j])
        {
            index = j;
            break;
        }
    }


}
int main()
{
    tree* root;/*
    root->key = 1;
    tree*a=new tree;
    a->key = 12;
    root->left = a;

    cin >> n;
    for (int i = 1; i <= n; i++)cin >> pre[i];
    for (int i = 1; i <= n; i++)cin >> in[i];
    root->key = pre[1];
    for (int i = 1; i <= n; i++)
    {
        int index = 0;
        for (int j = 1; j <= n; j++)
        {
            if (pre[i] == in[j])
            {
                index = j;
                break;
            }
        }

    }
}*/

