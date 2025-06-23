#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to add an undirected edge
void addEdge(vector<vector<int>> &adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // because the graph is undirected
}

// Iterative DFS function
vector<int> DFS_iterative(vector<vector<int>> &adj, int start) {
    vector<bool> visited(adj.size(), false);
    vector<int> res;
    stack<int> st;

    st.push(start);

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!visited[node]) {
            visited[node] = true;
            res.push_back(node);

            // Push neighbors (in reverse order to match recursive DFS more closely)
            for (auto it = adj[node].rbegin(); it != adj[node].rend(); ++it) {
                if (!visited[*it]) {
                    st.push(*it);
                }
            }
        }
    }

    return res;
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);

    // List of edges
    vector<vector<int>> edges = {
        {1, 2},
        {1, 0},
        {2, 0},
        {2, 3},
        {2, 4}
    };

    // Build the adjacency list
    for (auto &e : edges) {
        addEdge(adj, e[0], e[1]);
    }

    // Perform iterative DFS from node 0
    vector<int> result = DFS_iterative(adj, 0);

    // Output the traversal order
    cout << "DFS traversal (iterative): ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
