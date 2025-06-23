#include<iostream>
using namespace std;
void Print(int n){
    if (n==0){
        return;
    }
    cout<<"I Love Recursion"<<endl;
    Print(n-1);
}
int main(){
    int n ;
    cin>>n;
    Print(n);
}