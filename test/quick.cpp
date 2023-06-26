#include <iostream>

using namespace std;

void quickSort(int a[],int left,int right);

int main()

{

    int len, k;

    cin >> len; // 输入需要排序的数据个数；

    int *array = new int[len];

    for (k = 0; k < len; k++)
        cin >> array[k];

    cout << "The orginal array are:" << endl;

    for (k = 0; k < len; k++)

        cout << array[k] << " ";

    cout << endl;

    cout << "The processing is:" << endl;

    quickSort(array, 0, len - 1);

    cout << "The sorted array are:" << endl;

    for (k = 0; k < len; k++)

        cout << array[k] << " ";

    cout << endl;

    return 0;
}

void quickSort(int a[],int left,int right)
{
    
}