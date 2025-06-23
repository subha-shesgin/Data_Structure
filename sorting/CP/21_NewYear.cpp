#include<iostream>
using namespace std;

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

int calculateMinDistance(int d[], int size) {
    insertionSort(d, size);
    return (d[2] - d[1]) + (d[1] - d[0]);
}

int main() {
    int data[3];

    for (int i = 0; i < 3; i++) {
        cin >> data[i];
    }

    cout << calculateMinDistance(data, 3) << endl;
}
