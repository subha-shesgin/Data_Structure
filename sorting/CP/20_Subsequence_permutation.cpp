#include <iostream>
#include <string>
#include <algorithm> // For std::sort
using namespace std;

int main() {
    int t;
    cin >> t;
    cout << "Test cases: " << t << endl;

    for (int test = 0; test < t; test++) {
        int n;
        cin >> n;

        string s;
        cin >> s;
        
        string z = s;  // Create a copy of the string
        sort(z.begin(), z.end()); // Sort the string

        int k = 0;

        // Compare original string s with sorted string z
        for (int i = 0; i < n; i++) {
            if (s[i] != z[i]) {
                k++;
            }
        }
        cout << k << endl; // Output the count of differing characters
    }

    return 0;
}
