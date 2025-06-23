#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if a character is an operand (A-Z or a-z)
bool isOperand(char c) {
    return isalpha(c);
}

// Function to determine precedence of operators
int precedence(char op) {
    if (op == '^') return 3;  // Right-associative
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}
void reverseString(string &str) {
    int left = 0, right = str.length() - 1;
    
    while (left < right) {
        swap(str[left], str[right]);  // Swap characters
        left++;
        right--;
    }
}
// Function to convert infix expression to prefix
string infixToPrefix(string infix) {
    // Step 1: Reverse the infix expression and swap '(' with ')'
    reverseString(infix);

    for (char &c : infix) {
        if (c == '(') 
            c = ')';
        else if (c == ')') 
            c = '(';
    }

    // Step 2: Convert reversed infix expression to postfix
    stack<char> s;
    string postfix = "";

    for (char c : infix) {
        if (isOperand(c)) {
            // If operand, directly add to postfix expression
            postfix += c;
        } 
        else if (c == '(') {
            // Push opening parenthesis onto the stack
            s.push(c);
        } 
        else if (c == ')') {
            // Pop from stack to output until '(' is found
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Remove '(' from stack
        } 
        else {
            // Operator encountered: Maintain correct precedence order
            while (!s.empty() && precedence(s.top()) > precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    // Pop any remaining operators in the stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    // Step 3: Reverse postfix expression to get prefix expression
   reverseString(postfix);

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}
