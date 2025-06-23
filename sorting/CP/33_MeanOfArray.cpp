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

    // Calculate the number of elements to remove (5% of the array size)
    int size = (5 / 100.0) * arr.size();  // Ensuring proper floating point division

    // Remove the first 5% elements
    arr.erase(arr.begin(), arr.begin() + size);

    // Remove the last 5% elements
    arr.resize(arr.size() - size);  // Resize to remove the last 5% elements

    // Output the remaining elements
    cout << "Remaining elements: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    int sum =0;
    for(int i =0;i<arr.size();i++){
       
       sum = sum+ arr[i];
    }
    double mean = sum / arr.size();

    cout<<mean<<endl;

    return 0;
}
