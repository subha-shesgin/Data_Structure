#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int freq[1001] = {0};  // Frequency array initialized to 0
    int length, max_height = 0, total_towers = 0;

    // Read input and update frequency array
    for (int i = 0; i < N; i++) {
        cin >> length;
        freq[length]++;  // Count occurrences of each length
    }

    // Analyze the frequency array
    for (int i = 1; i <= 1000; i++) {
        if (freq[i] > 0) {  
            total_towers++;                // Count unique bar lengths (number of towers)
            max_height = max(max_height, freq[i]);  // Find the tallest tower
        }
    }

    cout << max_height << " " << total_towers << endl;
    return 0;
}
