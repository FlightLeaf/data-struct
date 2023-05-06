# 数据结构

```C++
class LinkNode
{
    friend List;
    private:
        LinkNode *link;
        int data;
    public:
    LinkNode(LinkNode *ptr = NULL){link = ptr;};
    LinkNode(const int &item,LinkNode *ptr = NULL)
    {
        data = item;
        link = ptr;
    };
    ~LinkNode(){};
};
```

**线性表**

|  文 件 名  |  功 能  | 具 体 功 能 |
|:---:|:---:|:---:|
|SeqList.cpp|常规顺序表|添加、删除等|
|SeqListTest.cpp|顺序表测试|-|
|SingleList.cpp|常规单链表，储存int类型|添加、删除、查询定位等|
|SingleListTest.cpp|单链表测试|-|
|Poly.cpp|利用单链表实现多项式的相关计算|添加、插入、求和、求差、乘积等|
*注：\*.exe文件为运行文件*

**栈和队列**

|  文 件 名  |  功 能  | 具 体 功 能 |
|:---:|:---:|:---:|
|Stack.h|栈(Stack)模板类|需要具体的派生类来定义实现|
|SeqStack.cpp|顺序栈|入栈、出栈、取栈顶元素等|
|LinkedList.h|单链表结点的类|用于链式栈调用生成结点，无具体功能|
|LinkedStack.cpp|链式栈|入栈、出栈、取栈顶元素等|
|LinkedStackTest.cpp|链式栈测试|-|
*注：\*.exe文件为运行文件*
