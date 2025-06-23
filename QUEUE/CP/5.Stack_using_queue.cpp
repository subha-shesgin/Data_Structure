#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MyStack {
private:
    queue<int> q1, q2; // Two queues for stack operations

public:
    /** Initialize the stack. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x) {
        q2.push(x); // Push to q2
        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        // Swap q1 and q2, so q1 always has the latest order
        swap(q1, q2);
    }

    /** Removes the element on top of the stack and returns it. */
    int pop() {
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }

    /** Get the top element. */
    int top() {
        return q1.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
};

// Driver function to simulate the example scenario
int main() {
    vector<string> operations = {"MyStack", "push", "push", "top", "pop", "empty"};
    vector<vector<int>> values = {{}, {1}, {2}, {}, {}, {}};
    vector<string> output;

    MyStack myStack;
    output.push_back("null"); // Object creation

    for (size_t i = 1; i < operations.size(); i++) {
        if (operations[i] == "push") {
            myStack.push(values[i][0]);
            output.push_back("null");
        } 
        else if (operations[i] == "pop") {
            output.push_back(to_string(myStack.pop()));
        } 
        else if (operations[i] == "top") {
            output.push_back(to_string(myStack.top()));
        } 
        else if (operations[i] == "empty") {
            output.push_back(myStack.empty() ? "true" : "false");
        }
    }

    // Print output in the required format
    cout << "[";
    for (size_t i = 0; i < output.size(); i++) {
        cout << output[i];
        if (i != output.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
