#include <iostream>
#include <vector>
using namespace std;

// Insertion sort function to sort an array in non-decreasing order.
void insertionSort(int data[], int size) {
    for (int i = 1; i < size; i++) {
        int value = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > value) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = value;
    }
}

int main(){
    int t;
    cin >> t;
    cout << "Test cases: " << t << endl;

    for (int test = 0; test < t; test++) {
        int a,b,c;
        cin >> a>>b>>c;
        cout << "Numbers are : " << a<<" "<<b<<" "<<c<<" "<< endl;

        int A[3] ={a,b,c};

        insertionSort(A, 3);

        cout<<A[1]<<endl;
    }
}