/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class List; // 前视定义,否则友元无法定义
class LinkNode
{

    friend class List; // 链表结点类的定义

private:
    LinkNode *link;

    int data;

public:
    LinkNode(LinkNode *ptr = NULL) { link = ptr; }

    LinkNode(const int &item, LinkNode *ptr = NULL)
    {
        data = item;
        link = ptr;
    }

    ~LinkNode(){};
};

class List
{ // 单链表类的定义

private:
    LinkNode *first; // 指向首结点的指针

public:
    List() { first = new LinkNode(); } // 带头结点

    ~List() {} // 析构函数

    void input(int endTag);

    void output();
};

void List ::input(int endTag)
{

    LinkNode *newnode;
    int val;

    cin >> val;

    while (val != endTag)

    {

        newnode = new LinkNode(val);

        if (newnode == NULL)

        {
            cerr << "存储分配错误" << endl;
            exit(1);
        }

        newnode->link = first->link;

        first->link = newnode;

        cin >> val;
    }
}
void List::output()
{
    LinkNode *p = first;
    if(p->link == NULL)
    {
        cout<<"1"<<endl;
        return;
    }
    int val[100];
    int i = 1;
    while (p->link != NULL)
    {
        p = p->link;
        if((i++)%2 != 0)
        {
            cout<<p->data<<endl;
        }
    }
}
int main()
{

    List l;

    l.input(0);

    l.output();

    return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */