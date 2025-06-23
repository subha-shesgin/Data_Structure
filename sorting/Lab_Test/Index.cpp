#include<iostream>
#include <vector>

using namespace std;
void insertionSort(vector<int>& data) {
    int size = data.size();
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

void Index(vector<int>& data,int target){
    insertionSort(data);
    for(int i =0;i<4;i++){
        if(data[i] == target){
            cout<<i<<" ";
            break;
        }
        else{
            data.push_back(target);
            insertionSort(data);
             if(data[i] == target){
            cout<<i<<" ";
            break;
        }
            
        }
    }

}
int main(){
    vector<int> A;
   for(int i =0;i<4;i++){
    int n;
    cin>>n;
    A.push_back(n);
   }
   int target;
   cin>>target;
   Index(A,target);


}