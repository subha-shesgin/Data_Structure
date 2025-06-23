#include <iostream>
#include <queue>
#include <sstream>  // To split the input string into words
using namespace std;

int main() {
    queue<string> q;  // Queue to store the words
    string str;
    string reversed = "";

    // Get the full line of input
    getline(cin, str);

    // Use a stringstream to split the input string into words
    stringstream ss(str);
    string word;

    // Push words into the queue
    while (ss >> word) {
        q.push(word);
    }

    // Construct the reversed string by dequeuing and appending words
    while (!q.empty()) {
        reversed = q.front() + " " + reversed;  // Add word to the front of reversed
        q.pop();  // Remove the word from the queue
    }

    // Print the result
    cout << reversed << endl;

    return 0;
}
