#include <iostream>
#include <queue>
#include <cctype>  // For tolower()
using namespace std;

// Function to check if a string is a palindrome (ignoring case & spaces)
bool isPalindrome(string str) {
    queue<char> q;
    string cleaned = "", reversed = "";

    // Convert to lowercase and remove spaces
    for (char ch : str) {
        if (isalnum(ch)) {  // Ignore spaces and special characters
            ch = tolower(ch);
            q.push(ch);
            cleaned += ch;
        }
    }

    // Reconstruct the reversed string
    while (!q.empty()) {
        reversed = q.front() + reversed;  // Build reversed string
        q.pop();
    }

    // Compare cleaned string with reversed version
    return (cleaned == reversed);
}

int main() {
    string str = "Able was I ere I saw Elba";

    if (isPalindrome(str))
        cout << "\"" << str << "\" is a palindrome!" << endl;
    else
        cout << "\"" << str << "\" is not a palindrome." << endl;

    return 0;
}
