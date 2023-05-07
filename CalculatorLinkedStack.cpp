#include<iostream>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include"LinkedStack.cpp"
using namespace std;
class CalculatorLinkedStack
{
private:
    /// @brief 待计算的表达式
    char *input;
    /// @brief 操作符栈
    LinkedStack<char> *op;
    /// @brief 操作数栈
    LinkedStack<char> *value;
    /// @brief 栈内优先级判断
    /// @param op 待判断的操作符
    /// @return 栈内优先数
    int isp(char op);
    /// @brief 栈外优先级判断
    /// @param op 待判断的操作符
    /// @return 栈外优先数
    int icp(char op);
    /// @brief 表达式的括号是否符合要求
    /// @return true 表达式符合要求
    bool judge();
    /// @brief 字符是否为运算符
    /// @param temp 待判断的字符
    /// @return true 是操作符
    bool IsOperator(char temp);
    /// @brief 字符是否为操作数
    /// @param temp 待判断的字符
    /// @return true 是操作数
    bool IsDigit(char temp);
    /// @brief 后缀表达式中出现字符时生成运算
    /// @param op 操作符
    void DoOperator(char op);
    /// @brief 获取操作数栈的前两个值并出栈
    /// @param left 第一个值
    /// @param right 第二个值
    /// @return true 完成取数
    bool get2Operands(double &left,double &right);
    /// @brief 操作数入栈
    /// @param value 待入栈的操作数
    void AddOperand(double value);
public:
    /// @brief 构造函数
    CalculatorLinkedStack(){};
    /// @brief 计算机主程序
    /// @return 返回输入表达式的结果
    double Run();
    /// @brief 清空栈
    void clear(){op->makeEmpty();value->makeEmpty();};
};