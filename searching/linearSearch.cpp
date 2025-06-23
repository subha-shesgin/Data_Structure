#include <iostream>
using namespace std;

// Function to perform linear search
int linearSearch(int array[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return i; // Return index if value is found
        }
    }
    return -1; // Return -1 if value is not found
}

int main() {
    // Array to search in
    int array[] = {9, 1, 8, 2, 7, 3, 6, 4, 5};
    int size = sizeof(array) / sizeof(array[0]); // Calculate size of the array
    int value = 6; // Value to search for

    // Perform linear search
    int index = linearSearch(array, size, value);
    
    // Output result
    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found" << endl;
    }
    
    return 0;
}
