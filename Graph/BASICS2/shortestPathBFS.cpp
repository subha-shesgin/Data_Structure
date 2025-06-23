#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
    vector<int> adj[N];

    // Create the adjacency list
    for (auto it : edges) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]); // Because the graph is undirected
    }

    vector<int> dist(N, 1e9);  // Initialize distances to "infinity"
    dist[src] = 0;

    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto neighbor : adj[node]) {
            if (dist[node] + 1 < dist[neighbor]) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

    // Prepare the result, convert unreachable nodes from 1e9 to -1
    vector<int> ans(N, -1);
    for (int i = 0; i < N; i++) {
        if (dist[i] != 1e9) {
            ans[i] = dist[i];
        }
    }

    return ans;
}

// Sample main to test the function
int main() {
    int N = 6, M = 7, src = 0;
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3},
        {2, 3},
        {3, 4},
        {4, 5},
        {1, 2}
    };

    vector<int> result = shortestPath(edges, N, M, src);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < N; i++) {
        cout << "To " << i << ": " << result[i] << endl;
    }

    return 0;
}
