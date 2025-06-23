#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> stk;
    
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            stk.push(c); // Push opening brackets
        } 
        else if (c == ')' || c == '}' || c == ']') {
            if (stk.empty()) return false; // No opening bracket to match

            char top = stk.top();
            if ((c == ')' && top == '(') ||
                (c == '}' && top == '{') ||
                (c == ']' && top == '[')) {
                stk.pop(); // Matched, remove from stack
            } 
            else {
                return false; // Mismatched brackets
            }
        }
    }
    
    return stk.empty(); // True if all brackets are matched
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    if (isValid(str))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
