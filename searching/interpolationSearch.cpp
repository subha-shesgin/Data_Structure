#include <iostream>
using namespace std;

int interpolationSearch(int array[], int size, int value) {
    int low = 0;
    int high = size - 1;
    
    while (low <= high && value >= array[low] && value <= array[high]) {
        int probe = low + (high - low) * (value - array[low]) / (array[high] - array[low]);
        
        if (array[probe] == value) {
            return probe; // Element found
        }
        else if (array[probe] < value) {
            low = probe + 1; // Search right subarray
        }
        else {
            high = probe - 1; // Search left subarray
        }
    }
    
    return -1; // Element not found
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(array) / sizeof(array[0]);
    int value = 8;
    
    int index = interpolationSearch(array, size, value);
    
    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found" << endl;
    }
    
    return 0;
}
