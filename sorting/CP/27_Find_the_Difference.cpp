#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Insertion Sort for strings
void insertionSort(string &data) {
    int size = data.length();
    for (int i = 1; i < size; i++) {
        char value = data[i];  
        int j = i - 1;
        
        // Move characters that are greater than 'value' one position ahead
        while (j >= 0 && data[j] > value) {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = value;
    }
}

// Function to find the added character
char findAddedCharacter(string s, string t) {
    char addedChar = 0;
    for (char c : t) {
        addedChar ^= c;
    }
    for (char c : s) {
        addedChar ^= c;
    }
    return addedChar;
}

int main() {
    string s, t;

    cout << "Enter the string s :" << endl;
    cin >> s;
    cout << s << endl;
    insertionSort(s);

    t = s;
    char c = 'b';
    t.push_back(c);
    
    // Find the added character
    char addedChar = findAddedCharacter(s, t);
    cout << "The added character is: " << addedChar << endl;
    
    return 0;
}
