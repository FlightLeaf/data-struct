#include <assert.h>
#include <iostream>
#include "Stack.h"
#include <ostream>
const int stackIncrement = 20;
template <class T>
class SeqStack : public Stack<T>
{
public:
    SeqStack(int sz = 50);              // 建立一个空栈
    ~SeqStack() { delete[] elements; }; // 析构函数

    /// @brief 入栈
    /// @param x 待入栈元素值
    void Push(T &x);

    /// @brief 退栈
    /// @param x 获取退栈元素的引用
    /// @return true 非空并且退栈成功
    /// @return false 空栈
    bool Pop(T &x);

    /// @brief 获取栈顶元素但不删除
    /// @param x 获取栈顶元素的引用
    /// @return true 成功获取到了栈顶元素
    /// @return false 如果栈为空
    bool getTop(T &x);

    /// @brief 判断栈是否为空
    /// @return true 为空
    /// @return false 非空
    bool IsEmpty() const { return (top == -1) ? true : false; };

    /// @brief 判断栈是否已满
    /// @return true 栈已满
    /// @return false 栈未满
    bool IsFull() const { return (top == maxSize - 1) ? true : false; };

    /// @brief 获取栈元素个数
    /// @return 栈元素个数
    int getSize() const { return top + 1; };

    /// @brief 清空栈
    void MakeEmpty() { top = -1; };

    /// @brief 重载输出运算符<<，用于打印栈元素至输出流
    /// @param os 输出流对象的引用
    /// @param s 要输出的栈对象的引用
    /// @return ostream& 返回输出流对象的引用以便实现链式表达式
    friend std::ostream &operator<<(std::ostream &os, SeqStack<T> &s);

private:
    T *elements;            // 存放栈元素的数组
    int top;                // 栈顶指针
    int maxSize;            // 栈可容纳最大元素个数
    void overflowProcess(); // 栈溢出处理
};

template <class T>
SeqStack<T>::SeqStack(int sz) : top(-1), maxSize(sz)
{
    elements = new T[maxSize];
    assert(elements != NULL);
}

template <class T>
void SeqStack<T>::overflowProcess()
{
    T *newArray = new T[maxSize + stackIncrement];
    if (newArray == NULL)
    {
        cerr << "内存分配失败！" << endl;
        exit(1);
    }
    for (int i = 0; i <= top; i++)
    {
        newArray[i] = elements[i];
    }
    delete[] elements;
    elements = newArray;
}

template <class T>
void SeqStack<T>::Push(T &x)
{
    if (IsFull())
        overflowProcess();
    elements[++top] = x;
}

template <class T>
bool SeqStack<T>::Pop(T &x)
{
    if (IsEmpty())
        return false;
    x = elements[top--];
    return true;
}

template <class T>
bool SeqStack<T>::getTop(T &x)
{
    if (IsEmpty())
        return false;
    x = elements[top];
    return ture;
}

template <class T>
std::ostream &operator<<(std::ostream &os, SeqStack<T> &s)
{
    os << "top = " << s.top << endl;
    for (int i = 0; i <= top; i++)
    {
        os << i << ":" << s.elements[i] << endl;
    }
    return os;
}

