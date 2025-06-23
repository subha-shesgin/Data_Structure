#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    vector <int> nums;

    cout<<"Enter the values: (enter q to quit)"<<endl;

    while(1){
        
        string input;
        cin>>input;

        if(input == "q"){
            break;
        }
        else{
            int n = stoi(input);
            nums.push_back(n);
        }
    }
    cout<<"nums :"<<endl;
    for(int n :nums){
        cout<<n<<" ";
    }
    cout<<endl;

   

    for(int n : nums){
         int count=0;
        for(int i =0;i < nums.size(); i++){
            if(nums[i] == n){
                count++;
            }if(count >= 2){
                cout<<"True"<<endl;
                return 0;
            }
        
        }
    }
    cout<<"False"<<endl;
    
}