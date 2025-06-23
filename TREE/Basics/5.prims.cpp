#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100;

// Prim's Algorithm to find MST weight
int primMST(int V, int E, vector<vector<int>> &edges) {
    // Step 1: Create an adjacency list
    vector<pair<int, int>> adj[MAX];  // pair<vertex, weight>

    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});  // Because undirected graph
    }

    // Step 2: Create a visited array to mark nodes already in MST
    vector<bool> visited(V, false);

    // Step 3: Priority queue to choose minimum weight edge (min-heap)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Step 4: Start from node 0
    pq.push({0, 0});  // (weight, vertex)

    int mstCost = 0;

    // Step 5: Run loop until all vertices are included
    while (!pq.empty()) {
        pair<int, int> curr = pq.top();
        pq.pop();

        int weight = curr.first;
        int node = curr.second;

        // Skip if already included
        if (visited[node]) continue;

        visited[node] = true;
        mstCost += weight;

        // Step 6: Push all adjacent edges to the priority queue
        for (int i = 0; i < adj[node].size(); i++) {
            int adjNode = adj[node][i].first;
            int edgeWt = adj[node][i].second;

            if (!visited[adjNode]) {
                pq.push({edgeWt, adjNode});
            }
        }
    }

    return mstCost;
}

int main() {
    int V = 3, E = 3;

    vector<vector<int>> graph = {
        {0, 1, 5},
        {1, 2, 3},
        {0, 2, 1}
    };

    int result = primMST(V, E, graph);
    cout << "Minimum cost of MST is: " << result << endl;

    return 0;
}