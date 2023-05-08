#include <iostream>
using namespace std;

class SingleList;
class LinkNode
{
    friend SingleList;
    private:
        LinkNode *link;
        int data;
    public:
    LinkNode(LinkNode *ptr = NULL){link = ptr;};
    LinkNode(const int &item,LinkNode *ptr = NULL)
    {
        data = item;
        link = ptr;
    };
    ~LinkNode(){};
};

class SingleList
{
private:
    LinkNode *first;
public:
    SingleList(){first = new LinkNode();};
    ~SingleList(){MakeEmpty();};
    void MakeEmpty();
    int Length();
    LinkNode *getHead();
    LinkNode *Find(int x);
    LinkNode *Locate(int i);
    int GetData(int i,int &x);
    void SetData(int x,int i);
    int Insert(int x,int i);
    int Remove(int &x,int i);
    int IsEmpty();
    void input(int endTag);
    void output();
};
void SingleList::MakeEmpty()
{
    LinkNode *p;
    while (first->link != NULL)
    {
        p = first->link;
        first->link = p->link;
        delete p; 
    }  
}

int SingleList::Length()
{
    //p指向第一个节点
    LinkNode *p = first->link;
    //计数器
    int count = 0;
    //p不为空的时候先计数，然后指向下一节点
    while (p!=NULL)
    {
        count++;
        p = p->link;
    }
    return count;
}

LinkNode *SingleList::getHead()
{
    return first;
}

LinkNode *SingleList::Find(int x)
{
    LinkNode *p = first->link;
    while (p != NULL)
    {
        if(p->data == x)
        {
            break;
        }
        p = p->link;
    }
    return p;
}

LinkNode *SingleList::Locate(int i)
{
    LinkNode *p = first;
    if(i<=0)return NULL;
    int j = 0;
    while (p != NULL&&j<i)
    {
        p = p->link;
        j++;
    }
    return p;
}

int SingleList::GetData(int i,int &x)
{
    LinkNode *p = Locate(i);
    if(p!=NULL)
    {
        x = p->data;
        return 1;
    }
    else
    {
        return 0;
    }
}

void SingleList::SetData(int x,int i)
{
    if(i<=0)return;
    LinkNode *p = Locate(i);
    if(p!=NULL)p->data = x;
}
//疑惑
int SingleList::Insert(int x,int i)
{
    if(i<=0)return 0;
    LinkNode *p = Locate(i);
    LinkNode *newList = new LinkNode(x,p->link);
    LinkNode *before = Locate(i-1);
    before->link = newList;
    return 1;
}

int SingleList::Remove(int &x,int i)
{
    LinkNode *p = Locate(i-1),*q;
    if(p==NULL)return 0;
    q = p->link;
    p->link = q->link;
    x = q->data;
    delete q;
    return 1;
}

int SingleList::IsEmpty()
{
    return(first->link==NULL?1:0);
}

void SingleList::input(int endTag)
{
    int data;
    LinkNode *newnode;
    cin>>data;
    while(data != endTag)
    {
        newnode = new LinkNode(data); 
        newnode->link = first->link;
        first->link = newnode;
        cin>>data;
    }
}

void SingleList::output()
{
    LinkNode *p = first->link;
    while(p!=NULL)
    {
        cout<<p->data<<endl;
        p = p->link;
    }
}

