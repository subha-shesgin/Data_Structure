#include <iostream>
#include <limits> // For INT_MAX
using namespace std;

// Insertion sort function to sort the array in non-decreasing order.
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

int main(){
    int t;
    cout << "Enter test cases :" << endl;
    cin >> t;

    for (int test = 0; test < t; test++) {
        int n;
        cout << "Enter number of athletes :" << endl;
        cin >> n;
        
        // Check for valid input.
        if (n <= 0) {
            cout << "Number of athletes must be positive." << endl;
            continue;
        }
        
        // Dynamically allocate the array.
        int* s = new int[n];
        
        cout << "Enter strength values:" << endl;
        for (int j = 0; j < n; j++) {
            cin >> s[j];
        }
        
        // Optional: Print the unsorted array.
        cout << "Unsorted strengths: ";
        for (int j = 0; j < n; j++) {
            cout << s[j] << " ";
        }
        cout << endl;
        
        // Sort the array.
        insertionSort(s, n);
        
        // Optional: Print the sorted array.
        cout << "Sorted strengths: ";
        for (int j = 0; j < n; j++) {
            cout << s[j] << " ";
        }
        cout << endl;
        
        // If there is only one athlete, no difference can be computed.
        if (n < 2) {
            cout << "Not enough athletes to compare differences." << endl;
        } else {
            // Initialize the minimum difference with the difference between the first two.
            int minDiff = s[1] - s[0];
            // Loop from 0 to n-2 to compare consecutive athletes.
            for (int j = 0; j < n - 1; j++) {
                int diff = s[j + 1] - s[j];
                if (diff < minDiff) {
                    minDiff = diff;
                }
            }
            cout << "Minimum difference: " << minDiff << endl;
        }
        
        // Free the allocated memory.
        delete[] s;
    }
    return 0;
}
