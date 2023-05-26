/**回文序列**/
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
using namespace std;

struct StackNode
{
public:
    char data;
    StackNode *link;
    StackNode(char d = 0, StackNode *next = NULL) : data(d), link(next){};
    ~StackNode(){};
};
class LinkedStack
{
private:
    StackNode *top;

public:
    LinkedStack() : top(NULL){};
    /// @brief 入栈
    /// @param x 字符型待入栈
    void Push(char &x);
    /// @brief 出栈
    /// @param x 字符型
    /// @return 0 出栈失败
    /// @return 1 出栈成功
    int Pop(char &x);
    friend ostream &operator<<(ostream &os, LinkedStack &s);
};

ostream &operator<<(ostream &os, LinkedStack &s)
{
    StackNode *temp = s.top;
    int i = 0;
    while (temp != NULL)
    {
        os << ++i << ":" << temp->data << endl;
        temp = temp->link;
    }
    return os;
}

void LinkedStack::Push(char &x)
{
    top = new StackNode(x, top);
    assert(top != NULL);
}

int LinkedStack::Pop(char &x)
{
    if (top == NULL)
        return 0;
    StackNode *temp = top;
    top = top->link;
    x = temp->data;
    delete temp;
    return 1;
}
/**********************************/
int huiwen(char *s)
{
    LinkedStack stack;
    StackNode *temp;
    int length = 0;
    while (s[length] != '\0')
    {
        stack.Push(s[length]);
        length++;
    }
    length = 0;
    while(s[length] != '\0')
    {
        char temp;
        stack.Pop(temp);
        if(s[length] != temp)
        {
            return 0;
        }
        length++;
    }
    return 1;
}
/**********************************/
int main()
{
    char s[200];
    cin>>s;
    cout<<huiwen(s)<<endl;
    return 0;
}