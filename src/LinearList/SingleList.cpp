#include <iostream>
using namespace std;

template<class T> class SingleList;

template<class T>
class LinkNode{
    friend class SingleList<T>;
private:
    LinkNode<T> *next;
    T data;
public:
    LinkNode(LinkNode<T> *ptr = NULL){next = ptr;};
    LinkNode(const T &item,LinkNode<T> *ptr = NULL)
    {
        data = item;
        next = ptr;
    };
    ~LinkNode(){};
};

template<class T>
class SingleList
{
private:
    LinkNode<T> *first;
public:
    SingleList(){first = new LinkNode<T>();};
    ~SingleList(){makeEmpty();};
    void makeEmpty();
    int length() const;
    LinkNode<T> *getHead() const;
    LinkNode<T> *find(T x) const;
    LinkNode<T> *locate(int i) const;
    bool getData(int i,T &x) const;
    void setData(int i,const T &x);
    bool insert(int i,const T &x);
    bool remove(int i,T &x);
    bool isEmpty() const;
    void input(T endTag);
    void output() const;
};

template<class T>
void SingleList<T>::makeEmpty()
{
    LinkNode<T> *p;
    while (first->next != NULL)
    {
        p = first->next;
        first->next = p->next;
        delete p; 
    }  
}

template<class T>
int SingleList<T>::length() const
{
    //p指向第一个节点
    LinkNode<T> *p = first->next;
    //计数器
    int count = 0;
    //p不为空的时候先计数，然后指向下一节点
    while (p!=NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

template<class T>
LinkNode<T> *SingleList<T>::getHead() const
{
    return first;
}

template<class T>
LinkNode<T> *SingleList<T>::find(T x) const
{
    LinkNode<T> *p = first->next;
    while (p != NULL)
    {
        if(p->data == x)
        {
            break;
        }
        p = p->next;
    }
    return p;
}

template<class T>
LinkNode<T> *SingleList<T>::locate(int i) const
{
    LinkNode<T> *p = first;
    if(i<=0)return NULL;
    int j = 0;
    while (p != NULL&&j<i)
    {
        p = p->next;
        j++;
    }
    return p;
}

template<class T>
bool SingleList<T>::getData(int i,T &x) const
{
    LinkNode<T> *p = locate(i);
    if(p!=NULL)
    {
        x = p->data;
        return true;
    }
    else
    {
        return false;
    }
}

template<class T>
void SingleList<T>::setData(int i,const T &x)
{
    if(i<=0)return;
    LinkNode<T> *p = locate(i);
    if(p!=NULL)p->data = x;
}

template<class T>
bool SingleList<T>::insert(int i,const T &x)
{
    if(i<=0)return false;
    LinkNode<T> *p = locate(i);
    LinkNode<T> *newNode = new LinkNode<T>(x,p);
    LinkNode<T> *before = locate(i-1);
    before->next = newNode;
    return true;
}

template<class T>
bool SingleList<T>::remove(int i,T &x)
{
    LinkNode<T> *p = locate(i-1),*q;
    if(p==NULL)return false;
    q = p->next;
    p->next = q->next;
    x = q->data;
    delete q;
    return true;
}

template<class T>
bool SingleList<T>::isEmpty() const
{
    return(first->next==NULL?true:false);
}

template<class T>
void SingleList<T>::input(T endTag)
{
    T data;
    LinkNode<T> *newnode;
    cin>>data;
    while(data != endTag)
    {
        newnode = new LinkNode<T>(data); 
        newnode->next = first->next;
        first->next = newnode;
        cin>>data;
    }
}

template<class T>
void SingleList<T>::output() const
{
    LinkNode<T> *p = first->next;
    while(p!=NULL)
    {
        cout<<p->data<<endl;
        p = p->next;
    }
}
