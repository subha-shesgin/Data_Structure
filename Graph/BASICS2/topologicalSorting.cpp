#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> toposort(int V, vector<vector<int>> &adj) {
    vector<int> indegree(V, 0);

    // Count indegrees
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (auto it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0) {
                q.push(it);
            }
        }
    }

    return topo;
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V); // Adjacency list

    cout << "Enter " << E << " directed edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Directed edge from u to v
    }

    vector<int> result = toposort(V, adj);

    if (result.size() != V) {
        cout << "The graph contains a cycle. Topological sort not possible." << endl;
    } else {
        cout << "\nOne possible Topological Sort:" << endl;
        for (auto node : result) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
