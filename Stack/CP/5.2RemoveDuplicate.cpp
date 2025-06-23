#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

string removeDuplicateLetters(string s) {
    unordered_map<char, int> lastIndex;
    for (int i = 0; i < s.size(); i++) {
        lastIndex[s[i]] = i; // Store the last occurrence of each character
    }

    stack<char> st;
    unordered_set<char> seen;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (seen.find(c) != seen.end()) continue; // Skip if already in result

        while (!st.empty() && st.top() > c && lastIndex[st.top()] > i) {
            seen.erase(st.top()); // Remove from seen set
            st.pop(); // Pop from stack
        }

        st.push(c);
        seen.insert(c);
    }

    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }
    return result;
}

int main() {
    string s1 = "bcabc";
    string s2 = "cbacdcbc";
    cout << "Output 1: " << removeDuplicateLetters(s1) << endl;
    cout << "Output 2: " << removeDuplicateLetters(s2) << endl;
    return 0;
}
