#include <map>
#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int>& data) {
    int size = data.size();
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

int main() {
    vector<int> arr;
    cout << "Enter the values for arr: (enter q to quit)" << endl;

    while (true) {
        string input;
        cin >> input;

        if (input == "q") {
            break;
        } else {
            int n = stoi(input);
            arr.push_back(n);
        }
    }

    insertionSort(arr);

    // Handle the case where there are fewer than 2 elements
    if (arr.size() < 2) {
        cout << "Not enough elements for difference calculation." << endl;
        return 0;
    }

    int difference = arr[1] - arr[0];

    // Loop starts at index 1 and goes to the second last element
    for (int i = 1; i < arr.size() - 1; i++) {
        int dif = arr[i + 1] - arr[i];
        if (difference > dif) {
            difference = dif;
        }
    }

    map<int, int> result;
    for (int i = 0; i < arr.size() - 1; i++) {
        if ((arr[i + 1] - arr[i]) == difference) {
            result.insert({arr[i], arr[i + 1]});
        }
    }

    // Output the result
    for (const auto& pair : result) {
        cout << pair.first << "," << pair.second << " ";
    }
    cout << endl;

    return 0;
}