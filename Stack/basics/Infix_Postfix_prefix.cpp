#include <iostream>
#include <stack>
#include <cctype>
#include <algorithm>
using namespace std;

// Function to check if the character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to check precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Infix to Postfix conversion
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";
    
    for (char& c : infix) {
        // If the character is an operand, add it to the output
        if (isalnum(c)) {
            postfix += c;
        }
        // If the character is '(', push it to stack
        else if (c == '(') {
            s.push(c);
        }
        // If the character is ')', pop and output until '(' is encountered
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();  // Pop the '('
        }
        // If the character is an operator
        else if (isOperator(c)) {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    // Pop all the remaining operators
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

// Function to evaluate Postfix expression
int evaluatePostfix(string postfix) {
    stack<int> s;
    
    for (char& c : postfix) {
        if (isdigit(c)) {
            s.push(c - '0');  // Convert char to int and push onto the stack
        } else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            
            // Perform the operation based on the operator
            switch(c) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
        }
    }

    return s.top();
}

// Function to reverse a string
string reverseString(string str) {
    reverse(str.begin(), str.end());
    return str;
}

// Function to convert Infix to Prefix
string infixToPrefix(string infix) {
    // Reverse the infix expression
    infix = reverseString(infix);
    
    // Replace '(' with ')' and vice versa
    for (int i = 0; i < infix.size(); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    // Convert the reversed infix to postfix (which is equivalent to prefix)
    string postfix = infixToPostfix(infix);

    // Reverse the postfix expression to get the prefix
    return reverseString(postfix);
}

// Function to evaluate Prefix expression
int evaluatePrefix(string prefix) {
    stack<int> s;
    
    // Reverse the prefix expression
    reverse(prefix.begin(), prefix.end());

    for (char& c : prefix) {
        if (isdigit(c)) {
            s.push(c - '0');  // Convert char to int and push onto the stack
        } else {
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();

            // Perform the operation based on the operator
            switch(c) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
        }
    }

    return s.top();
}

int main() {
    string infix, postfix, prefix;
    
    cout << "Enter Infix Expression: ";
    cin >> infix;

    // Convert Infix to Postfix
    postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    // Evaluate Postfix Expression
    cout << "Postfix Evaluation Result: " << evaluatePostfix(postfix) << endl;

    // Convert Infix to Prefix
    prefix = infixToPrefix(infix);
    cout << "Prefix Expression: " << prefix << endl;

    // Evaluate Prefix Expression
    cout << "Prefix Evaluation Result: " << evaluatePrefix(prefix) << endl;

    return 0;
}
