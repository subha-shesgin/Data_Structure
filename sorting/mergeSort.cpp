#include <iostream>
using namespace std;

void merge(int data[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    int temp[high + 1];
    
    while (i <= mid && j <= high) {
        if (data[i] <= data[j]) {
            temp[k] = data[i];
            k++;
            i++;
        } else {
            temp[k] = data[j];
            k++;
            j++;

        }
    }
    
    while (i <= mid) {
        temp[k] = data[i];
        k++;
        i++;
    }
    while (j <= high) {
        temp[k] = data[j];
        k++;
        j++;
    }
    
    for (int x = low; x <= high; x++) {
        data[x] = temp[x];
    }
}

void mergeSort(int data[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(data, low, mid);
        mergeSort(data, mid + 1, high);
        merge(data, low, mid, high);
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
    
    mergeSort(data, 0, size - 1);
    
    cout << "Sorted array (Ascending Order): ";
    printArray(data, size);
    
    return 0;
}
