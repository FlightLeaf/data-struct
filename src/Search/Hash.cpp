#include <iostream>
#include <math.h>
using namespace std;
int Hash(int *s, int N);
int main()
{
    int N;
    cin >> N;
    int *s = new int[N];
    Hash(s, N);
    for (int i = 0; i < N; i++)
    {
        cout << i << ":";
        if (s[i] != 0) // 0表示该存储单元没有存放数据；
            cout << s[i];
        cout << endl;
    }
    return 0;
}
int Hash(int *s, int N)
{
    for (int i = 0; i < N; i++)
    {
        s[i] = 0;
    }
    int num;
    cin >> num;
    int key;
    int d, odd = 0, save = 1;
    int temp;
    for (int i = 0; i < num; i++)
    {
        cin >> key;
        d = key % N;
        if (s[d] == 0)
        {
            s[d] = key;
        }
        else
        {
            odd = 0;
            save = 1;
            do
            {
                temp = d;
                if (odd % 2 == 0)
                {
                    temp = (d + (save * save)) % N;
                }
                else
                {
                    temp = (d - (save * save)) % N;
                    save++;
                }
                odd++;
            } while (s[temp] != 0);
            s[temp] = key;
        }
    }
    return 0;
}