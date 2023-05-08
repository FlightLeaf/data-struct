const int MaxSize = 100;
template <class T>
class Stack
{
public:
    /// @brief 构造函数,用于创建 Stack 对象
    Stack(){};

    /// @brief 入栈
    /// @param x 待加入的元素的值
    virtual void Push(const T &x) = 0;

    /// @brief 出栈
    /// @param x 获取栈顶元素的引用
    /// @return true 成功出栈
    /// @return false 栈空
    virtual bool Pop(T &x) = 0;

    /// @brief 获取栈顶元素，但不出栈
    /// @param x 获取栈顶元素的引用
    /// @return true 成功获取元素
    /// @return false 栈空
    virtual bool getTop(T &x) = 0;

    /// @brief 判断栈是否为空
    /// @return ture 栈空
    virtual bool IsEmpty() = 0;

    /// @brief 判断栈是否已满
    /// @return true 栈满
    bool IsFull();

    /// @brief 获取栈的元素个数
    /// @return 栈的元素个数
    virtual int getSize() = 0;
};
