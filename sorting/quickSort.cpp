#include <iostream>
using namespace std;

void quickSort(int array[], int start, int end);
int partition(int array[], int start, int end);

void quickSort(int array[], int start, int end) {
    if (end <= start) return; // base case

    int pivot = partition(array, start, end);
    quickSort(array, start, pivot - 1);
    quickSort(array, pivot + 1, end);
}

int partition(int array[], int start, int end) {
    int pivot = array[end];
    int i = start - 1;

    for (int j = start; j < end; j++) {
        if (array[j] < pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }
    i++;
    swap(array[i], array[end]);
    return i;
}

void printArray(int data[], int size) {
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

int main() {
    int data[] = {8, 2, 5, 3, 9, 4, 7, 6, 1};
    int size = sizeof(data) / sizeof(data[0]);
    
    cout << "Original array: ";
    printArray(data, size);
    
    quickSort(data, 0, size - 1);
    
    cout << "Sorted array (Ascending Order): ";
    printArray(data, size);
    
    return 0;
}
