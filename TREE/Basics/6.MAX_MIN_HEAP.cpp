#include <iostream>
#include <vector>
using namespace std;

////////// MAX HEAP///////

void heapifyUpMax(vector<int>& heap, int index) {
    while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
        swap(heap[(index - 1) / 2], heap[index]);
        index = (index - 1) / 2;
    }
}

void heapifyDownMax(vector<int>& heap, int index) {
    int size = heap.size();
    while (true) {
        int left = 2 * index + 1, right = 2 * index + 2, largest = index;

        if (left < size && heap[left] > heap[largest])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest == index)
            break;

        swap(heap[index], heap[largest]);
        index = largest;
    }
}

void insertMaxHeap(vector<int>& heap, int value) {
    heap.push_back(value);
    heapifyUpMax(heap, heap.size() - 1);
}

int extractMax(vector<int>& heap) {
    if (heap.empty())
        return -1;

    int maxVal = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDownMax(heap, 0);
    return maxVal;
}

///////////// MIN HEAP/////////

void heapifyUpMin(vector<int>& heap, int index) {
    while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
        swap(heap[(index - 1) / 2], heap[index]);
        index = (index - 1) / 2;
    }
}

void heapifyDownMin(vector<int>& heap, int index) {
    int size = heap.size();
    while (true) {
        int left = 2 * index + 1, right = 2 * index + 2, smallest = index;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == index)
            break;

        swap(heap[index], heap[smallest]);
        index = smallest;
    }
}

void insertMinHeap(vector<int>& heap, int value) {
    heap.push_back(value);
    heapifyUpMin(heap, heap.size() - 1);
}

int extractMin(vector<int>& heap) {
    if (heap.empty())
        return -1;

    int minVal = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDownMin(heap, 0);
    return minVal;
}


int main() {
    vector<int> maxHeap;
    insertMaxHeap(maxHeap, 10);
    insertMaxHeap(maxHeap, 5);
    insertMaxHeap(maxHeap, 20);
    insertMaxHeap(maxHeap, 3);

    cout << "Max Heap: ";
    for (int x : maxHeap) cout << x << " ";
    cout << "\nExtracted Max: " << extractMax(maxHeap) << endl;

    cout << "Max Heap after extract: ";
    for (int x : maxHeap) cout << x << " ";
    cout << endl;

    vector<int> minHeap;
    insertMinHeap(minHeap, 10);
    insertMinHeap(minHeap, 5);
    insertMinHeap(minHeap, 20);
    insertMinHeap(minHeap, 3);

    cout << "\nMin Heap: ";
    for (int x : minHeap) cout << x << " ";
    cout << "\nExtracted Min: " << extractMin(minHeap) << endl;

    cout << "Min Heap after extract: ";
    for (int x : minHeap) cout << x << " ";
    cout << endl;

    return 0;
}