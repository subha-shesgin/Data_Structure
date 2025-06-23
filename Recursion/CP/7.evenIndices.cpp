#include<iostream>
using namespace std;

void Even(int arr[], int index){
    if(index ==0){
        cout<<arr[index]<<" ";
        return;
    }
    else{
        if((index%2) ==0){
            cout<<arr[index]<<" ";
        }
    }
    Even( arr,index-1);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    Even(arr,n-1);
}