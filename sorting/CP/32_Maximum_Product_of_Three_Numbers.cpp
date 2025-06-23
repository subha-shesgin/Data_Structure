#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumProduct(vector<int>& nums) {
    // Sort the array
    sort(nums.begin(), nums.end());
    
    // Calculate the two possible products:
    // 1. Product of the three largest numbers
    int product1 = nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3];
    
    // 2. Product of the two smallest and the largest number
    int product2 = nums[0] * nums[1] * nums[nums.size() - 1];
    
    // Return the maximum of both products
    return max(product1, product2);
}

int main() {
    vector<int> nums = {-10, -10, 5, 2};
    cout << "Maximum product of three numbers is: " << maximumProduct(nums) << endl;
    for(int n : nums){
        cout <<n<<" ";
    }
    return 0;
}
