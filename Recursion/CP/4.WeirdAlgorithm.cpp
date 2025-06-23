#include <iostream>
using namespace std;

void weird_algo(long long n) {
    cout << n << " "; // Print the current number with a space

    if (n == 1) return; // Base case: stop when n becomes 1

    if (n % 2 == 0) {
        weird_algo(n / 2); // Recursive call for even numbers
    } else {
        weird_algo(n * 3 + 1); // Recursive call for odd numbers
    }
}

int main() {
    long long n;
    cin >> n;
    weird_algo(n);
    cout << endl; // Newline for proper formatting
    return 0;
}
