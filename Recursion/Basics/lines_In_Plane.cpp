#include <iostream>
using namespace std;

// Recursive function to calculate maximum number of regions with n lines
int maxRegions(int n) {
    if (n == 0) return 1; // Base case: No lines, one region5
    return maxRegions(n - 1) + n;
}

int main() {
    int n;
    cout << "Enter the number of lines: ";
    cin >> n;
    
    cout << "Maximum number of regions: " << maxRegions(n) << endl;
    return 0;
}
