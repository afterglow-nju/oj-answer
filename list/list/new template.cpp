#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<bitset>
#include<stack>
#include<utility>
#include<iomanip>
#include<vector>
#include<math.h>
#include<string>
#include<stdio.h>
#include<limits>
using namespace std;
struct listnode
{
	int val;
	listnode* next;
	listnode(int x) :val(x), next(nullptr) {}
};
listnode* dele(listnode* head,int val)
{//设置一个虚拟头结点
	listnode *dummyhead = new listnode(0);
	dummyhead->next = head;
	listnode* tem = dummyhead;
	while (tem->next != nullptr)
	{
		if (tem->next->val == val)
		{
			listnode* de = tem->next;
			tem->next = tem->next->next;
			delete de;
		}
		else
		{
			tem= tem->next;
		}
	}
	head = dummyhead->next;
	return head;
}
int main()
{
	listnode* head =new listnode(1);
	delete head;
}






#include<assert.h>
class MyLinkedList {
public:
    struct node
    {
        int val;
        node* next;
        node(int x) :val(x), next(nullptr) {}
    };
    MyLinkedList() {
        dummy = new node(0);
        size = 0;
    }

    int get(int index) {
        if (index > (size - 1) || index < 0) return -1;
        node* tem = dummy->next;
        for (int i = 0; i < index; i++)
        {
            tem = tem->next;
        }
        return tem->val;
    }

    void addAtHead(int val) {
        node* newone = new node(val);
        newone->next = dummy->next;
        dummy->next = newone;
        size++;
    }

    void addAtTail(int val) {
        node* tem = dummy;
        while (tem->next != nullptr)
        {
            tem = tem->next;
        }
        node* newone = new node(val);
        tem->next = newone;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index > size) return;
        //if (index <= 0) { addAtHead(val); return; }
        //if (index == size) { addAtTail(val); return; }
        node* tem = dummy;
        for (int i = 0; i < index; i++)
        {
            tem = tem->next;
        }
        node* newone = new node(val);
        newone->next = tem->next;
        tem->next = newone;
        size++;
        return;
    }

    void deleteAtIndex(int index) {
        if (index >= 0 && index < size)
        {
            size--;
            node* tem = dummy;
            // int t=index-1;
            for (int i = 0; i < index; i++)
            {
                tem = tem->next;
            }
            node* de = tem->next;
            if (de != nullptr)
                tem->next = de->next;
            else tem->next = nullptr;
            delete de;
        }
        else
        {
            return;
        }
    }
private:

    int size;
    node* dummy;

};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */