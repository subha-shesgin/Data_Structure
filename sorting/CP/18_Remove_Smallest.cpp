#include<iostream>

using namespace std;

// Insertion sort function to sort an array in non-decreasing order.
void insertionSort(int data[], int size) {
    for (int i = 1; i < size; i++) {
        int value = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > value) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = value;
    }
}

int main() {
    int t;
    cin >> t;

    for (int test = 0; test < t; test++) {
        int n;
        cin >> n;

        int A[n]; // Declare an array of size n
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }

        // Sort the array using insertion sort
        insertionSort(A, n);

        // Loop through the array and check conditions
        bool found = false; // Flag to check if only one element is left
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // If the difference between any two elements is <= 1
                if (A[j] - A[i] <= 1) {
                    // Remove the smaller one (either A[i] or A[j])
                    if (A[i] < A[j]) {
                        // Remove A[i] by shifting elements left
                        for (int k = i; k < n - 1; k++) {
                            A[k] = A[k + 1];
                        }
                        n--; // Decrease the size of the array
                        j--; // Adjust index since the array is shifted
                    } else {
                        // Remove A[j] by shifting elements left
                        for (int k = j; k < n - 1; k++) {
                            A[k] = A[k + 1];
                        }
                        n--; // Decrease the size of the array
                        j--; // Adjust index since the array is shifted
                    }
                }
            }
            // If the array is reduced to one element, print "YES"
            if (n == 1) {
                cout << "YES" << endl;
                found = true;
                break;
            }
        }

        // If the loop completes and array is not reduced to one element
        if (!found) {
            cout << "NO" << endl;
        }
    }

    return 0;
}
