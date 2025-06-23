#include <iostream>
using namespace std;

int josephus(int n, int k) {
    // Base Case: Only one person remains
    if (n == 1)
        return 0; // 0-based index

    // Recursive case: Reduce the problem and adjust the position
    return (josephus(n - 1, k) + k) % n;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    // Convert 0-based result to 1-based index
    int result = josephus(n, k) + 1;
    
    cout << result << endl;
    
    return 0;
}
