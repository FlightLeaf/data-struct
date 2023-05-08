#include <iostream>
#include <assert.h>
#include"LinkedList.h"
#include"Stack.h"

using namespace std;

template <class T>
class LinkedStack : public Stack<T>
{
public:
    LinkedStack(){top = NULL;};

    ~LinkedStack() { makeEmpty(); };

    /// @brief 入栈
    /// @param x 待加入的元素的值
    void Push(const T &x);

    /// @brief 出栈
    /// @param x 获取栈顶元素的引用
    /// @return true 成功出栈
    /// @return false 栈空
    bool Pop(T &x);

    /// @brief 获取栈顶元素，但不出栈
    /// @param x 获取栈顶元素的引用
    /// @return true 成功获取元素
    /// @return false 栈空
    bool getTop(T &x);

    /// @brief 判断栈是否为空
    /// @return ture 栈空
    bool IsEmpty() { return (top == NULL) ? true : false; };

    /// @brief 获取栈的元素个数
    /// @return 栈的元素个数
    int getSize();

    /// @brief 清空栈
    void makeEmpty();

    /// @brief 重载输出运算符<<，用于打印栈元素至输出流
    /// @param os 输出流对象的引用
    /// @param s 要输出的栈对象的引用
    /// @return ostream& 返回输出流对象的引用以便实现链式表达式
    friend std::ostream &operator<<(std::ostream &os, LinkedStack<T> &s)
    {
        os<<"栈中元素个数："<<s.getSize()<<endl;
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
        count++;
        temp = temp->link;   
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