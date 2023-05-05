#include "SeqList.cpp"
typedef int T;
int main()
{
    SeqList myList(100);

    int i = 0;
    for(i = 0;i<5;i++)
        myList.Insert(i+10,i);
    myList.output();

    for(i=10;i<15;i++)
        myList.Remove(i);
    myList.output();
    
    return 0;
}

