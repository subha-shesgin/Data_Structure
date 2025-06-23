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
    int n;
    cout<<"Enter number of sticks"<<endl;
    cin>>n;
    cout<<n<<endl;
    
    int len[n];
    cout<<"Enter length of the sticks :"<<endl;
    for(int i =0;i<n;i++){
        cin>>len[i];
    }

    for(int i =0;i<n;i++){
        cout<<len[i]<<" ";
    }
    cout<<endl;
    insertionSort(len,n);

    int mid;

    mid = n/2;
    int x =0;
    int y=0;
    for(int j=0;j<mid;j++){
        y = y+len[j];
    }

    for(int j=mid;j<n;j++){
        x = x+len[j];
    }

    cout<<x<<","<<y<<endl;

    int square = (x*x )+ (y*y);

    cout<<square<<endl;

}