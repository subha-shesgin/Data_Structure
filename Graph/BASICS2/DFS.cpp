#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &res) {
    vis[node] = 1;
    res.push_back(node);

    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, adj, vis, res);
        }
    }
}

vector<int> DfsTraversal(int V, vector<vector<int>> &adj) {
    vector<int> vis(V, 0);
    vector<int> res;
    int start = 0;
    dfs(start, adj, vis, res);
    return res;
}

int main() {
    vector<vector<int>> adj = {
        {1, 2},     // 0
        {0, 2, 3},  // 1
        {0, 4},     // 2
        {1, 4},     // 3
        {2, 3}      // 4
    };
    
    int V = adj.size();
    vector<int> ans = DfsTraversal(V, adj);

    for (auto i : ans) {
        cout << i << " ";
    }

    return 0;
}
