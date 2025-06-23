#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperand(char c) {
    // Using built-in function isalpha to check if c is an alphabet letter
    return isalpha(c);
}

int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/' || op == '%') return 2;
    if(op == '+' || op == '-') return 1;
    return -1; // For any non-operator character
}

int main() {
    string infix;
    cin >> infix;
    
    stack<char> s;
    string postfix = "";
    
    for (char c : infix) {
        if (isOperand(c)) {
            // Directly add operands to the postfix string.
            postfix.push_back(c);
        }
        else if (c == '(') {
            // Push opening parenthesis onto stack.
            s.push(c);
        }
        else if (c == ')') {
            // Pop and output from the stack until an '(' is encountered.
            while (!s.empty() && s.top() != '(') {
                postfix.push_back(s.top());
                s.pop();
            }
            if (!s.empty())
                s.pop(); // Remove the '(' from the stack.
        }
        else {
            // Operator encountered:
            // Pop operators from the stack with higher or equal precedence.
            while (!s.empty() && s.top() != '(' && precedence(s.top()) >= precedence(c)) {
                postfix.push_back(s.top());
                s.pop();
            }
            // Push the current operator onto the stack.
            s.push(c);
        }
    }
    
    // Pop any remaining operators from the stack.
    while (!s.empty()) {
        if (s.top() != '(')
            postfix.push_back(s.top());
        s.pop();
    }
    
    cout << postfix << endl;
    return 0;
}
