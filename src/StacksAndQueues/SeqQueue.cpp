#include <iostream>
#include <Queue.h>
#include <assert.h>

using namespace std;

template <class T>
class SeqQueue : public Queue<T>
{
public:
    /// @brief 构造函数
    /// @param sz 最大容量默认12
    SeqQueue(int size = 12) : front(0), rear(0), maxSize(size)
    {
        elements = new T[maxSize];
        assert(elements != NULL);
    }

    /// @brief 析构函数
    ~SeqQueue() { delete[] elements; }

    /// @brief 新元素进队列
    /// @param value 待加入的新元素
    bool EnQueue(const T &value);

    /// @brief 队尾元素出队列
    /// @param value 获取到队尾元素值的引用
    bool DeQueue(T &value);

    /// @brief 获取队头元素的值
    /// @param value 获取队头元素的值引用
    bool getFront(T &value);

    /// @brief 判断是否为空
    /// @return true 队列空
    bool isEmpty() { return (front == rear) ? true : false; };

    /// @brief 判断队列是否已满
    /// @return true 队列满
    bool isFull() { return ((rear + 1) % maxSize == front) ? true : false; };

    /// @brief 获取队列元素个数
    /// @return 元素个数
    int getSize() { return (rear - front + maxSize) % maxSize; };

    friend std::ostream &operator<<(std::ostream &os, const SeqQueue<T> &queue)
    {
        os << "front = " << queue.front << ",rear = " << queue.rear << endl;
        for (int i = queue.front; i != queue.rear; i = (i + 1) % queue.maxSize)
        {
            os << i << " : " << queue.elements[i] << endl;
        }
        return os;
    }
    private:
    T *elements;
    int front, rear;
    int maxSize;
};

template <class T>
bool SeqQueue<T>::EnQueue(const T &value)
{
    if(isFull()) return false;
    elements[rear] = value;
    rear = (rear + 1) % maxSize;
    return true;
}

template <class T>
bool SeqQueue<T>::DeQueue(T &value)
{
    if(isEmpty()) return false;
    value = elements[front];
    front = (front + 1) % maxSize;
    return true;
}

template <class T>
bool SeqQueue<T>::getFront(T &value)
{
    if(isEmpty()) return false;
    value = elements[value];
    return true;
}