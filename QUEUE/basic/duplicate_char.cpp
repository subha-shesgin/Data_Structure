#include <iostream>
#include <queue>
#include <string>
using namespace std;

string removeAdjacentDuplicates(string str) {
    queue<char> q;
    string result = "";

    for (char ch : str) {
        // If result is not empty and last character in result matches current character, remove it
        if (!result.empty() && result.back() == ch) {
            result.pop_back();  // Remove last character (simulating stack behavior)
        } else {
            result += ch;  // Append the character if no adjacent duplicate
        }
    }

    // If the result is empty, return "Empty String"
    return result.empty() ? "Empty String" : result;
}

int main() {
    string str;
    cout << "Enter the string: ";
    cin >> str;

    string result = removeAdjacentDuplicates(str);
    cout << "Result: " << result << endl;

    return 0;
}
