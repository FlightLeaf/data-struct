#include <iostream>
#include <stdlib.h>
using namespace std;
typedef int T;
class SeqList
{
private:
    T *data;
    int MaxSize;
    int last;

public:
    SeqList(int sz);
    ~SeqList();
    int Length() { return last + 1; }
    int Find(T &x);
    void Insert(const T &x, int i);
    int Remove(T &x);
    int IsEmpty() { return last == -1; }
    int IsFull() { return last == MaxSize - 1; }
    T GetData(int i) { return data[i]; }
    void SetData(int i, T &x)
    {
        if (i > 0 && i <= last + 1)
        {
            data[i - 1] = x;
        }
    }
    void reduce(SeqList &sq);
    void input();
    void output();
};

int SeqList::Find(T &x)
{
    int i = 0;
    while (i <= last && data[i] != x)
        i++;
    if (i > last)
        return -1;
    else
        return i + 1;
}

void SeqList::Insert(const T &x, int i)
{
    // 0<=i<=last+1
    if (last == MaxSize - 1)
    {
        cerr << "顺序表已满无法插入!" << endl;
        exit(1);
    }
    if (i < 0 || i > last + 1)
    {
        cerr << "参数i越界出错!" << endl;
        exit(1);
    }
    last++;
    for (int j = last; j > i; j--)
    {
        data[j] = data[j - 1];
    }
    data[i] = x;
}
int SeqList ::Remove(T &x)
{
    int i = Find(x) - 1;
    if (i >= 0)
    {
        last--;
        for (int j = i; j <= last; j++)
            data[j] = data[j + 1];
        return 1;
    }
    return 0;
}

SeqList::SeqList(int sz)
{
    if (sz > 0)
    {
        data = new T[sz];
        if (data != NULL)
        {
            MaxSize = sz;
            last = -1;
        }
        else
        {
            cerr << "储存分配错误！" << endl;
            exit(1);
        }
    }
}
// 删除方法
SeqList::~SeqList()
{
    delete[] data;
}
// 输入数据
void SeqList::input()
{
    while (1)
    {
        cin >> last;
        if (last <= MaxSize && last > 0)
            break;
    }
    for (int i = 0; i < last; i++)
    {
        cin >> data[i];
    }
    last--;
}
// 输出数据
void SeqList::output()
{
    for (int i = 0; i <= last; i++)
        cout << data[i] << " ";
}

/*void SeqList::reduce(SeqList &sq)
{
    int index[20];
    int count = 0;
    for (int j = 0; j < Length(); j++)
    {
        for (int i = 0; i < sq.Length(); i++)
        {
            if (sq.GetData(i) == data[j])
            {
                index[count] = data[j];
                count++;
            }
        }
    }
    for(int i = 0;i<count;i++)
    {
        cout<<index[i]<<endl;
    }
}*/

void SeqList::reduce(SeqList &sq)
{
    int i,j;
    int index[20];
    int count=0;
    for(i=0;i<Length();i++){
        for(j=0;j<sq.Length();j++)
        {
            if(sq.GetData(j)==data[i])
            {
                index[count]=data[i];
                count++;
            }
        }
    }
    for(int i=0;i<count;i++)
    {
        count<<index[i]<<endl;
    }
}


int main()
{
    SeqList sq1 = SeqList(20);
    sq1.input();
    //sq1.output();
    SeqList sq2 = SeqList(20);
    sq2.input();
    //sq2.output();
    sq1.reduce(sq2);
    //sq1.output();
    return 0;
}