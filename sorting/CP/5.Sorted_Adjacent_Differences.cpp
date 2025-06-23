#include <iostream>

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

int main(){
    int test;
    cout << "Enter number of test cases" << endl;
    cin >> test;
    
    // Process each test case
    for (int t = 0; t < test; t++){
        int n;
        cout << "Enter size of array" << endl;
        cin >> n ;
        
        int array[n];
        cout << "Enter the array:" << endl;
        for (int j = 0; j < n; j++){
            cin >> array[j];
        }
        
        // Optional: Debug print the original array
        
        for (int j = 0; j < n; j++){
            cout << array[j] << " ";
        }
        cout << endl;
        
        // Sort the array using insertion sort
        insertionSort(array, n);
        
        cout << "After sorting:" << endl;
        for (int j = 0; j < n; j++){
            cout << array[j] << " ";
        }
        cout << endl;

        int result[n+1] ={0};

        if(n%2 == 0){
            int k = n-1;
            for(int i =0;i<n/2;i++){
                result[k--] = array[n-1-i];
                result[k--] =  array[i];
            }
        }
        else{
            int k = n-1;
            result[0] = array[n/2];
            for(int i =0;i<n/2;i++){
                result[k--] = array[n-1-i];
                result[k--] =  array[i];
            }
        }
        for(int i = 0;i<n;i++){
            cout<<result[i]<<" ";
        }
        cout<<endl;
    }
}