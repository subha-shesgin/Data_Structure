#include <iostream>
using namespace std;

void countingSort(int A[], int n, int k) {
    // k is the maximum possible value in the array A.
    // Create a count array 'c' of size k+1 and initialize all elements to 0.
    int* c = new int[k + 1](); // The () initializes all elements to 0.
    
    // Step 1: Store the count of each element from A[] in c[].
    for (int j = 0; j < n; j++) {
        c[A[j]] = c[A[j]] + 1;
    }
    
    // Step 2: Change c[] so that it contains the actual positions of the elements in the output array.
    for (int i = 1; i <= k; i++) {
        c[i] = c[i] + c[i - 1];
    }
    
    // Step 3: Build the output array B using the count array c.
    int* B = new int[n];
    // Iterate from the last element to the first to ensure a stable sort.
    for (int j = n - 1; j >= 0; j--) {
        // Place A[j] at its correct sorted position in B.
        B[c[A[j]] - 1] = A[j];
        // Decrement the count for A[j].
        c[A[j]] = c[A[j]] - 1;
    }
    
    // Print the sorted array B.
    for (int i = 0; i < n; i++) {
        cout << B[i] << " ";
    }
    cout << endl;
    
    // Clean up dynamically allocated memory.
    delete[] c;
    delete[] B;
}

int main() {
    // Example array to sort.
    // Make sure that all values are in the range 0..k, where k is known.
    int A[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(A) / sizeof(A[0]); // Number of elements in A.
    int k = 8; // Maximum element value in A.
    
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    
    cout << "Sorted array: ";
    countingSort(A, n, k);
    
    return 0;
}
