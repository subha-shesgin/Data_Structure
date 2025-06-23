#include <iostream>
#include <fstream>
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

bool canForm(string pile , string guest,string host){
    selectionSort(pile);
    selectionSort(guest);
    selectionSort(host);

    string combineWord = guest + host;
    selectionSort(combineWord);

    return (pile == combineWord);
}


int main(){
//ofstream file ("file.txt")
//file <<"nvmnc"

    ifstream file("Amusing_joke.txt");
    string guest,host,pile;

    if (!file) {
    cout << "Error: File not found!" << endl;
    return 1;
}

    getline(file,guest);
    getline(file,host);
    getline(file,pile);

    file.close();

    cout<<"Guest : "<<guest<<endl;
    cout<<"Host : "<<host<<endl;
    cout<<"Letters : "<<pile<<endl;

    if(canForm(pile,guest,host)){
        cout<< "Yes"<<endl;

    }
    else{
        cout<< "No"<<endl;
    }
    
    return 0;

}