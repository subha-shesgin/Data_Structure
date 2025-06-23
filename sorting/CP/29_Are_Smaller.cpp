#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    vector<int> nums;

    cout << "Enter the values: (enter q to quit)" << endl;

    while (true) {
        string input;
        cin >> input;

        if (input == "q") {
            break;
        }
        try {
            int n = stoi(input);
            nums.push_back(n);
        } catch (exception &e) {
            cout << "Invalid input, please enter an integer or 'q' to quit." << endl;
        }
    }

    vector<int> small(nums.size(), 0);
    
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            if (j != i && nums[j] < nums[i]) {
                small[i]++;
            }
        }
    }
    
    cout << "Count of smaller numbers: " << endl;
    for (int n : small) {
        cout << n << " ";
    }
    cout << endl;
    
    return 0;
}
