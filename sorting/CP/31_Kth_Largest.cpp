#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, k;
    cout << "Enter the number of elements: ";
    cin >> n;
    int A[n];

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << "Enter k: ";
    cin >> k;

    // Insert elements into a set (automatically sorts in ascending order & removes duplicates)
    set<int> sets(A, A + n);

    // Check if k is within valid range
    if (k > sets.size() || k <= 0) {
        cout << "Invalid value of k!" << endl;
        return 1;
    }

    // Find the k-th largest element using reverse iterator
    auto it = sets.rbegin(); // Reverse iterator points to largest element
    advance(it, k - 1); // Move k-1 steps forward to get k-th largest

    cout << "The " << k << "th largest element is: " << *it << endl;

    return 0;
}
