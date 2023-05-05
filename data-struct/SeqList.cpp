#include<iostream>
#include<stdlib.h>
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
    //返回表长度
    int Length(){return last+1;}
    int Find(T&x);
    void Insert(const T&x,int i);
    int Remove(T&x);
    
    int IsEmpty(){return last == -1;}
    int IsFull(){return last == MaxSize-1;}
    //取表中第i个值
    T GetData(int i){return data[i-1];}
    //为第i个赋值
    void SetData(int i,T&x)
    {
        if(i>0&&i<=last+1)
        {
            data[i-1] = x;
        }
    }
    void input();
    void output();
};
//查询数据下表
int SeqList::Find(T&x)
{
    int i = 0;
    while (i<=last&&data[i]!=x)
        i++;
    if(i>last)
        return -1;
    else
        return i+1;
}
//在某一个位置插入数据
void SeqList::Insert(const T&x,int i)
{
    //0<=i<=last+1
    if(last == MaxSize-1)
    {
        cerr<<"顺序表已满无法插入!"<<endl;
        exit(1);
    }
    if(i<0||i>last+1)
    {
        cerr<<"参数i越界出错!"<<endl;
        exit(1);
    }
    last++;
    for(int j = last;j>i;j--)
    {
        data[j] = data[j-1];
    }
    data[i] = x;
}
//删除某一数据
int SeqList ::Remove(T&x)
{
    int i = Find(x)-1;
    if(i>=0)
    {
        last--;
        for(int j = i;j<=last;j++)
            data[j] = data[j+1];
        return 1;
    }
    return 0;
}
//构造方法
SeqList::SeqList(int sz)
{
    if(sz > 0)
    {
        data = new T[sz];
        if(data != NULL)
        {
            MaxSize = sz;
            last = -1;
        }
        else
        {
            cerr<<"储存分配错误！"<<endl;
            exit(1);
        }
    }
}
//删除方法
SeqList::~SeqList()
{
    delete [] data;
}
//输入数据
void SeqList::input()
{
    cout<<"开始建立顺序表，请输入元素个数"<<endl;
    while(1)
    {
        cin>>last;
        if(last<=MaxSize&&last>0)
            break;
        cout<<"元素个数有误，范围1~"<<MaxSize-1<<endl;
    }
    for(int i = 0;i<last;i++)
    {
        cout<<"请输入第"<<i+1<<"个元素："<<endl;
        cin>>data[i];
    }
    cout<<"建表完成！"<<endl;
    last--;
}
//输出数据
void SeqList::output()
{
    cout<<"顺序表元素个数为："<<last+1<<endl;
    for(int i = 0;i<=last;i++)
        cout<<i+1<<":"<<data[i]<<endl;
}