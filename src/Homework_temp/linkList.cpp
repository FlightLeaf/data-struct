#include <iostream>
#include <stdlib.h>
using namespace std;
typedef int T;
class SeqList
{
private:
    T *data;
    int MaxSize; // 顺序表最多可以存放的元素个数。
    int last;    // 顺序表最后一个元素的下标，初始值为-1。
public:
    SeqList(int sz);
    void Input();                   // 首先输入元素的个数，然后顺次输入元素的值。
    void Output();                  // 输出线性表的所有元素。
    void Insert(const T &x, int i); // 在线性表中第i个位置插入值为x的元素。
    void Remove(T &x);              // 从线性表中删除第一个值等于x的元素。
};

SeqList::SeqList(int sz)
{
    data = new T[sz];
    MaxSize = sz;
    last = -1;
}

void SeqList::Input()
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

void SeqList::Output()
{
    cout << "The elements are:" << endl;
    for (int i = 0; i <= last; i++)
    {
        cout << data[i] << endl;
    }
}

void SeqList::Insert(const T &x, int i)
{
    if (last == MaxSize - 1)
    {
        exit(1);
    }
    if (i < 0 || i > last + 1)
    {
        exit(1);
    }
    last++;
    for (int j = last; j > i; j--)
    {
        data[j] = data[j - 1];
    }
    data[i] = x;
}

void SeqList::Remove(T &x)
{
    int index;
    for (int i = 0; i <= last; i++)
    {
        if (data[i] == x)
        {
            index = i;
            break;
        }
    }
    for (int i = index; i <= last; i++)
    {
        data[i] = data[i + 1];
    }
    last--;
}