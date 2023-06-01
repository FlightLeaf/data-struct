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
    ~SparseMatrix() { //delete[] smArrays;
     };

    /// @brief 输入矩阵
    void input();

    /// @brief 输出矩阵
    void output();

    /// @brief 转置
    /// @param x 转置后的矩阵
    void transpose(SparseMatrix &x);

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
    cin >> Rows >> Cols >> Terms;
    for (int i = 0; i < Terms; i++)
    {
        cin >> smArrays[i].row >> smArrays[i].col >> smArrays[i].value;
    }
}

void SparseMatrix::output()
{
    for (int i = 0; i < Terms; i++)
    {
        cout << smArrays[i].row << " " << smArrays[i].col << " " << smArrays[i].value << endl;
    }
}

void SparseMatrix::add(SparseMatrix &x,SparseMatrix &y)
{
    if (x.Rows != y.Rows || x.Cols != y.Cols) 
    {
        cerr << "矩阵行列不匹配！" << endl;
        return;
    }
    SparseMatrix z(x.maxTerms + y.maxTerms);

    int p1 = 0, p2 = 0, p3 = 0;

    while (p1 < x.Terms && p2 < y.Terms)
    {
        if (x.smArrays[p1].row < y.smArrays[p2].row ||
            (x.smArrays[p1].row == y.smArrays[p2].row &&
             x.smArrays[p1].col < y.smArrays[p2].col))
        {
            z.smArrays[p3++] = x.smArrays[p1++];
        }
        else if (x.smArrays[p1].row > y.smArrays[p2].row ||
                 (x.smArrays[p1].row == y.smArrays[p2].row &&
                  x.smArrays[p1].col > y.smArrays[p2].col))
        {
            z.smArrays[p3++] = y.smArrays[p2++];
        }
        else
        {
            Trituple temp;
            temp.row = x.smArrays[p1].row;
            temp.col = x.smArrays[p1].col;
            temp.value = x.smArrays[p1].value + y.smArrays[p2].value;
            if (temp.value != 0) 
            {
                z.smArrays[p3++] = temp;
            }
            p1++;
            p2++;
        }
    }

    while (p1 < x.Terms)
    {
        z.smArrays[p3++] = x.smArrays[p1++];
    }
    while (p2 < y.Terms)
    {
        z.smArrays[p3++] = y.smArrays[p2++];
    }

    z.Rows = x.Rows;
    z.Cols = x.Cols;
    z.Terms = p3;

    x = z;
}

 
void SparseMatrix::transpose(SparseMatrix &x)
{
    int *rowSize = new int[Cols];
    int *rowStart = new int[Cols];
    x.Cols = Rows;
    x.Rows = Cols;
    x.Terms = Terms;
    if (Terms > 0)
    {
        int i, j;
        for (i = 0; i < Cols; i++)
        {
            rowSize[i] = 0;
        }
        for (i = 0; i < Terms; i++)
        {
            rowSize[smArrays[i].col]++;
        }
        rowStart[0] = 0;
        for (i = 1; i < Cols; i++)
        {
            rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
        }
        for(i = 0; i < Terms; i++)
        {
            j = rowStart[smArrays[i].col];
            x.smArrays[j].row = smArrays[i].col;
            x.smArrays[j].col = smArrays[i].row;
            x.smArrays[j].value = smArrays[i].value;
            rowStart[smArrays[i].col] ++;
        }
        delete[] rowStart;
        delete[] rowSize;
    }
}

int main()
{
    SparseMatrix matrix1,matrix2,transform;
    matrix1.input();
    matrix2.input();
    matrix1.transpose(transform);
    cout<<"The transformed matrix  is:"<<endl;
    transform.output();
    matrix1.add(matrix1,matrix2);
    cout<<"The added matrix is:"<<endl;
    matrix1.output();
    return 0;
}
