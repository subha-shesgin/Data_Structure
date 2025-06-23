#include <iostream>
 
using namespace std;

int main(){
    int s,n;
    cout<<"Enter value of S and N :"<<endl;
    cin>>s>>n;
    cout<<s<<" "<<n<<" "<<endl;

    int x,y;
    int count =0;

    for(int i =0;i<n;i++){
        cout<<"Enter x and y"<<endl;
        cin>>x>>y;
        cout<<x<<" "<<y<<" "<<endl;

        if(s>x){
            count++;
            s= s+y;
        }

    }
    if(count == n){
        cout<<"YES"<<endl;
    }
    else{
         cout<<"No"<<endl;
    }
    return 0;
}