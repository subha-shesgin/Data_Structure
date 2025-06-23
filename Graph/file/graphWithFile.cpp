#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    ifstream infile("graph.txt");
    if (!infile.is_open()) {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    string line;
    int V, E;

    // Read first line: V E
    getline(infile, line);
    stringstream ss(line);
    ss >> V >> E;

    // Create adjacency list for weighted graph
    vector<pair<int, int>> adj[V];

    // Read edges
    while (getline(infile, line)) {
        stringstream edgeStream(line);
        int u, v, w;
        edgeStream >> u >> v >> w;

        adj[u].push_back({v, w});
        // If undirected graph, add: adj[v].push_back({u, w});
    }

    infile.close();

    // Print the graph
    cout << "Adjacency List of Weighted Graph:\n";
    for (int i = 0; i < V; i++) {
        cout << i << " -> ";
        for (auto [neighbor, weight] : adj[i]) {
            cout << "(" << neighbor << ", " << weight << ") ";
        }
        cout << endl;
    }

    return 0;
}
