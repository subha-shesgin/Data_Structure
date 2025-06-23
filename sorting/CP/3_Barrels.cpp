#include <iostream>
#include <vector>  // For dynamic array (vector)

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

int main(){
    int test;
    
    cout << "Enter number of tests: " << endl;
    cin >> test;
    cout << test << endl;

    for(int i = 1; i <= test; i++) {
        int barrels, pourings;
        
        // Input the number of barrels and pourings
        cout << "Enter number of barrels and number of pourings: " << endl;
        cin >> barrels >> pourings;

        // Dynamically create a vector (or array) to store the amount of water in each barrel
        vector<int> amount(barrels);

        cout << "Enter amount of water in each barrel: " << endl;
        for (int j = 0; j < barrels; j++) {
            cin >> amount[j];
        }

        cout << "Barrels: " << barrels << " Pourings: " << pourings << endl;
        cout << "Initial water amounts in barrels: ";
        for (int k = 0; k < barrels; k++) {
            cout << amount[k] << " ";
        }
        cout << endl;

        for(int i =1;i<=pourings;i++){
            amount[barrels-1] = amount[barrels-1] + amount[i];
            amount[i] = amount[i] - amount[i];
        }

        // Sort the array
        insertionSort(amount.data(), barrels); // Use .data() to get a pointer to the underlying array

        // Output sorted amounts
        cout << "Sorted water amounts in barrels: ";
        for (int k = 0; k < barrels; k++) {
            cout << amount[k] << " ";
        }
        cout << endl;

        int difference = amount[barrels-1] - amount[0];

        cout<<difference<<endl;
    }

    return 0;
}
