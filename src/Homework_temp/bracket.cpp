#include <LinkedStack.h>
using namespace std;

char exchange(const char buf)
{
    char buf_;
    switch (buf)
    {
    case '(':
        return ')';
    case '[':
        return ']';
    case '{':
        return '}';
    case '<':
        return '>';
    }
};

int main()
{
    char buf;
    cin >> buf;
    LinkedStack<char> stack;
    int local = 1;
    do
    {
        if (buf == '(' || buf == '{' || buf == '<' || buf == '[')
        {
            stack.Push(buf);
        }
        else if (buf == '}' || buf == ')' || buf == ']' || buf == '>')
        {
            char temp;
            stack.getTop(temp);
            if (buf == exchange(temp))
            {
                stack.Pop(temp);
            }
            if (buf != exchange(temp))
            {
                // The 6 character '>' is wrong.
                cout << "The " << local << " character '" << buf << "' is wrong." << endl;
                return 0;
            }
        }
        cin >> buf;
        local++;
    } while (buf != '#');
    if (!stack.IsEmpty())
    {
        cout << "loss of right character ";
        int i = stack.getSize();
        char temp;
        while (i != 0)
        {
            stack.Pop(temp);
            cout << exchange(temp);
            i--;
        }
        cout << "." << endl;
        return 0;
    }
    cout << "right" << endl;
    return 0;
}