#include"SeqQueue.cpp"

using namespace std;

int main()
{
    SeqQueue<int> queue(14);
    
    for(int i=0; i<10; i++)
    {
        queue.EnQueue(i);
    }
    int front;
    queue.getFront(front);
    cout << queue << endl;  
    cout<< "********************************"<<endl;
    cout << front << endl;
    cout << queue.getSize() << endl;
    return 0;
}