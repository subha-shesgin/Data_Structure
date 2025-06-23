#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of mountains: ";
    cin >> n;

    vector<int> heights(n);
    queue<int> result;

    // Input mountain heights
    for (int i = 0; i < n; i++) {
        cin >> heights[i];  // Correct way to store input in vector
    }

    // Find next greater element for each mountain
    for (int i = 0; i < n; i++) {
        int nextGreater = -1;  // Default to -1 if no greater element is found
        for (int j = i + 1; j < n; j++) {
            if (heights[j] > heights[i]) {
                nextGreater = heights[j];
                break;  // Stop searching once we find the next greater element
            }
        }
        result.push(nextGreater);
    }

    // Print results
    cout << "Next greater heights for each mountain:" << endl;
    while (!result.empty()) {
        cout << result.front() << " ";
        result.pop();
    }
    cout << endl;

    return 0;
}
