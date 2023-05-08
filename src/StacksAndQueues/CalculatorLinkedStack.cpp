/*
    链式栈实现表达式计算
*/
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "LinkedStack.cpp"
using namespace std;
class CalculatorLinkedStack
{
public:
    /// @brief 计算式
    string input;

    /// @brief 操作符栈
    LinkedStack<char> op;

    /// @brief 操作数栈
    LinkedStack<double> value;

    /// @brief 构造函数
    CalculatorLinkedStack(){};

    /// @brief 计算机主程序
    /// @return 返回输入表达式的结果
    double Run();

    /// @brief 传递已有的表达式计算
    /// @param in 待计算的表达式
    /// @return 计算结果
    double Calulator(char *in);

    /// @brief 清空栈
    void clear()
    {
        op.makeEmpty();
        value.makeEmpty();
    };

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
    bool judge(char *expression);

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
    bool get2Operands(double &left, double &right);

    /// @brief 操作数入栈
    /// @param val 待入栈的操作数
    void AddOperand(char val);

    /// @brief 中缀转后缀
    void postfix();
};

int CalculatorLinkedStack::isp(char op)
{
    switch (op)
    {
    case '#':
        return 0;
        break;
    case '(':
        return 1;
        break;
    case '*':
    case '/':
    case '%':
        return 5;
        break;
    case '+':
    case '-':
        return 3;
        break;
    case ')':
        return 6;
        break;
    }
    return -1;
}

int CalculatorLinkedStack::icp(char op)
{
    switch (op)
    {
    case '#':
        return 0;
        break;
    case '(':
        return 6;
        break;
    case '*':
    case '/':
    case '%':
        return 4;
        break;
    case '+':
    case '-':
        return 2;
        break;
    case ')':
        return 1;
        break;
    }
    return -1;
}

bool CalculatorLinkedStack::judge(char *expression)
{
    LinkedStack<char> l;
    int length = strlen(expression);
    char j;
    for (int i = 0; i < length; i++)
    {
        if (expression[i] == '(')
            l.Push('(');
        else if (expression[i] == ')')
        {
            if (!l.Pop(j))
                return false;
        }
    }
    while (l.IsEmpty() == false)
    {
        l.Pop(j);
        return false;
    }
    return true;
}

bool CalculatorLinkedStack::IsOperator(char temp)
{
    switch (temp)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
        return true;
        break;
    }
    return false;
}

bool CalculatorLinkedStack::IsDigit(char temp)
{
    switch (temp)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case '(':
    case ')':
        return false;
        break;
    }
    return true;
}

bool CalculatorLinkedStack::get2Operands(double &left, double &right)
{
    if (value.IsEmpty())
    {
        cerr << "无右操作数" << endl;
        return false;
    }
    value.Pop(right);
    if (value.IsEmpty())
    {
        cerr << "无左操作数" << endl;
        return false;
    }
    value.Pop(left);
    return true;
}

void CalculatorLinkedStack::DoOperator(char op)
{
    double left;
    double right;
    if (get2Operands(left, right))
    {
        switch (op)
        {
        case '+':
            value.Push(left + right);
            break;
        case '-':
            value.Push(left - right);
            break;
        case '*':
            value.Push(left * right);
            break;
        case '/':
            if (right == 0.0)
            {
                cerr << "除数为零！" << endl;
            }
            value.Push(left / right);
            break;
        case '%':
            value.Push(fmod(left, right));
            break;
        }
    }
}

void CalculatorLinkedStack::AddOperand(char val)
{
    int va = val-'0';//转为整型
    value.Push(va);
}

void CalculatorLinkedStack::postfix()
{
    
}

double CalculatorLinkedStack::Run()
{
    getline(cin,input);
    input = "("+input+")";
    cout<<input<<endl;
    char ch1,op_temp;
    op.Push('#');
    int len = input.size();
    for(int i = 0; i<len ;i++)
    {
        if(IsDigit(input[i]))
        {
            AddOperand(input[i]);
        }
        else
        {
            op.getTop(ch1);
            if(isp(ch1)<icp(input[i]))
            {
                op.Push(input[i]);
                continue;
            }
            else if(isp(ch1)>icp(input[i]))
            {
                op.Pop(op_temp);
                DoOperator(op_temp);
            }
            else
            {
                op.Pop(op_temp);
                if(op_temp == '(') continue;
            }
        }
    }
    double rel;
    value.getTop(rel);
    return rel;
}
