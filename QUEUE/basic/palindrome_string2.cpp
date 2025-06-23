#include <iostream>
#include <cctype>    // For toupper() and isalpha()
#include <stack>
#include <queue>

using namespace std;

int main() {
    stack<char> s;  // STL stack
    queue<char> q;  // STL queue
    char ch;
    int mismatches = 0;

    cout << "Enter string: " << endl;

    // Read characters until a newline is encountered
    while (cin.peek() != '\n') {  // Continue until the newline character
        cin >> ch;  // Read a character
        if (isalpha(ch)) {  // Ignore non-alphabet characters
            ch = toupper(ch);  // Convert to uppercase
            s.push(ch);  // Push to stack (LIFO)
            q.push(ch);  // Enqueue to queue (FIFO)
        }
    }

    // Compare Stack (LIFO) and Queue (FIFO)
    while (!q.empty() && !s.empty()) {
        char sItem = s.top();   // Get top item from stack
        char qItem = q.front(); // Get front item from queue

        if (sItem != qItem) {
            ++mismatches;  // Count mismatches
        }

        s.pop();  // Pop from stack (remove top item)
        q.pop();  // Dequeue from queue (remove front item)
    }

    // If there are no mismatches, it's a palindrome
    if (mismatches == 0)
        cout << "That is a palindrome" << endl;
    else
        cout << "That is not a palindrome" << endl;

    return 0;
}
