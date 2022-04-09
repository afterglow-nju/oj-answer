#include<iostream>
using namespace std;
struct node
{
	int value;
	node* next;
};
void input(node*& head,int n)
{	
	int* q =new int [n+1];

	for (int i = 1; i <= n; i++)
	{
		cin >> q[i];
	}
	for (int i = n; i >= 1; i--)
	{
		node* p = new node;
		p->value = q[i];
		p->next = head;
		head = p;
	}
	delete[]q;
}
void output(node*& head, int n)
{
	node* cur = head;
	for (int i = 1; i <= n; i++)
	{
		cout << cur->value<<" ";
		cur = cur->next;
	}
}
void free(node*& head, int n)
{
	node* cur = head;
	for (int i = 1; i <= n; i++)
	{
		node* p = cur;
		cur = cur->next;
		delete p;
	}
}
int main()
{
	node* head=NULL;
	int n;
	cin >> n;
	input(head, n);
	output(head, n);
	free(head, n);
	
}