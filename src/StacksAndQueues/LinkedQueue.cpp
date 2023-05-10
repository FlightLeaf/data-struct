#include <iostream>
#include <Queue.h>
#include <assert.h>
#include <LinkedList.h>

using namespace std;

template <class T>
class LinkedQueue : public Queue<T>
{
private:
    LinkNode<T> *front, *rear;

public:
    /// @brief 构造函数
    /// @param sz 最大容量默认12
    LinkedQueue() : front(NULL), rear(NULL){};

    /// @brief 析构函数
    ~LinkedQueue() { makeEmpty(); };

    /// @brief 新元素进队列
    /// @param value 待加入的新元素
    bool EnQueue(const T &value);

    /// @brief 队尾元素出队列
    /// @param value 获取到队尾元素值的引用
    bool DeQueue(T &value);

    /// @brief 获取队头元素的值
    /// @param value 获取队头元素的值引用
    bool getFront(T &value);

    /// @brief 清空队列
    void makeEmpty();

    /// @brief 判断是否为空
    /// @return true 队列空
    bool isEmpty() { return (front == rear) ? true : false; };

    /// @brief 获取队列元素个数
    /// @return 元素个数
    int getSize();

    /// @brief 重写"cout<<"
    /// @param os
    /// @param queue
    /// @return 打印结果
    friend std::ostream &operator<<(std::ostream &os, LinkedQueue<T> &queue)
    {
        os << "队列中的元素的个数：" << queue.getSize() << endl;
        LinkNode<T> *p = queue.front;
        int i = 0;
        while (p != NULL)
        {
            os << ++i << ":" << p->data << endl;
            p = p->link;
        }
        return os;
    }
};

template <class T>
bool LinkedQueue<T>::EnQueue(const T &value)
{
    if (front == NULL)
    {
        front = rear = new LinkNode<T>(value);
        if (front == NULL)
            return false;
    }
    else
    {
        rear->link = new LinkNode<T>(value);
        if (rear->link == NULL)
            return false;
        rear = rear->link;
    }
    return true;
}

template <class T>
bool LinkedQueue<T>::DeQueue(T &value)
{
    if (isEmpty())
        return false;
    LinkNode<T> *temp = front;
    value = front->data;
    front = front->link;
    delete temp;
    return true;
}

template <class T>
bool LinkedQueue<T>::getFront(T &value)
{
    if (isEmpty())
        return false;
    value = front->data;
    return true;
}

template <class T>
void LinkedQueue<T>::makeEmpty()
{
    LinkNode<T> *temp;
    while (front != NULL)
    {
        temp = front;
        front = front->link;
        delete temp;
    }
}

template <class T>
int LinkedQueue<T>::getSize()
{
    int size = 0;
    if (isEmpty())
        return size;
    LinkNode<T> *temp = front;
    while (temp != rear) 
    {
        size++;
        temp = temp->link;
    }
    return size+1;
}
