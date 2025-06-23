#include <iostream>
using namespace std;

void checkPalindrome(int arr[], int start, int end) {
    // Base case: If pointers cross, it's a palindrome
    if (start >= end) {
        cout << "YES" << endl;
        return; // Stop further execution
    }

    // If first and last elements don't match, it's not a palindrome
    if (arr[start] != arr[end]) {
        cout << "NO" << endl;
        return; // Stop further execution
    }

    // Recursive call for the inner subarray
    checkPalindrome(arr, start + 1, end - 1);
}

int main() {
    int n;
    cin >> n;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    checkPalindrome(arr, 0, n - 1); // Fix: Pass `n-1` as the last index

    return 0;
}
