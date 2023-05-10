#include "LinkedQueue.cpp"

using namespace std;

int main()
{
    LinkedQueue<int> queue;
    for (int i = 0; i < 10; i++)
        queue.EnQueue(i);
    cout << queue << endl;
    cout << "********************************" << endl;
    cout << queue.getSize() << endl;
    return 0;
}