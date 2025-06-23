#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    int T;
    cin >> T; // Number of test cases
    
    for (int i = 0; i < T; i++) {
        queue<int> q;
        stack<int> reverse;
        int n;
        cin >> n; // Number of elements
        
        // Input elements into the queue
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            q.push(num);
        }

        // Move elements from queue to stack to reverse them
        while (!q.empty()) {
            reverse.push(q.front());
            q.pop();
        }

        // Move back from stack to queue (reversed order)
        while (!reverse.empty()) {
            q.push(reverse.top());
            reverse.pop();
        }

        // Print reversed queue
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl; // Print a newline for each test case
    }

    return 0;
}
