#include <iostream>
using namespace std;

void selectionSortAscending(int data[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (data[j] < data[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = data[i];
            data[i] = data[minIndex];
            data[minIndex] = temp;
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
    
    selectionSortAscending(data, size);
    
    cout << "Sorted array (Ascending Order): ";
    printArray(data, size);
    
    return 0;
}