#include <iostream>
#include <stdlib.h>

const int DafaultSize = 100;

template <class T>
struct Trituple
{
    /// @brief 行号
    int row;
    /// @brief 列号
    int col;
    /// @brief 元素的值
    T value;
    Trituple<T> &operator=(Trituple<T> &x)
    {
        row = x.row;
        col = x.col;
        value = x.value;
    }
};

template <class T>
class SparseMatrix
{
    friend ostraem &operator<<(ostream &out, SparseMatrix<T> &M);
    friend istream &operator>>(istream &in, SparseMatrix<T> &M);

public:
    /// @brief 构造函数
    /// @param maxSize 最大容量
    SparseMatrix(int maxSize = DafaultSize);

    /// @brief 复制构造函数
    /// @param x 目标
    SparseMatrix(SparseMatrix<T> &x);

    /// @brief 析构函数
    ~SparseMatrix() { delete[] smArrays; };

    /// @brief 赋值运算符重载函数
    /// @param x
    /// @return 该函数接受一个参数 x，表示另一个类型为 SparseMatrix 的对象，
    /// @return 赋值运算符重载函数的本质是将当前对象的值 （SparseMatrix 类型）
    /// @return 设置为参数对象的一个副本。为了确保两个对象互相独立，需要先删除当前对象的原有数据，再逐一复制参数对象中的数据到当前对象中
    SparseMatrix<T> &operator=(SparseMatrix<T> &x);

    /// @brief 矩阵转置运算
    /// @return 转置后的矩阵
    SparseMatrix<T> Transpose();

    /// @brief 矩阵相加
    /// @param b 被加数
    /// @return 结果矩阵
    SparseMatrix<T> Add(SparseMatrix<T> &b);

    /// @brief 矩阵相乘
    /// @param b 被乘数
    /// @return 结果矩阵
    SparseMatrix<T> Multiply(SparseMatrix<T> &b);

private:
    int Rows, Cols, Terms;
    Trituple<T> *smArrays;
    int maxTerms;
};

template <class T>
SparseMatrix<T>::SparseMatrix(int size) : maxTerms(size)
{
    if (size < 1)
    {
        cerr << "初始化错误！" << endl;
        exit(1);
    }
    smArrays = new Trituple<T>[size];
    if (smArrays == NULL)
    {
        cerr << "存储分配错误！" << endl;
        exit(1);
    }
    Rows = Cols = Terms = 0;
}

template <class T>
SparseMatrix<T>::SparseMatrix(SparseMatrix<T> &x)
{
    Rows = matrix.Rows;
    Cols = matrix.Cols;
    Terms = matrix.Terms;
    maxTerms = matrix.MaxTerms;
    smArrays = new Trituple<T>[maxTerms];
    if (smArrays == nullptr)
    {
        cerr << "存储分配错误！" << endl;
        exit(1);
    }
    for (int i = 0; i < Terms; i++)
    {
        smArrays[i] = x.smArrays[i];
    }
}


