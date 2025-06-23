#include <stack>
#include <iostream>
using namespace std;

stack<int> s1, s2; // Two stacks: s1 for pushing, s2 for popping

void push(int x) {
    s1.push(x); // Push element to stack s1
}

int pop() {
    if (s2.empty()) { // Transfer elements only if s2 is empty
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    int front = s2.top();
    s2.pop();
    return front;
}

int peek() {
    if (s2.empty()) { // Transfer elements only if s2 is empty
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    return s2.top();
}

bool empty() {
    return s1.empty() && s2.empty();
}

int main() {
    push(1);
    push(2);
    cout << peek() << endl; // Returns 1
    cout << pop() << endl;  // Returns 1
    cout << empty() << endl; // Returns false
    return 0;
}
