// #include <iostream>
// #include <set>
// using namespace std;

//---------insertionSort for SET -------------
// void insertionSortSet(set<int>& data, const vector<int>& values) {
//     for (int val : values) {
//         data.insert(val);  // Set automatically sorts elements
//     }
// }

// int main() {
//     vector<int> values = {5, 3, 8, 1, 4};
//     set<int> sortedSet;
    
//     insertionSortSet(sortedSet, values);

//     for (int num : sortedSet) {
//         cout << num << " ";
//     }
//     cout << endl;

//     return 0;
// }

//---------------insertionSort for MAP--------------------------

// void insertionSortMap(vector<pair<int, int>>& data) {
//     int size = data.size();
//     for (int i = 1; i < size; i++) {
//         pair<int, int> value = data[i];
//         int j = i - 1;
//         while (j >= 0 && data[j].second > value.second) {
//             data[j + 1] = data[j];
//             j--;
//         }
//         data[j + 1] = value;
//     }
// }

// int main() {
//     map<int, int> myMap = {{1, 30}, {2, 10}, {3, 20}, {4, 40}};
//     vector<pair<int, int>> vec(myMap.begin(), myMap.end());

//     insertionSortMap(vec);

//     for (const auto& p : vec) {
//         cout << p.first << " -> " << p.second << endl;
//     }

//     return 0;
// }


//-----------------insertionSort for ARRAY-----------------------

// void insertionSortArray(int arr[], int size) {
//     for (int i = 1; i < size; i++) {
//         int value = arr[i];
//         int j = i - 1;
//         while (j >= 0 && arr[j] > value) {
//             arr[j + 1] = arr[j];
//             j--;
//         }
//         arr[j + 1] = value;
//     }
// }

// int main() {
//     int arr[] = {5, 3, 8, 1, 4};
//     int size = sizeof(arr) / sizeof(arr[0]);

//     insertionSortArray(arr, size);

//     for (int i = 0; i < size; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }



