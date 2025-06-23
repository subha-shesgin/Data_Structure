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
    int t;
    cout<<"Enter test cases:"<<endl;
    cin>>t;
    cout<<t<<endl;

    int n;

    for(int i=0;i<t;i++){
        cout<<"Enter numvber of boxes (n) :"<<endl;
        cin>>n;
        cout<<n<<endl;

        int candy =0;
        int box[n];

        cout<<"Enter candies in each box :"<<endl;
        for(int k=0;k<n;k++){
            cin>>box[k];
        }

        for(int k=0;k<n;k++){
            cout<<box[k]<<" ";
        }
        cout<<endl;

        insertionSort(box,n);
        for(int j=n-1;j>0;j--){
            

            candy = candy + (box[j] - box[0]);


        }
        cout<<candy<<endl;
    }
}