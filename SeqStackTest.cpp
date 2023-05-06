#include"SeqStack.cpp"
using namespace std;
int main()
{
    SeqStack<int> stack(40);
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    for(int i = 0;i<10;i++)
    {
        stack.Push(a[i]);
    }
    cout<<stack<<endl;
    return 0;
}