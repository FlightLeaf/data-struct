#include <iostream>
#include <stdlib.h>
#include "linkList.cpp"
using namespace std;

int main()
{
    SeqList myList(100);
    myList.Input();
    myList.Output();
    int i;
    for (i = 0; i < 5; i++)
        myList.Insert(i + 10, i);
    myList.Output();
    for (i = 10; i < 15; i++)
        myList.Remove(i);
    myList.Output();
    return 0;
}