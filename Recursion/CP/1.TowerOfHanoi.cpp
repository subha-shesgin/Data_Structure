#include <iostream>
#include <cmath> // Include for pow()
using namespace std;

// Function to solve Tower of Hanoi
void towerOfHanoi(int n, char left, char middle, char right) {
    if (n == 1) {
        cout << left << " to " << right << endl;
        return;
    }
    
    // Step 1: Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, left, right, middle);
    
    // Step 2: Move nth disk from source to destination
    cout << left << " to " << right << endl;
    
    // Step 3: Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, middle, left, right);
}

// Driver Code
int main() {
    int n; // Number of disks
    cout << "Enter number of disks: ";
    cin >> n;

    int moves = (int)pow(2, n) - 1; // Typecast to int
    cout << "Total moves required: " << moves << endl;
    
    towerOfHanoi(n, '1', '2', '3'); // Using 'A' = source, 'B' = auxiliary, 'C' = destination
    
    return 0;
}
