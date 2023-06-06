# 数据结构

## 介绍

这是一个学习记录，非计算机专业，课本是《数据结构（用面向对象方法与C++语言描述）（第2版）》殷人昆 清华大学出版社

## 项目结构

|  文件夹  |  内容  | 备注 |
|:---:|:---:|:---:|
|.vscode|配置文件||
|bin|*.exe文件||
|include|头文件||
|src|源代码||
|test|测试代码||
|[src/Homework_temp](https://gitee.com/flight-leaf/data-struct/tree/master/src/Homework_temp)|线上大作业代码||

```c++
#include <iostream>
template <class T>
class LinkNode
{
public:
    LinkNode *link;
    T data;

public:
    LinkNode(LinkNode *ptr = NULL) { link = ptr; };
    LinkNode(const T &item, LinkNode *ptr = NULL)
    {
        data = item;
        link = ptr;
    };
    ~LinkNode(){};
};
```

## 具体内容

### 头文件

|  文件名  |  功能  | 具体内容 | 备注 |
|:---:|:---:|:---:|:---:|
|[Stack.h](https://gitee.com/flight-leaf/data-struct/blob/master/include/Stack.h)|栈(Stack)模板类|需要具体的派生类来定义实现||
|[LinkedList.h](https://gitee.com/flight-leaf/data-struct/blob/master/include/LinkedList.h)|单链表结点的类|用于链式栈调用生成结点，无具体功能||
|[Queue.h](https://gitee.com/flight-leaf/data-struct/blob/master/include/Queue.h)|队列模板类|需要具体的派生类来定义实现||
|[LinkedStack.h](https://gitee.com/flight-leaf/data-struct/blob/master/include/LinkedStack.h)|链式栈|入栈、出栈、取栈顶元素等||
|[SingleList.h](https://gitee.com/flight-leaf/data-struct/blob/master/include/SingleList.h)|单链表|添加、删除、查询定位等||

### 线性表(linearList)

|  文件名  |  功能  | 具体内容 | 备注 |
|:---:|:---:|:---:|:---:|
|[Poly.cpp](https://gitee.com/flight-leaf/data-struct/blob/master/src/LinearList/Poly.cpp)|利用单链表实现多项式的相关计算|添加、插入、求和、求差、乘积等||
|[SeqList.cpp](https://gitee.com/flight-leaf/data-struct/blob/master/src/LinearList/SeqList.cpp)|常规顺序表|添加、删除等||
|[SeqListTest.cpp](https://gitee.com/flight-leaf/data-struct/blob/master/src/LinearList/SeqListTest.cpp)|顺序表测试|-||
|[SingleList.cpp](https://gitee.com/flight-leaf/data-struct/blob/master/src/LinearList/SingleList.cpp)|常规单链表|添加、删除、查询定位等||
|[SingleListTest.cpp](https://gitee.com/flight-leaf/data-struct/blob/master/src/LinearList/SingleListTest.cpp)|单链表测试|-||

### 栈和队列(stacks qnd queues)

|  文件名  |  功能  | 具体内容 | 备注 |
|:---:|:---:|:---:|:---:|
|[CalculatorLinkedStack.cpp](https://gitee.com/flight-leaf/data-struct/blob/master/src/StacksAndQueues/CalculatorLinkedStack.cpp)|链式栈实现表达式运算|中缀表达式转后缀、计算、括号规则判断等||
|[CalculatorLinkedStackTest.cpp](https://gitee.com/flight-leaf/data-struct/blob/master/src/StacksAndQueues/CalculatorLinkedStackTest.cpp)|链式栈实现表达式运算测试|-||
|[LinkedStack.cpp](https://gitee.com/flight-leaf/data-struct/blob/master/src/StacksAndQueues/LinkedStack.cpp)|链式栈|入栈、出栈、取栈顶元素等||
|[LinkedStackTest.cpp](https://gitee.com/flight-leaf/data-struct/blob/master/src/StacksAndQueues/LinkedStack.cpp)|链式栈测试|-||
|[SeqStack.cpp](https://gitee.com/flight-leaf/data-struct/blob/master/src/StacksAndQueues/SeqStack.cpp)|顺序栈|入栈、出栈、取栈顶元素等||
|[SeqStackTest.cpp](https://gitee.com/flight-leaf/data-struct/blob/master/src/StacksAndQueues/SeqStackTest.cpp)|顺序栈测试|-||
|[SeqQueue.cpp](https://gitee.com/flight-leaf/data-struct/blob/master/src/StacksAndQueues/SeqQueue.cpp)|循环顺序队列|出队、入队、获取队首等||
|[SeqQueueTest.cpp](https://gitee.com/flight-leaf/data-struct/blob/master/src/StacksAndQueues/SeqQueueTest.cpp)|循环顺序队列测试|-||
|[LinkedQueue.cpp](https://gitee.com/flight-leaf/data-struct/blob/master/src/StacksAndQueues/LinkedQueue.cpp)|链式队列|出队、入队、获取队首等||
|[LinkedQueueTest.cpp](https://gitee.com/flight-leaf/data-struct/blob/master/src/StacksAndQueues/LinkedQueueTest.cpp)|链式队列测试|出队、入队、获取队首等||

### 数组和串(arrays and strings)

|  文件名  |  功能  | 具体内容 | 备注 |
|:---:|:---:|:---:|:---:|
|[Trituple.cpp](https://gitee.com/flight-leaf/data-struct/blob/master/src/ArraysAndStrings/Trituple.cpp)|稀疏矩阵|矩阵加法，矩阵乘法，以及存储|未完成|

### 树与二叉树(tree and binary tree)

|  文件名  |  功能  | 具体内容 | 备注 |
|:---:|:---:|:---:|:---:|
|[tree.cpp](https://gitee.com/flight-leaf/data-struct/blob/master/src/TreeAndBinaryTree/tree.cpp)|树的链式存储|创建树、遍历、求高度等||

### 搜索(search)

|  文件名  |  功能  | 具体内容 | 备注 |
|:---:|:---:|:---:|:---:|

### 图(picture)

|  文件名  |  功能  | 具体内容 | 备注 |
|:---:|:---:|:---:|:---:|

### 排序(sort)

|  文件名  |  功能  | 具体内容 | 备注 |
|:---:|:---:|:---:|:---:|

## 总结
