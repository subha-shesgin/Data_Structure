#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> coins(n);

    int total_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
        total_sum += coins[i];
    }

    // Sort coins in descending order
    sort(coins.rbegin(), coins.rend());

    int selected_sum = 0;
    int num_coins = 0;

    // Select coins until the sum of selected coins exceeds half of total sum
    for (int i = 0; i < n; i++) {
        selected_sum += coins[i];
        num_coins++;
        if (selected_sum > total_sum / 2) {
            break;
        }
    }

    cout << num_coins << endl;
    return 0;
}
