#include <iostream>
#include <cstring>
using namespace std;

// 链式栈结构体
template<typename T>
struct Node {
    T data;
    Node* next;
};

template<typename T>
class LinkedStack {
private:
    Node<T>* top_node;
public:
    LinkedStack() {
        top_node = nullptr;
    }
    ~LinkedStack() {
        clear();
    }
    bool is_empty() const {
        return (top_node == nullptr);
    }
    void push(T x) {
        Node<T>* new_node = new Node<T>{x, top_node};
        top_node = new_node;
    }
    T pop() {
        if (is_empty()) {
            cerr << "Error: the stack is empty." << endl;
            exit(-1);  // 终止程序
        }
        Node<T>* old_node = top_node;
        top_node = top_node->next;
        T value = old_node->data;
        delete old_node;
        return value;
    }
    T get_top() const {
        if (is_empty()) {
            cerr << "Error: the stack is empty." << endl;
            exit(-1);  // 终止程序
        }
        return top_node->data;
    }
    void clear() {
        while (!is_empty()) {
            pop();
        }
    }
};

// 将字符类型的运算符转换为相应的整数
int get_priority(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        default:
            return 0;  // 如果不是运算符，返回 0
    }
}

// 判断是否为运算符
bool is_operator(char ch) {
    return (get_priority(ch) > 0);
}

// 将中缀表达式转换为后缀表达式
string InfixToPostfix(const string& infix_str) {
    string postfix_str = "";  // 后缀表达式字符串
    LinkedStack<char> op_stack;  // 运算符栈

    for (int i = 0; i < infix_str.size(); ++i) {
        char ch = infix_str[i];

        if (ch == ' ') {  // 跳过空格
            continue;
        }
        else if (isdigit(ch)) {  // 如果是数字，直接输出到后缀表达式中
            postfix_str += ch;
        }
        else if (is_operator(ch)) {  // 如果是运算符
            while (!op_stack.is_empty() && is_operator(op_stack.get_top()) && get_priority(ch) <= get_priority(op_stack.get_top())) {
                postfix_str += op_stack.pop();
            }
            op_stack.push(ch);  // 将当前运算符入栈
        }
        else if (ch == '(') {  // 如果是左括号，将其入栈
            op_stack.push(ch);
        }
        else if (ch == ')') {  // 如果是右括号
            while (!op_stack.is_empty() && op_stack.get_top() != '(') {
                postfix_str += op_stack.pop();
            }
            if (!op_stack.is_empty() && op_stack.get_top() == '(') {
                op_stack.pop();  // 弹出左括号
            }
            else {
                cerr << "Error: mismatched parentheses." << endl;
                exit(-1);  // 终止程序
            }
        }
        else {
            cerr << "Error: invalid character - " << ch << endl;
            exit(-1);  // 终止程序
        }
    }

    while (!op_stack.is_empty()) {
        if (op_stack.get_top() == '(' || op_stack.get_top() == ')') {
            cerr << "Error: mismatched parentheses." << endl;
            exit(-1);  // 终止程序
        }
        postfix_str += op_stack.pop();
    }

    return postfix_str;
}

// 计算后缀表达式的结果
int PostfixEvaluate(const string& postfix_str) {
    LinkedStack<int> value_stack; // 操作数栈

    for (int i = 0; i < postfix_str.size(); ++i) {
        char ch = postfix_str[i];

        if (isdigit(ch)) {  // 如果是数字，压入操作数栈中
            int value = ch - '0';  // 字符转整数
            while (i+1 < postfix_str.size() && isdigit(postfix_str[i+1])) {
                value = value * 10 + (postfix_str[++i] - '0'); // 把多位数字拼接起来，依次累乘 10
            }
            value_stack.push(value);
        }
        else if (is_operator(ch)) {  // 如果是运算符，弹出两个操作数进行计算，并将结果压回栈中
            int y = value_stack.pop();
            int x = value_stack.pop();

            switch (ch) {
                case '+':
                    value_stack.push(x + y);
                    break;
                case '-':
                    value_stack.push(x - y);
                    break;
                case '*':
                    value_stack.push(x * y);
                    break;
                case '/':
                    if (y == 0) {
                        cerr << "Error: division by zero." << endl;
                        exit(-1); // 终止程序
                    }
                    value_stack.push(x / y);
                    break;
                case '%':
                    if (y == 0) {
                        cerr << "Error: division by zero." << endl;
                        exit(-1); // 终止程序
                    }
                    value_stack.push(x % y);
                    break;
                default:
                    break;
            }
        }
        else { // 如果是无效字符，抛出异常并终止程序
            cerr << "Error: invalid character - " << ch << endl;
            exit(-1);
        }
    }

    if (value_stack.is_empty()) {
        cerr << "Error: empty stack." << endl;
        exit(-1);  // 终止程序
    }

    return value_stack.pop();
}

int main() {
    string infix_str;  // 中缀表达式字符串
    cout << "Please input an infix expression: ";
    getline(cin, infix_str);

    string postfix_str = InfixToPostfix(infix_str);
    cout << "Postfix expression: " << postfix_str << endl;

    int result = PostfixEvaluate(postfix_str);
    cout << "Result: " << result << endl;

    return 0;
}
