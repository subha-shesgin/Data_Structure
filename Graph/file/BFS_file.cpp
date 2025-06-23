#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(int V, vector<vector<int>>& adj, int start) {
    vector<int> visited(V, 0);
    queue<int> q;
    vector<int> result;

    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }

    return result;
}

int main() {
    ifstream inFile("graph.txt");
    int V, E;
    inFile >> V >> E;

    vector<vector<int>> adj(V);
    for (int i = 0; i < E; ++i) {
        int u, v;
        inFile >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // For undirected graph
    }
    inFile.close();

    vector<int> bfsResult = bfs(V, adj, 0);

    ofstream outFile("bfs_output.txt");
    outFile << "BFS Traversal: ";
    for (int node : bfsResult) {
        outFile << node << " ";
    }
    outFile << endl;
    outFile.close();

    cout << "BFS result written to bfs_output.txt" << endl;

    return 0;
}
