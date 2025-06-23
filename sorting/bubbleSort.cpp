#include <iostream>
using namespace std;

void bubbleSort(int data[], int size) {
    for (int k = 0; k < size - 1; k++) { // Outer loop for passes
        for (int ptr = 0; ptr < size - k - 1; ptr++) { // Inner loop for swapping
            if (data[ptr] > data[ptr + 1]) {
                // Swap elements if they are in the wrong order
                int temp = data[ptr];
                data[ptr] = data[ptr + 1];
                data[ptr + 1] = temp;
            }
        }
    }
}

void printArray(int data[], int size) {
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

int main() {
    int data[20] = {10, 13, 7, 9, 2, 5, 8, 17, 1, 11, 6, 19, 12, 18, 4, 14, 3, 15, 20, 16};
    int size = sizeof(data) / sizeof(data[0]);
    
    cout << "Original array: ";
    printArray(data, size);
    
    bubbleSort(data, size);
    
    cout << "Sorted array: ";
    printArray(data, size);
    
    return 0;
}
