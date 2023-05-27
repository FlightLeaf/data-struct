#include <iostream>
#include <stdlib.h>

using namespace std;
const int DafaultSize = 200;

struct Trituple
{
    /// @brief 行号
    int row;
    /// @brief 列号
    int col;
    /// @brief 元素的值
    int value;
    Trituple &operator=(Trituple &x)
    {
        row = x.row;
        col = x.col;
        value = x.value;
    }
};

class SparseMatrix
{
public:
    /// @brief 构造函数
    /// @param maxSize 最大容量
    SparseMatrix(int maxSize = DafaultSize)
    {
        if (maxSize < 1)
        {
            cerr << "初始化错误！" << endl;
            exit(1);
        }
        maxTerms = maxSize;
        smArrays = new Trituple[maxTerms];
        if (smArrays == NULL)
        {
            cerr << "存储分配错误！" << endl;
            exit(1);
        }
        Rows = Cols = Terms = 0;
    }
    /// @brief 析构函数
    ~SparseMatrix() { delete[] smArrays; };

    void input();

    void output();

    //void transpose(SparseMatrix &x);

    /// @brief 矩阵求和 x = x + y 
    /// @param x 
    /// @param y
    void add(SparseMatrix &x,SparseMatrix &y);
    
private:
    /// @brief 行数
    int Rows;

    /// @brief 列数
    int Cols;

    /// @brief 非零元素个数
    int Terms;

    /// @brief 非零元素的集合
    Trituple *smArrays;

    /// @brief 最大容量
    int maxTerms;
};

void SparseMatrix::input()
{
    cin>>Rows>>Cols>>Terms;
    for(int i=0; i<Terms;i++)
    {
        cin>>smArrays[i].row>>smArrays[i].col>>smArrays[i].value;
    }
}

void SparseMatrix::output()
{
    cout<<Rows<<" "<<Cols<<" "<<Terms<<endl;
    for(int i=0;i<Terms;i++)
    {
        cout<<smArrays[i].row<<" "<<smArrays[i].col<<" "<<smArrays[i].value<<endl;
    }
}

void SparseMatrix::add(SparseMatrix& x,SparseMatrix& y)
{
    

}

int main()
{
    SparseMatrix matrix;
    matrix.input();
    matrix.output();
    return 0;
}
