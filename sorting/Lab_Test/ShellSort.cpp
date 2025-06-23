#include<iostream>

using namespace std;

void shellSort (int A[], int n){
    int gap,i,j;
    for( gap = n/2;gap>0;gap/=2){
        for(i =gap;i<n;i+=1){
            int temp = A[i];
            for(j =i;((j>=gap) && (A[j-gap]>temp));j-=gap){
                
                A[j]= A[j-gap];
        
            }
            
            A[j] = temp;
            
        }
    }

}

int main(){
    int A []= {2,4,1,6,3,8,5,7};

    int n = 8;

    for(int i =0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;

    shellSort(A,n);

    cout<<"After sorting :";
    for(int i =0;i<n;i++){
        cout<<A[i]<<" ";
    }

}