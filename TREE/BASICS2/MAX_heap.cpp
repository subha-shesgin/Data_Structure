#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 1e5;
vector<int> heap; // Global heap array

void heapifyUp(int index) {
    if (index == 0) return;
    int parent = (index - 1) / 2;
    if (heap[index] > heap[parent]) {
        swap(heap[index], heap[parent]);
        heapifyUp(parent);
    }
}

void heapifyDown(int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < heap.size() && heap[left] > heap[largest]) {
        largest = left;
    }
    if (right < heap.size() && heap[right] > heap[largest]) {
        largest = right;
    }

    if (largest != index) {
        swap(heap[index], heap[largest]);
        heapifyDown(largest);
    }
}

void insert(int value) {
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

void removeMax() {
    if (heap.empty()) {
        cout << "Heap is empty.\n";
        return;
    }
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
}

int getMax() {
    if (heap.empty()) {
        cout << "Heap is empty.\n";
        return -1;
    }
    return heap[0];
}

void printHeap() {
    for (int val : heap) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    insert(10);
    insert(20);
    insert(15);
    insert(30);
    insert(40);

    cout << "Max Heap: ";
    printHeap();
