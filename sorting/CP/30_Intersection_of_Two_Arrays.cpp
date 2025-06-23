#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main(){
    vector<int> nums1;
    cout << "Enter the values for nums1: (enter q to quit)" << endl;

    while(true){
        string input;
        cin >> input;

        if(input == "q"){
            break;
        } else {
            int n = stoi(input);
            nums1.push_back(n);
        }
    }

    vector<int> nums2;
    cout << "Enter the values for nums2: (enter q to quit)" << endl;

    while(true){
        string input;
        cin >> input;

        if(input == "q"){
            break;
        } else {
            int n = stoi(input);
            nums2.push_back(n);
        }
    }

    set<int> result;
    for(int i = 0; i < nums1.size(); i++) {
        for(int j =0; j< nums2.size();j++){
            if(nums1[i] == nums2[j]){
                result.insert(nums1[i]);
            }

        }
    }

    for(int n : result){
        cout<<n<<" ";
    }
    cout<<endl;
    return 0;
}
