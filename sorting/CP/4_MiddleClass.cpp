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

int main(){
    int test;
    cout << "Enter number of test cases" << endl;
    cin >> test;
    
    // Process each test case
    for (int t = 0; t < test; t++){
        int n, x;
        cout << "Enter number of people and amount of money" << endl;
        cin >> n >> x;
        
        int array[n];
        cout << "Enter the money:" << endl;
        for (int j = 0; j < n; j++){
            cin >> array[j];
        }
        
        // Optional: Debug print the original array
        cout << "People and amount of money = " << n << " " << x << endl;
        for (int j = 0; j < n; j++){
            cout << array[j] << " ";
        }
        cout << endl;
        
        // Sort the array using insertion sort
        insertionSort(array, n);
        
        cout << "After sorting:" << endl;
        for (int j = 0; j < n; j++){
            cout << array[j] << " ";
        }
        cout << endl;
        
        // Calculate the maximum number of wealthy people.
        // The idea: starting from the richest, add one person at a time.
        // Let 'sum' be the total savings of the selected group and 'count'
        // be the number of people in the group. If (sum/count) >= x, then
        // this group can be made wealthy by redistribution.
        int wealthy = 0;
        double sum = 0;
        int count = 0;
        for (int j = n - 1; j >= 0; j--){
            sum += array[j];
            count++;
            if ((sum / count) >= x) {
                wealthy = count;  // update wealthy to current group size
            }
            else {
                break;
            }
        }
        cout << "Maximum number of wealthy people: " << wealthy << endl;
    }
    
    return 0;
}
