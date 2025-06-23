#include <iostream>
using namespace std;

void insertionSort(int data[], int size) {
    for (int i = 1; i < size; i++) {
        int value = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > value) {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = value;
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
    
    insertionSort(data, size);
    
    cout << "Sorted array (Ascending Order): ";
    printArray(data, size);
    
    return 0;
}
