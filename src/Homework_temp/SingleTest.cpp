#include <iostream>
#include "Single.cpp"
using namespace std;

int main()
{
    SingleList myList;
    int num;
    cin >> num;
    myList.input(num);
    myList.output();
    SingleList myList2;
    int num2;
    cin >> num2;
    myList2.input(num2);
    myList2.output();
    myList.add(&myList2);
    myList.output();
    return 0;
}