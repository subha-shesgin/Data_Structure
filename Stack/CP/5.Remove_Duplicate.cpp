#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    // Step 1: Count the frequency of each character.
    int freq[26] = {0};
    for (char c : s) {
        freq[c - 'a']++;
    }
    
    // Step 2: Use a boolean array to track if a character is already in the stack.
    bool inStack[26] = {false};
    stack<char> st;
    
    // Step 3: Traverse the string.
    for (char c : s) {
        // Decrement the frequency since we are processing this occurrence.
        freq[c - 'a']--;
        
        // If the character is already in the stack, skip it.
        if (inStack[c - 'a'])
            continue;
        
        // Step 4: While stack is not empty and the current character is smaller than
        // the character on top of the stack, and the top character will appear later,
        // pop the stack.
        while (!st.empty() && st.top() > c && freq[st.top() - 'a'] > 0) {
            inStack[st.top() - 'a'] = false;
            st.pop();
        }
        
        // Step 5: Push the current character onto the stack and mark it.
        st.push(c);
        inStack[c - 'a'] = true;
    }
    
    // Step 6: Build the resulting string from the stack.
    string result = "";
    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    
    // The characters are in reverse order; reverse the string manually.
    int n = result.size();
    for (int i = 0; i < n / 2; i++) {
        char temp = result[i];
        result[i] = result[n - i - 1];
        result[n - i - 1] = temp;
    }
    
    cout << result << endl;
    return 0;
}
