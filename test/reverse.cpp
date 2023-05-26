/****转置****/
#include <iostream>
using namespace std;

class SingleList;

class LinkNode
{
    friend class SingleList;

private:
    LinkNode *next;
    int data;

public:
    LinkNode(LinkNode *ptr = NULL) { next = ptr; };
    LinkNode(const int &item, LinkNode *ptr = NULL)
    {
        data = item;
        next = ptr;
    };
    ~LinkNode(){};
};

class SingleList
{
private:
    LinkNode *first;

public:
    SingleList() { first = new LinkNode(); };
    ~SingleList() { makeEmpty(); };
    void makeEmpty();
    int length() const;
    LinkNode *getHead() const;
    LinkNode *find(int x) const;
    LinkNode *locate(int i) const;
    bool getData(int i, int &x) const;
    void setData(int i, const int &x);
    bool insert(int i, const int &x);
    bool remove(int i, int &x);
    bool isEmpty() const;
    void input(int endTag);
    void output() const;
    void reverse();
};


void SingleList::makeEmpty()
{
    LinkNode *p;
    while (first->next != NULL)
    {
        p = first->next;
        first->next = p->next;
        delete p;
    }
}

int SingleList::length() const
{
    // p指向第一个节点
    LinkNode *p = first->next;
    // 计数器
    int count = 0;
    // p不为空的时候先计数，然后指向下一节点
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

LinkNode *SingleList::getHead() const
{
    return first;
}

LinkNode *SingleList::find(int x) const
{
    LinkNode *p = first->next;
    while (p != NULL)
    {
        if (p->data == x)
        {
            break;
        }
        p = p->next;
    }
    return p;
}

LinkNode *SingleList::locate(int i) const
{
    LinkNode *p = first;
    if (i <= 0)
        return NULL;
    int j = 0;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

bool SingleList::getData(int i, int &x) const
{
    LinkNode *p = locate(i);
    if (p != NULL)
    {
        x = p->data;
        return true;
    }
    else
    {
        return false;
    }
}

void SingleList::setData(int i, const int &x)
{
    if (i <= 0)
        return;
    LinkNode *p = locate(i);
    if (p != NULL)
        p->data = x;
}

bool SingleList::insert(int i, const int &x)
{
    if (i <= 0)
        return false;
    LinkNode *p = locate(i);
    LinkNode *newNode = new LinkNode(x, p);
    LinkNode *before = locate(i - 1);
    before->next = newNode;
    return true;
}

bool SingleList::remove(int i, int &x)
{
    LinkNode *p = locate(i - 1), *q;
    if (p == NULL)
        return false;
    q = p->next;
    p->next = q->next;
    x = q->data;
    delete q;
    return true;
}

bool SingleList::isEmpty() const
{
    return (first->next == NULL ? true : false);
}

void SingleList::input(int endTag)
{
    int data;
    LinkNode *newnode;
    cin >> data;
    while (data != endTag)
    {
        newnode = new LinkNode(data);
        newnode->next = first->next;
        first->next = newnode;
        cin >> data;
    }
}

void SingleList::output() const
{
    LinkNode *p = first->next;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
/**************************************************/
void SingleList::reverse()
{
    LinkNode *first_temp = new LinkNode();
    LinkNode *p = first->next;
    while (p != NULL)
    {

        LinkNode *new_temp;
        new_temp = new LinkNode(p->data);
        if (first_temp->next == NULL)
        {
            first_temp->next = new_temp;
        }
        else
        {
            new_temp->next = first_temp->next;
            first_temp->next = new_temp;
        }
        p = p->next;
    }
    makeEmpty();
    first = first_temp;
}
/**************************************************/
int main()
{
    SingleList list;
    list.input(0);
    list.reverse();
    list.output();
    return 0;
}