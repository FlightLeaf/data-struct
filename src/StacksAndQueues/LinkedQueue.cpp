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
    LinkedQueue() : front(NULL), rear(NULL) {};

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
    int getSize() { return (rear - front + maxSize) % maxSize; };

    friend std::ostream &operator<<(std::ostream &os, SeqQueue<T> &queue)
    {
        
    }
};