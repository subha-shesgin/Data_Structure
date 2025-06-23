#include<iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &data) {
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
int main(){
    vector <int> heights;

    cout<<"Enter the values: (enter q to quit)"<<endl;

    while(1){
        
        string input;
        cin>>input;

        if(input == "q"){
            break;
        }
        else{
            int n = stoi(input);
            heights.push_back(n);
        }
    }
    vector<int> expected;

    expected = heights;

    insertionSort(expected);


    int count=0;

    for(int i =0;i<heights.size();i++){
        if(heights[i]!= expected[i]){
            count++;
        }
    }
    cout<<count<<endl;
}