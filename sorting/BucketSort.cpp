#include <iostream>
#include <vector>
using namespace std;

// Insertion Sort for sorting a bucket (vector) in ascending order.
void insertionSort(vector<float>& bucket) {
    for (int i = 1; i < bucket.size(); i++) {
        float key = bucket[i];
        int j = i - 1;
        // Move elements of bucket[0..i-1] that are greater than key one position ahead.
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Bucket Sort function
void bucketSort(vector<float>& A) {
    int n = A.size();
    
    // 1. Create n empty buckets.
    vector<vector<float>> B(n);
    
    // 2. Insert each element A[i] into the appropriate bucket.
    //    Bucket index is computed as: index = floor(n * A[i])
    //    (Since A[i] is in [0,1), n * A[i] will be in [0, n))
    for (int i = 0; i < n; i++) {
        int index = n * A[i];  // Implicit floor since we're converting to int.
        B[index].push_back(A[i]);
    }
    
    // 3. Sort each bucket using insertion sort.
    for (int i = 0; i < n; i++) {
        insertionSort(B[i]);
    }
    
    // 4. Concatenate the sorted buckets back into the array A.
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < B[i].size(); j++) {
            A[index++] = B[i][j];
        }
    }
}

int main() {
    // Example input: Array of floats in the range [0, 1).
    vector<float> A = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    
    cout << "Original array: ";
    for (float num : A) {
        cout << num << " ";
    }
    cout << endl;
    
    // Sort the array using bucket sort.
    bucketSort(A);
    
    cout << "Sorted array: ";
    for (float num : A) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
