/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <iostream>
#include <stdlib.h>
using namespace std;
typedef char T;
class SeqList
{
private:
    T *data;
    int MaxSize;
    int last;
public:
    SeqList(int sz);
    ~SeqList() { delete[] data; }
    void input();
    int huiwen();
};
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
            cerr << "存储分配错误！" << endl;
            exit(1);
        }
    }
}
void SeqList::input()
{
    while (1)
    {
        cin >> last;
        if (last <= MaxSize && last > 0)
            break;
        cout << "元素个数有误，范围1~" << MaxSize - 1 << endl;
    }
    for (int i = 0; i < last; i++)
    {
        cin >> data[i];
    }
    last--;
}

int SeqList::huiwen()
{
    int index = last,i;
    for(i = 0;i<=last;i++)
    {
        if(data[i]!=data[index])
        {
            break;
        }
        index = index-1;
    }
    if(i == last+1)
    {
        return 1;
    }
    return 0;
}

int main()
{

    SeqList myList(100);

    myList.input();

    cout << myList.huiwen();

    return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */