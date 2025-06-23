//Better Optimized because set erases duplicates and sortes in ascending order
#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S){
   set<pair<int, int>> st;
   vector<int> dist(V, 1e9);

   st.insert({0, S});
   dist[S] = 0;

   while(!st.empty()){
        auto it = *(st.begin());
        int currdis = it.first;
        int node = it.second;
        st.erase(it);

        for(auto it: adj[node]){
            int edgeWeight = it[1];
            int adjNode = it[0];
            if(currdis + edgeWeight < dist[adjNode]){
                //erase if existed
                if(dist[adjNode] != 1e9){
                    st.erase({dist[adjNode], adjNode});
                }
                dist[adjNode] = currdis + edgeWeight;
                st.insert({dist[adjNode], adjNode});
            }
        }
   }
   return dist;
}

int main(){
    int n, e, u, v, w;
    cin >> n; // number of nodes
    cin >> e; // number of edges
    vector<vector<int>> adj[n+1];
    for(int i = 0; i < e; i++){
        cin >> u >> v >> w;
        //there is an edge between u and v with weight w
        adj[u].push_back({v, w}); // v is an adjacent node of u and weight is w
        adj[v].push_back({u,w}); // u is an adjacent node of v and weight is w
            
    }
    
    int source;
    cin >> source;

    vector<int> dist = dijkstra(n + 1, adj, source);

    for (int i = 1; i <= n; i++) {
        cout << "Distance from " << source << " to " << i << " = " << dist[i] << "\n";
    }

    return 0;

}
// Time Complexity: E log V

/*
test case:
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

*/