
//////////实验3：括号匹配（6月9日截止）///////////

#include <iostream>
#include <assert.h>

using namespace std;
template <class T>
class LinkNode
{
public:
    LinkNode *link;
    T data;

public:
    LinkNode(LinkNode *ptr = NULL) { link = ptr; };
    LinkNode(const T &item, LinkNode *ptr = NULL)
    {
        data = item;
        link = ptr;
    };
    ~LinkNode(){};
};

template <class T>
class LinkedStack
{
public:
    LinkedStack(){top = NULL;};
    ~LinkedStack() { makeEmpty(); };
    void Push(const T &x);
    bool Pop(T &x);
    bool getTop(T &x);
    bool IsEmpty() { return (top == NULL) ? true : false; };
    int getSize();
    void makeEmpty();
    friend std::ostream &operator<<(std::ostream &os, LinkedStack<T> &s)
    {
        os<<"Number:"<<s.getSize()<<endl;
        LinkNode<T> *temp = s.top;
        int i = 0;
        while(temp!=NULL)
        {
            os<<++i<<":"<<temp->data<<endl;
            temp = temp->link;
        }
        return os;
    };
private:
    LinkNode<T> *top;
};

template <class T>
void LinkedStack<T>::makeEmpty()
{
    LinkNode<T> *temp;
    while (top != NULL)
    {
        temp = top;
        top = top->link;
        delete temp;
    }
}

template <class T>
void LinkedStack<T>::Push(const T &x)
{
    top = new LinkNode<T>(x,top);
    assert(top!=NULL);
}

template <class T>
bool LinkedStack<T>::Pop(T &x)
{
    if(IsEmpty())return false;
    LinkNode<T> *temp = top;
    top = top->link;
    x = temp->data;
    delete temp;
    return true;
}

template <class T>
int LinkedStack<T>::getSize()
{
    if(IsEmpty())return 0;
    LinkNode<T> *temp = top;
    int count = 1;
    while (temp->link!=NULL)
    {
        temp = temp->link;
        count++;
    }
    return count;
}

template <class T>
bool LinkedStack<T>::getTop(T &x)
{
    if(IsEmpty())return false;
    x = top->data;
    return true;
}

char exchange(const char buf)
{
    char buf_;
    switch (buf)
    {
    case '(':
        return ')';
    case '[':
        return ']';
    case '{':
        return '}';
    case '<':
        return '>';
    }
};

int main()
{
    char buf;
    cin >> buf;
    LinkedStack<char> stack;
    int local = 1;
    do
    {
        if (buf == '(' || buf == '{' || buf == '<' || buf == '[')
        {
            stack.Push(buf);
        }
        else if (buf == '}' || buf == ')' || buf == ']' || buf == '>')
        {
            char temp;
            stack.getTop(temp);
            if (buf == exchange(temp))
            {
                stack.Pop(temp);
            }
            if (buf != exchange(temp))
            {
                // The 6 character '>' is wrong.
                cout << "The " << local << " character '" << buf << "' is wrong." << endl;
                return 0;
            }
        }
        cin >> buf;
        local++;
    } while (buf != '#');
    if (!stack.IsEmpty())
    {
        cout << "loss of right character ";
        int i = stack.getSize();
        char temp;
        while (i != 0)
        {
            stack.Pop(temp);
            cout << exchange(temp);
            i--;
        }
        cout << "." << endl;
        return 0;
    }
    cout << "right" << endl;
    return 0;
}