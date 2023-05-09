const int max_size = 50;
template <class T>
class Queue
{
public:
    /// @brief 构造函数
    Queue(){};

    /// @brief 析构函数
    ~Queue(){};

    /// @brief 新元素进队列
    /// @param value 待加入的新元素
    virtual void EnQueue(const T &value);

    /// @brief 队尾元素出队列
    /// @param value 获取到队尾元素值的引用
    virtual void DeQueue(T &value);

    /// @brief 获取队头元素的值
    /// @param value 获取队头元素的值引用
    virtual void getFront(T &value);

    /// @brief 判断是否为空
    /// @return true 队列空
    virtual bool isEmpty();

    /// @brief 判断队列是否已满
    /// @return true 队列满
    virtual bool isFull();

    /// @brief 获取队列元素个数
    /// @return 元素个数
    virtual int getSize();
};