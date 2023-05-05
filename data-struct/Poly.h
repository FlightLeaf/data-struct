#ifndef POLY_H
#define POLY_H

#include<math.h>
#include<iostream>
using namespace std;
class PolyNode;
class Poly {
 public:
    Poly(){first = new PolyNode();};
    ~Poly(){MakeEmpty();};
    /*清空多项式*/
    void MakeEmpty();  
    /*返回多项式长度*/
    int Length();  
    /*找到exp的位置并返回PolyNode指针*/
    PolyNode *Find(int exp);   
    /*新项的插入*/
    int Insert(double coef,int exp);   
    /*移除特定的某一项，系数可以为空*/
    int Remove(int exp,double coef = 0);    
    /*判断多项式是否为空*/
    int IsEmpty();          
    /*输入多项式*/
    void input(int endTag); 
    /*输出多项式*/
    void output();          
    /*给多项式输入数值后计算结果*/
    double result(double x); 
    /*原多项式加多项式*/
    int add(Poly ploy);     
    /*原多项式减多项式*/
    int reduce(Poly poly); 
    /*多项式相乘*/
    int multiply(Poly ploy); 
 private:
    PolyNode* first;
};

void Poly::MakeEmpty()
{
    PolyNode *temp;
    while(first->link!=NULL)
    {
        temp = first->link;
        first->link = temp->link;
        delete temp;    
    }
}

int Poly::Length()
{
    int result = 0;
    PolyNode *temp = first->link;
    while (temp!=NULL)
    {
        result++;    
        temp = temp->link;
    }
    return result;
}

PolyNode *Poly::Find(int exp)
{
    if(exp<0)return 0;
    PolyNode *temp = first;
    while(temp->link!=0)
    {
        if(temp->link->exp==exp)
        {
            return temp->link;
        }
        else
        {
            temp = temp->link;
        }
    }
    return 0;
}

int Poly::Insert(double coef, int exp)
{
    if(coef != 0)
    {
        PolyNode *current = first;
        while (current->link != NULL && current->link->exp < exp) {//判断当输入的exp小于等于原多项式中的某一项时就可以插入这一位置
            current = current->link;
        }
        if (current->link != NULL && current->exp == exp) {//如果exp相同则合并系数即可
            current->coef += coef;
        }
        else {
            PolyNode *new_node = new PolyNode(coef, exp);//如果不相同则新建插入
            new_node->link = current->link;
            current->link = new_node;
        }
        return 1;
    }
    return 0;
}


int Poly::Remove(int exp,double coef)
{
    int result = 0;
    if(coef == 0) // 如果删除系数为0的项，则忽略传入的coef参数
    {
        PolyNode *prev = first;
        PolyNode *current = first->link;
        while (current != NULL)
        {
            if(current->exp == exp)
            {
                prev->link = current->link;
                delete current;
                result = 1;
                break;
                current = prev->link;
            }
            else
            {
                prev = current;
                current = current->link;
            }
        }
    }
    else
    {
        PolyNode *temp = Find(exp);
        if(temp!=NULL)
        {
            if(temp->coef==coef)
            {
                if(temp == first->link)//如果是第一项，则特殊处理
                {
                    first->link = temp->link;
                }
                else
                {
                    PolyNode *prev = first->link;
                    while(prev->link != temp) prev = prev->link;
                    prev->link = temp->link;
                }
                delete temp;
                result = 1;
            }
            else if(temp->coef!=coef)//系数不同则执行相减
            {
                temp->coef = temp->coef-coef;
                result = 1;
            }
        }
    }
    return result;
}


int Poly::IsEmpty()
{
    return(first->link == NULL?1:0);
}

void Poly::input(int endTag)
{
    double coef = 0.0;
    int exp = 0;
    do {
        cin>>coef>>exp;
        if (coef != endTag) {
            Insert(coef, exp);
        }
    } while (coef != endTag);
}

void Poly::output()
{
    PolyNode *temp = first->link;
    while(temp!=NULL)
    {
        cout<<temp->coef<<"*x^"<<temp->exp<<endl;
        temp = temp->link;
    }
}

double Poly::result(double x)
{
    PolyNode *temp = first;
    double result = 0;
    while (temp->link!=NULL)
    {
        temp = temp->link;
        result += temp->coef * pow(x, temp->exp);
    }
    return result;
}

int Poly::add(Poly poly)
{
    if(poly.Length()!=0)
    {
        PolyNode *current = poly.first->link;
        while (current != NULL)
        {
            Insert(current->coef,current->exp);
            current = current->link;
        }
        return 1;
    }
    return 0;
}

int Poly::reduce(Poly poly)
{
     if(poly.Length()!=0)
    {
        PolyNode *current = poly.first->link;
        while (current != NULL)
        {
            Remove(current->coef,current->exp);
            current = current->link;
        }
        return 1;
    }
    return 0;
}

int Poly::multiply(Poly poly)
{
    if(poly.Length()!=0)
    {
        Poly result;
        PolyNode *current = poly.first->link;
        while (current != NULL)
        {
            for (PolyNode *node = first->link; node != NULL; node = node->link)
            {
                double coef = node->coef * current->coef;
                int exp = node->exp + current->exp;
                result.Insert(coef, exp);
            }
            current = current->link;
        }
        MakeEmpty();
        PolyNode *temp = result.first->link;
        while (temp != nullptr)
        {
            Insert(temp->coef, temp->exp);
            temp = temp->link;
        }
        return 1;
    }
    return 0;
}

class PolyNode {
 private:
  friend Poly;
  double coef;
  int exp;
  PolyNode* link;

 public:
  PolyNode(PolyNode* temp = NULL) { link = temp; }
  PolyNode(double coef, int exp, PolyNode* temp = NULL) {
    this->coef = coef;
    this->exp = exp;
    link = temp;
  }
  ~PolyNode() {}
};

#endif