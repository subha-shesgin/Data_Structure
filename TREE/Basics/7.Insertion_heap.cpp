#include <iostream>
#include <vector>
using namespace std;

// Function to heapify a node using bottom-up approach
void heapify(vector<int>& heap, int index) {
    int parent = (index - 1) / 2;

    if (parent >= 0 && heap[index] > heap[parent]) {
        swap(heap[index], heap[parent]);
        heapify(heap, parent); // Recursively heapify up the parent
    }
}

// Function to insert a new element into the heap
void insertNode(vector<int>& heap, int key) {
    heap.push_back(key); // Insert at the end
    heapify(heap, heap.size() - 1); // Heapify from new element
}

// Function to print heap elements
void printHeap(const vector<int>& heap) {
    for (int x : heap)
        cout << x << " ";
    cout << endl;
}

// Driver code
int main() {
    vector<int> heap = {10, 5, 3, 2, 4};

    int key = 15;
    insertNode(heap, key);

    cout << "Heap after insertion: ";
    printHeap(heap);

    return 0;
}