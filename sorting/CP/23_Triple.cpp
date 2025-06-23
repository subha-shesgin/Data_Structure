#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int arr[n];  // Array to store input
        int freq[100001] = {0};  // Assuming input values range from 0 to 100000

        // Step 1: Read the array and calculate frequency
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
            freq[arr[j]]++;
        }

        // Step 2: Find the first element that appears at least 3 times
        int result = -1;
        for (int j = 0; j < n; j++) {
            if (freq[arr[j]] >= 3) {
                result = arr[j];
                break;  // Exit the loop once we find the result
            }
        }

        // Step 3: Print the result after checking all elements
        cout << result << endl;
    }

    return 0;
}
