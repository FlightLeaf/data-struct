#include<iostream>
using namespace std;
int main()
{
    char ch;
    double newoperand;
    while(cin.get(ch),ch != '#')
    {
        switch(ch)
        {
            case '+':case '-':case '*':case '/':
                cout << "##"<<endl;break;
            default:
                cin.putback(ch);
                cin>>newoperand;
                cout<<newoperand<<endl;
                break;
        }
    }
    return 0;
}