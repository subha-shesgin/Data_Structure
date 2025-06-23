#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
    string s,t;
    cout<<"Enter S"<<endl;
    cin>>s;
    cout<<"Enter t"<<endl;
    cin>>t;

    stack<char> S ;
     stack<char> T ;

    for(char c :s){
        if(c =='#'){
            S.pop();
        }
        else{
            S.push(c);
        }
    }
     for(char c :t){
        if(c =='#'){
            T.pop();
        }
        else{
            T.push(c);
        }
    }
    if(S == T){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}
