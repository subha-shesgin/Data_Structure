#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> dijkstra(int V, vector<vector<pair<int, int>>> adj, int src) {
    // Min-heap priority queue: {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(V, 1e9); // Initialize distances to "infinity"
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int currDist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node]) {
            int adjNode = it.first;
            int edgeWeight = it.second;

            if (currDist + edgeWeight < dist[adjNode]) {
                dist[adjNode] = currDist + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

// Sample test
int main() {
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);

    // addEdge(u, v, wt)
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 1});

    int src = 0;
    vector<int> shortest = dijkstra(V, adj, src);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "To " << i << " = " << shortest[i] << endl;
    }

    return 0;
}
