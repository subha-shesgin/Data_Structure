#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> DfsTraversal(int V, vector<vector<int>> &adj) {
    vector<int> vis(V, 0);
    vector<int> res;
    stack<int> st;

    st.push(0); // Start from node 0

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!vis[node]) {
            vis[node] = 1;
            res.push_back(node);

            // Push neighbors in the order they appear (no reverse)
            for (auto it : adj[node]) {
                if (!vis[it]) {
                    st.push(it);
                }
            }
        }
    }

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
