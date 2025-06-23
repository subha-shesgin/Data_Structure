#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<char> stk;
    string S;

    cout << "Enter S: ";
    cin >> S;

    // Push each character of S into the stack
    for (char c : S) {
        stk.push(c);
    }

    // Pop and print each character in LIFO order (reverse order)
    cout << "Reversed string: ";
    while (!stk.empty()) {
        cout << stk.top(); // Print the top element
        stk.pop(); // Remove the top element
    }

    cout << endl;
    return 0;
}
