#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs = {{}};
        for (int num : nums) {
            int n = subs.size();
            for (int i = 0; i < n; i++) {
                subs.push_back(subs[i]); 
                subs.back().push_back(num);
            }
        }
        return subs;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3}; // Example input
    vector<vector<int>> result = sol.subsets(nums);
    
    // Output the subsets
    cout << "Subsets:" << endl;
    for (const auto& subset : result) {
        cout << "{";
        for (size_t i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ", ";
        }
        cout << "}" << endl;
    }
    
    return 0;
}