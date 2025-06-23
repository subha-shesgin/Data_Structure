#include <iostream>

using namespace std;

// Insertion sort function to sort the array in non-decreasing order.
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

int main(){
    int n,m;
    cout<<"Enter value of n :"<<endl;
    cin>>n;
    int A[n];
    cout<<"Enter the array A :"<<endl;
    for(int i =0;i<n;i++){
        cin>>A[i];
    }
       for(int i =0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;

      cout<<"Enter value of m :"<<endl;
    cin>>m;
    int B[m];
    cout<<"Enter the array B :"<<endl;
    for(int i =0;i<m;i++){
        cin>>B[i];
    }
       for(int i =0;i<m;i++){
        cout<<B[i]<<" ";
    }
    cout<<endl;

    insertionSort(A,n);
    insertionSort(B,m);
    
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            int sum =0;

            sum = A[i]+B[j];
             bool foundInA = false, foundInB = false;

            // Check in A
            for (int k = 0; k < n; k++) {
                if (A[k] == sum) {
                    foundInA = true;
                    break;
                }
            }

            // Check in B
            for (int k = 0; k < m; k++) {
                if (B[k] == sum) {
                    foundInB = true;
                    break;
                }
            }

            // If sum is not in A or B, print the pair
            if (!foundInA && !foundInB) {
                cout << A[i] << " " << B[j] << endl;
                return 1;
            }
        
        }
    }

}