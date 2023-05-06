const int MaxSize = 100;
template <class T>
class Stack
{
public:
    // 构造函数,用于创建 Stack 对象
    Stack();
    // 用于向栈中添加新元素,其中 x 表示待加入的元素的值
    virtual void Push(const T &x) = 0;
    // 用于从栈顶删除一个元素,并将其值赋给参数x,如果栈已空,则返回false
    virtual bool Pop(T &x) = 0;
    // 获取栈顶元素,在该函数执行后,栈的状态不变
    virtual bool getTop(T &x) const = 0;
    // 判断栈是否为空，如果为空则返回true,否则返回false
    virtual bool IsEmpty() const = 0;
    // 判断栈是否已满，如果已满则返回true,否则返回false
    virtual bool IsFull() const = 0;
    // 获取栈的元素个数
    virtual bool getSize() const = 0;
};
