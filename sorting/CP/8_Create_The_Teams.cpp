#include <iostream>
using namespace std;

// Insertion sort function to sort the array in non-decreasing order.
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
    int t;
    cout << "Enter test cases:" << endl;
    cin >> t;

    // Process each test case.
    for (int tc = 0; tc < t; tc++){
        int n, x;
        cout << "Enter number of programmers and restriction of team skill:" << endl;
        cin >> n >> x;
        cout << n << " " << x << endl;

        int arr[n];

        cout << "Enter strengths of participants:" << endl;
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        
        // Optionally, print the unsorted array.
        cout << "Unsorted strengths: ";
        for (int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;

        // Sort the candidate strengths using insertion sort.
        insertionSort(arr, n);

        cout << "Sorted strengths: ";
        for (int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;

        // Greedy team formation:
        // We iterate from the strongest candidate (end of array) to the weakest.
        // Maintain a count of candidates in the current team.
        // If count * current_strength >= x, then a team is formed.
        int teams = 0;
        int count = 0;
        for (int i = n - 1; i >= 0; i--){
            count++;  // include the current candidate in the current team
            if (count * arr[i] >= x) {
                teams++;    // a valid team is formed
                count = 0;  // reset for the next team
            }
        }

        cout << "Maximum number of teams: " << teams << endl;
    }
    
    return 0;
}
