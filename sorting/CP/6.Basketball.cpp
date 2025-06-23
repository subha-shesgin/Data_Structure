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
    int players , enemyPower;

    cout<<"Enter number of players and power of the enemy:"<<endl;
    cin>>players>>enemyPower;
    cout<<"Players : "<<players<<" "<<"power of enemy:"<<enemyPower<<endl;
     int canditatePow[players];

     cout<<"Enter power of candidates"<<endl;

     for(int i=0;i<players;i++){
        cin>>canditatePow[i];
     }
     for(int i=0;i<players;i++){
        cout<<canditatePow[i]<<" ";
     }
    cout<<endl;
    
    insertionSort(canditatePow,players);

    cout<<"sorted:";
     for(int i=0;i<players;i++){
        cout<<canditatePow[i]<<" ";
     }
    cout<<endl;

   int wins =0;
     int i = -1;
     int j = players-1;
     int cur = canditatePow[j];

     while(i<j){
        int max = canditatePow[j];
        if(cur<= enemyPower){
            i++;
            cur = cur+max;

        }
        else{
            wins++;
            j--;
            if(j>=0){
            cur = canditatePow[j];
            }
        }
     }
    cout<<wins<<endl;
}