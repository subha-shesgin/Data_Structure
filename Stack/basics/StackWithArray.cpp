#include <iostream>

#define MAX 100  // Define the maximum size of the stack

using namespace std;

int stack[MAX];  // Array to store stack elements
int top = -1;    // Variable to keep track of the top element

// Check if stack is empty
bool isEmpty() {
    return top == -1;
}

// Check if stack is full
bool isFull() {
    return top == MAX - 1;
}

// Push operation
void push(int value) {
    if (isFull()) {
        cout << "Stack Overflow!" << endl;
        return;
    }
    stack[++top] = value;
}

// Pop operation
int pop() {
    if (isEmpty()) {
        cout << "Stack Underflow!" << endl;
        return -1;
    }
    return stack[top--];
}

// Peek operation
int peek() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    return stack[top];
}

// Main function
int main() {
    push(10);
    push(20);
    push(30);

    cout << "Top element: " << peek() << endl;

    cout << "Popped: " << pop() << endl;
    cout << "Popped: " << pop() << endl;

    return 0;
}
