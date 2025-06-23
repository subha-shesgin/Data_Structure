#include <iostream>
#include <vector>
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
    cout << "Test cases: " << t << endl;

    for (int test = 0; test < t; test++) {
        int n;
        cin >> n;
        cout << "Number of athletes (n): " << n << endl;

        // Create two vectors of size n.
        vector<int> A(n), B(n);

        // Read elements into vector A.
        cout << "Enter elements for vector A:" << endl;
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }

        // Display vector A.
        cout << "Vector A: ";
        for (int i = 0; i < n; i++) {
            cout << A[i] << " ";
        }
        cout << endl;

        // Read elements into vector B.
        cout << "Enter elements for vector B:" << endl;
        for (int i = 0; i < n; i++) {
            cin >> B[i];
        }

        // Display vector B.
        cout << "Vector B: ";
        for (int i = 0; i < n; i++) {
            cout << B[i] << " ";
        }
        cout << endl;

        int count = 0;
        
        // Check if the two vectors are not equal.
        while (A != B) {
            // Sort both vectors using insertion sort.
            insertionSort(&A[0], n);
            insertionSort(&B[0], n);

            // After sorting, if they are still not equal,
            // compare element by element.
            if (A != B) {
                for (int j = 0; j < n; j++) {
                    if (A[j] != B[j]) {
                        // Toggle the element in A (for binary values, 0 becomes 1 and 1 becomes 0)
                        A[j] = 1 - A[j];
                        count++;
                    }
                }
            }
        } 
        
        cout << count << endl;
    }

    return 0;
}
