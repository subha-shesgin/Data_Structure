
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
    int t;
    cout<<"enter test cases"<<endl;
    cin>>t;
    cout<<t<<endl;

    for(int i =0;i<t;i++){
        int length;
        cout<<"Enter length of array"<<endl;
        cin>>length;
        cout<<length<<endl;

        int arr[length];
        int dif[length];
        cout<<"enter strenghts of participants"<<endl;
        for(int j =0;j<length;j++){
            cin>>arr[j];
        }
         for(int j =0;j<length;j++){
            cout<<arr[j]<<" ";
        }
        cout << endl;
        insertionSort(arr,length);
        int max = arr[length-1];

        for(int j =0;j<length;j++){
            int difference;

            if(j == length-1){
                difference = arr[j] - arr[j-1];
                dif[j] = difference;
            }
            else{
                difference = arr[j] - max;
                dif[j] = difference;
            }
        }
        for(int j =0;j<length;j++){
            cout<<dif[j]<<" ";
        }
        cout << endl;
    }
    
}