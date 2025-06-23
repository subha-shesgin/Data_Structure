#include <iostream>
using namespace std;

int binarySearch(int data[], int size, int item) {
    int LB = 0;
    int UB = size - 1;
    int MID;

    while (LB <= UB) {
        MID = (LB + UB) / 2;
        
        if (data[MID] == item)
            return MID; // Item found, return index
        else if (item < data[MID])
            UB = MID - 1; // Search in the left half
        else
            LB = MID + 1; // Search in the right half
    }
    
    return -1; // Item not found
}

int main() {
    int data[] = {2, 5, 7, 9, 11, 13, 15};
    int size = sizeof(data) / sizeof(data[0]);
    int item = 11; // Item to search for
    
    int result = binarySearch(data, size, item);
    
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Item is not in the list." << endl;
    
    return 0;
}
