#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

string reverseVowels(string s) {
    string w1 = "", w2 = "";
    bool secondWord = false;
    
    for (char c : s) {
        if (c == ' ') {
            secondWord = true;
            continue;
        }
        if (!secondWord)
            w1 += c;
        else
            w2 += c;
    }

    if (w2.empty())
        return s;

    stack<char> vowelStack;
    queue<char> vowelQueue;
    
    for (char c : w1) {
        if (isVowel(c)) vowelStack.push(c);
    }
    for (char c : w2) {
        if (isVowel(c)) vowelStack.push(c);
    }
    
    for (char c : w1) {
        if (isVowel(c)) vowelQueue.push(c);
    }
    for (char c : w2) {
        if (isVowel(c)) vowelQueue.push(c);
    }
    
    for (char &c : w1) {
        if (isVowel(c)) {
            c = vowelStack.top();
            vowelStack.pop();
        }
    }
    for (char &c : w2) {
        if (isVowel(c)) {
            c = vowelStack.top();
            vowelStack.pop();
        }
    }
    
    return w1 + " " + w2;
}

int main() {
    string input;
    cout << "Enter str: ";
    getline(cin, input);
    
    string result = reverseVowels(input);
    
    cout << "After : " << result << endl;
    return 0;
}