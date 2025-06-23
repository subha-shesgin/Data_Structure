#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <cstdlib> // for atoi, if you wish to keep using it
using namespace std;

int main(){
    vector<string> tokens;
    cout << "Enter the tokens (enter q to quit): ";
    while (true) {
        string s;
        cin >> s;
        if (s == "q") {
            break;
        }
        tokens.push_back(s);
    }

    stack<int> stk;
    for (int i = 0; i < tokens.size(); i++){
        string token = tokens[i];

        if (token == "+" || token == "-" || token == "*" || token == "/") {
            // Pop right operand first, then left operand.
            int right = stk.top();
            stk.pop();
            int left = stk.top();
            stk.pop();

            int result = 0;
            if (token == "+") {
                result = left + right;
            }
            else if (token == "-") {
                result = left - right;
            }
            else if (token == "*") {
                result = left * right;
            }
            else if (token == "/") {
                result = left / right;
            }
            stk.push(result);
        }
        else {
            int num = atoi(token.c_str());
            stk.push(num);
        }
    }
    cout << "Result: " << stk.top() << endl;
    return 0;
}
