#include <iostream>
#include <vector>
using namespace std;

void heapifyUp(vector<int> &heap, int index) {
    if (index == 0) return;

    int parent = (index - 1) / 2;

    if (heap[index] < heap[parent]) {
        swap(heap[index], heap[parent]);
        heapifyUp(heap, parent);
    }
}

void heapifyDown(vector<int> &heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap.size() && heap[left] < heap[smallest]) {
        smallest = left;
    }
    if (right < heap.size() && heap[right] < heap[smallest]) {
        smallest = right;
    }

    if (smallest != index) {
        swap(heap[index], heap[smallest]);
        heapifyDown(heap, smallest);
    }
}

void insert(vector<int> &heap, int value) {
    heap.push_back(value);
    heapifyUp(heap, heap.size() - 1);
}

void removeMin(vector<int> &heap) {
    if (heap.empty()) return;

    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(heap, 0);
}

int getMin(const vector<int> &heap) {
    if (heap.empty()) {
        cout << "Heap is empty." << endl;
        return -1;
    }
    return heap[0];
}

void printHeap(const vector<int> &heap) {
    for (int val : heap) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> heap;

    insert(heap, 10);
    insert(heap, 20);
    insert(heap, 15);
    insert(heap, 30);
    insert(heap, 40);

    cout << "Min Heap: ";
    printHeap(heap);

    cout << "Minimum: " << getMin(heap) << endl;

    removeMin(heap);
    cout << "Heap after removing min: ";
    printHeap(heap);

    return 0;
}
