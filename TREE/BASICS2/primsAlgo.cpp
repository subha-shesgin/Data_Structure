#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[]) {
    // Min-heap: {weight, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> vis(V, 0); // Track visited nodes

    pq.push({0, 0}); // Start from node 0 with weight 0
    int sum = 0;

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        int wt = it.first;
        int node = it.second;

        if (vis[node]) continue;

        vis[node] = 1;
        sum += wt;

        // Visit adjacent nodes
        for (auto edge : adj[node]) {
            int adjNode = edge[0];
            int edgeWt = edge[1];

            if (!vis[adjNode]) {
                pq.push({edgeWt, adjNode});
            }
        }
    }

    return sum;
}

// Sample test
int main() {
    int V = 5;
    vector<vector<int>> adj[V];

    // Edge format: adj[u].push_back({v, wt}) and adj[v].push_back({u, wt}) for undirected graph
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    cout << "Weight of MST: " << spanningTree(V, adj) << endl;

    return 0;
}
