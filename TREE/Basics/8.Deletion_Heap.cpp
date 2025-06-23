#include <iostream>
#include <vector>
using namespace std;

// Function to heapify a subtree rooted at index 'i'
void heapify(vector<int>& heap, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] > heap[largest])
        largest = left;

    if (right < n && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapify(heap, n, largest);
    }
}

// Function to delete the root of the Max-Heap
void deleteRoot(vector<int>& heap) {
    int n = heap.size();
    if (n == 0) return;

    // Replace root with last element
    heap[0] = heap[n - 1];
    heap.pop_back(); // Decrease size

    // Heapify the new root
    heapify(heap, heap.size(), 0);
}

// Function to print elements of the heap
void printHeap(const vector<int>& heap) {
    for (int x : heap) {
        cout << x << " ";
    }
    cout << endl;
}

// Main function
int main() {
    vector<int> heap = {10, 5, 3, 2, 4};

    // Print original heap
    cout << "Original Heap: ";
    printHeap(heap);

    // Delete root
    deleteRoot(heap);

    // Print updated heap
    cout << "After deleting root: ";
    printHeap(heap);

    return 0;
}