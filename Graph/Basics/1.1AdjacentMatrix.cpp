#include<iostream>
using namespace std;
int main()
{
     int Adj[4][4] ={0};
     int edges = 5;

     int from; 
     int to;

     for(int i =0;i<edges;i++){
        cout<<"enter starting and ending node"<<endl;
        cin>>from>>to;

        Adj[from][to] =1;
        Adj[to][from] =1;

     }
     cout<<"Adjacent matrix"<<endl;
     for(int i =0;i<4;i++){
        for(int j =0;j<4;j++){
            cout<<Adj[i][j];
        }
        cout<<endl;
     }




}
