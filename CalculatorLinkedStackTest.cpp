#include"CalculatorLinkedStack.cpp"
using namespace std;
int main()
{
    CalculatorLinkedStack c;
    char temp[] = "1+2)+2+3)";
    cout<<c.judge(temp);
    return 0;
}
