#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Insertion sort function to sort the array in non-decreasing order.
void insertionSort(char data[], int size) {
    for (int i = 1; i < size; i++) {
        char value = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > value) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = value;
    }
}

int main() {
    string s;
    cin >> s;
    
    // Vector to store the digit characters
    vector<char> digits;
    
    // Extract digits (skip the '+' characters)
    for (char ch : s) {
        if (ch != '+') {
            digits.push_back(ch);
        }
    }
    
    // If there are any digits, sort them using our insertionSort function.
    // We pass the underlying array pointer and the total number of digits.
    if (!digits.empty()) {
        insertionSort(&digits[0], digits.size());
    }
    
    // Rebuild the string with '+' inserted between numbers
    string result;
    for (size_t i = 0; i < digits.size(); i++) {
        result.push_back(digits[i]);
        if (i < digits.size() - 1) {  // Don't add '+' after the last digit
            result.push_back('+');
        }
    }
    
    // Output the sorted string
    cout << result << endl;
    
    return 0;
}
