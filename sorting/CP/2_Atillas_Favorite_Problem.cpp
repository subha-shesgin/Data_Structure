#include <iostream>
#include <string>

using namespace std;

void selectionSort(string& s) {
    int size = s.length();
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (s[j] < s[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = s[i];
            s[i] = s[minIndex];
            s[minIndex] = temp;
        }
    }
}

int main(){
    int test;
   
    cout<<"Enter test cases"<<endl;
    cin>> test ;
    cout<<test<<endl;

    for(int i =1;i<=test;i++){
         int length;
         string str;
        cout<<"enter length of string "<<endl;
        cin>>length;
        cout<<"enter string"<<endl;
        cin>>str;

        if(str.length() == length){
            
            cout<<length<<endl;
            cout<<str<<endl;
        }

        selectionSort(str);

        int alphabet = str[str.length() - 1] - 96;

        cout<<"required size = "<<alphabet<<endl;

    }
    

    return 0;
}