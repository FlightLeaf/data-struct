//多项式
#include <iostream>
using namespace std;

class polynomial;
class LinkNode
{
    friend polynomial;
    private:
        LinkNode *link;
        int data[2];
    public:
    LinkNode(LinkNode *ptr = NULL){link = ptr;};
    LinkNode(const int &coefficient,const int &pow,LinkNode *ptr = NULL)
    {
        data[0] = coefficient;
        data[1] = pow;
        link = ptr;
    };
    ~LinkNode(){};
};

class polynomial
{
private:
    LinkNode *first;
public:
    polynomial(){first = new LinkNode();};
    ~polynomial(){MakeEmpty();};
    void MakeEmpty();
    int Length();
    LinkNode *getHead();
    //LinkNode *Find(int x);
    LinkNode *Locate(int i);
    int GetData(int i,int &x,int &y);
    void SetData(int coefficient,int pow,int i);
    int Insert(int coefficient,int pow,int i);
    int Remove(int &x,int &y,int i);
    int IsEmpty();
    void input(int endTag);
    void output();
};
void polynomial::MakeEmpty()
{
    LinkNode *p;
    while (first->link != NULL)
    {
        p = first->link;
        first->link = p->link;
        delete p; 
    }  
}

int polynomial::Length()
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

LinkNode *polynomial::getHead()
{
    return first;
}
/*
LinkNode *polynomial::Find(int x)
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
*/


LinkNode *polynomial::Locate(int i)
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

int polynomial::GetData(int i,int &x,int &y)
{
    LinkNode *p = Locate(i);
    if(p!=NULL)
    {
        x = p->data[0];
        y = p->data[1];
        return 1;
    }
    else
    {
        return 0;
    }
}



void polynomial::SetData(int coefficient,int pow,int i)
{
    if(i<=0)return;
    LinkNode *p = Locate(i);
    if(p!=NULL)
    {
        p->data[0] = coefficient;
        p->data[1] = pow;
    }
    
}
//疑惑
int polynomial::Insert(int coefficient,int pow,int i)
{
    if(i<=0)return 0;
    LinkNode *p = Locate(i);
    LinkNode *newpolynomial = new LinkNode(coefficient,pow,p->link);
    LinkNode *before = Locate(i-1);
    before->link = newpolynomial;
    return 1;
}

int polynomial::Remove(int &x,int &y,int i)
{
    LinkNode *p = Locate(i-1),*q;
    if(p==NULL)return 0;
    q = p->link;
    p->link = q->link;
    x = q->data[0];
    y = q->data[1];
    delete q;
    return 1;
}

int polynomial::IsEmpty()
{
    return(first->link==NULL?1:0);
}

void polynomial::input(int endTag)
{
    int coefficient;
    int pow;
    LinkNode *newnode;
    cin>>coefficient>>pow;
    while(coefficient != endTag)
    {
        newnode = new LinkNode(coefficient,pow); 
        newnode->link = first->link;
        first->link = newnode;
        cin>>coefficient>>pow;;
    }
}

void polynomial::output()
{
    LinkNode *p = first->link;
    while(p!=NULL)
    {
        cout<<p->data[0]<<p->data[1]<<endl;
        p = p->link;
    }
}

