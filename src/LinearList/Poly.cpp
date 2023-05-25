#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
class Poly;
class PolyNode
{
    friend Poly;

private:
    double coef;
    int exp;
    PolyNode *next;

public:
    PolyNode(PolyNode *temp = NULL) { next = temp; };
    PolyNode(double coef, int exp, PolyNode *temp = NULL)
    {
        this->coef = coef;
        this->exp = exp;
        next = temp;
    }
    ~PolyNode(){};
};
class Poly
{
private:
    PolyNode *first;

public:
    Poly() { first = new PolyNode(); };
    ~Poly(){};
    /*清空多项式*/
    void MakeEmpty();
    /*返回多项式长度*/
    int length();
    /*找到exp的位置并返回PolyNode指针*/
    PolyNode *Find(int exp);
    /*新项的插入*/
    int insert(double coef, int exp);
    /*移除特定的某一项，系数可以为空*/
    int remove(int exp, double coef = 0);
    /*判断多项式是否为空*/
    int sEmpty();
    /*输入多项式*/
    void input(int endTag);
    /*输出多项式*/
    void output();
    /*给多项式输入数值后计算结果*/
    float result(float x);
    /*多项式求导*/
    void derivatives();
    /*多项式获取头结点*/
    PolyNode *getFirst() { return first; };
    /*原多项式加多项式*/
    int add(Poly ploy);
    /*原多项式减多项式*/
    int reduce(Poly poly);
    /*多项式相乘*/
    Poly multiply(Poly ploy);
    /*复制函数*/
    Poly copy();
};

Poly Poly::copy()
{
    Poly res = Poly();
    PolyNode *p = first->next; // 遍历原多项式
    while (p)
    {
        res.insert(p->coef, p->exp); // 将每一项依次插入新多项式中
        p = p->next;
    }
    return res;
}

void Poly::MakeEmpty()
{
    PolyNode *temp;
    while (first->next != NULL)
    {
        temp = first->next;
        first->next = temp->next;
        delete temp;
    }
}

int Poly::length()
{
    int result = 0;
    PolyNode *temp = first->next;
    while (temp != NULL)
    {
        result++;
        temp = temp->next;
    }
    return result;
}

PolyNode *Poly::Find(int exp)
{
    if (exp < 0)
        return 0;
    PolyNode *temp = first;
    while (temp->next != 0)
    {
        if (temp->next->exp == exp)
        {
            return temp->next;
        }
        else
        {
            temp = temp->next;
        }
    }
    return 0;
}

int Poly::insert(double coef, int exp)
{
    if (coef != 0)
    {
        PolyNode *current = first;
        while (current->next != NULL && current->next->exp <= exp)
        { // 判断当输入的exp小于等于原多项式中的某一项时就可以插入这一位置
            current = current->next;
        }
        if (current->exp == exp)
        { // 如果exp相同则合并系数即可
            current->coef += coef;
        }
        else
        {
            PolyNode *new_node = new PolyNode(coef, exp); // 如果不相同则新建插入
            new_node->next = current->next;
            current->next = new_node;
        }
        return 1;
    }
    return 0;
}

int Poly::remove(int exp, double coef)
{
    int result = 0;
    PolyNode *temp = Find(exp);
    if (temp != NULL)
    {
        if (temp->coef == coef)
        {
            if (temp == first->next) // 如果是第一项，则特殊处理
            {
                first->next = temp->next;
            }
            else
            {
                PolyNode *prev = first->next;
                while (prev->next != temp)
                    prev = prev->next;
                prev->next = temp->next;
            }
            delete temp;
            result = 1;
        }
        else if (temp->coef != coef) // 系数不同则执行相减
        {
            temp->coef = temp->coef - coef;
            result = 1;
        }
    }
    else
    {
        insert(-coef, exp);
        result = 1;
    }
    return result;
}

int Poly::sEmpty()
{
    return (first->next == NULL ? 1 : 0);
}

void Poly::input(int endTag)
{
    double coef = 10000;
    int exp ;
    do
    {
        cin >> coef;
        if (coef == endTag)
        {
            break;
        }
        cin >> exp;
        insert(coef, exp);
    } while (coef != endTag);
}

void Poly::output()
{
    PolyNode *temp = first->next;
    int i = 0;

    while (temp != NULL)
    {
        i++;
        if (i == 1)
        {
            cout << "C(x)=";
        }
        if (temp->exp == 0)
        {
            cout << temp->coef;
        }
        else if (temp->exp == 1 && i != 1)
        {
            cout << "+" << temp->coef << "x";
        }
        else if (temp->exp == 1 && i == 1)
        {
            cout << temp->coef << "x";
        }
        else if (temp->coef == 1)
        {
            cout << "x^" << temp->exp;
        }
        else if (temp->coef > 0 && i != 1)
        {
            cout << "+" << temp->coef << "x^" << temp->exp;
        }
        else if (temp->coef == 0)
        {
            temp = temp->next;
            continue;
            ;
        }
        else
        {
            cout << temp->coef << "x^" << temp->exp;
        }
        temp = temp->next;
    }
    cout << endl;
}

float Poly::result(float x)
{
    PolyNode *temp = first;
    float result = 0;
    while (temp->next != NULL)
    {
        temp = temp->next;
        result += temp->coef * pow(x, temp->exp);
    }
    return result;
}

int Poly::add(Poly poly)
{
    if (poly.length() != 0)
    {
        PolyNode *current = poly.first->next;
        while (current != NULL)
        {
            insert(current->coef, current->exp);
            current = current->next;
        }
        return 1;
    }
    return 0;
}

int Poly::reduce(Poly poly)
{
    if (poly.length() != 0)
    {
        PolyNode *current = poly.first->next;
        while (current != NULL)
        {
            remove(current->exp, current->coef);
            current = current->next;
        }
        return 1;
    }
    return 0;
}

Poly Poly::multiply(Poly poly)
{
    Poly result;
    if (poly.length() != 0)
    {
        PolyNode *current = poly.first->next;
        while (current != NULL)
        {
            for (PolyNode *node = first->next; node != NULL; node = node->next)
            {
                double coef = node->coef * current->coef;
                int exp = node->exp + current->exp;
                result.insert(coef, exp);
            }
            current = current->next;
        }
    }
    return result;
}

void Poly::derivatives()
{
    if (length() != 0)
    {
        PolyNode *current = first->next;
        while (current != NULL)
        {
            current->coef = current->coef * current->exp;
            current->exp = current->exp - 1;
            current = current->next;
        }
    }
}

int main()
{
    Poly myPoly1, myPoly2;
    Poly addPoly, multiplyPoly, reducePoly, dividePoly;
    char result;
    while (result != 'X')
    {
        cin >> result;
        if (result == 'C')
        {
            myPoly1.input(0);
            myPoly2.input(0);
        }
        else if (result == 'S')
        {
            reducePoly = myPoly1.copy();
            reducePoly.reduce(myPoly2);
            reducePoly.output();
        }
        else if (result == 'M')
        {
            multiplyPoly = myPoly1.copy();
            multiplyPoly = multiplyPoly.multiply(myPoly2);
            multiplyPoly.output();
        }
        else if (result == 'P')
        {
            addPoly = myPoly1.copy();
            addPoly.add(myPoly2);
            addPoly.output();
        }
        else if (result == 'D')
        {
            dividePoly = myPoly1.copy();
            dividePoly.derivatives();
            dividePoly.output();
        }
        else if (result == 'V')
        {
            float num;
            cin >> num;
            printf("%.2f\n", myPoly1.result(num));
        }
        else if (result == 'E')
        {
            myPoly1.MakeEmpty();
            myPoly2.MakeEmpty();
            reducePoly.MakeEmpty();
            addPoly.MakeEmpty();
            multiplyPoly.MakeEmpty();
            dividePoly.MakeEmpty();
        }
    }
    return 0;
}