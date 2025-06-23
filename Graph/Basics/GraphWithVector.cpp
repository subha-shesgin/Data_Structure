#include<iostream>
#include<vector>
using namespace std;

int main(){
    int node,edges;
    cout<<"Enter number of nodes and edges :"<<endl;
    cin>>node>>edges;

    vector<vector<int>> adj(node+1);
    cout<<"Enter nodes for edges :";
    for(int i =0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    cout<<"\nThe graph is :"<<endl;
    for(int i =1;i<=node;i++){
        cout<<"Node"<<i<<": ";
        for(int neighbour : adj[i]){
            cout<<neighbour<<" ";
        }
        cout<<endl;
    }
    return 0;

}