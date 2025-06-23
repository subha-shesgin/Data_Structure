#include <iostream>
#include <vector>
using namespace std;

int main() {
    int V = 5;  // Number of vertices
    vector<vector<int>> graph(V);  // Adjacency list

    // Add edges (undirected)
    graph[0].push_back(1);
    graph[1].push_back(0);

    graph[0].push_back(2);
    graph[2].push_back(0);

    graph[1].push_back(3);
    graph[3].push_back(1);

    graph[1].push_back(4);
    graph[4].push_back(1);

    // Print the graph
    cout << "Adjacency list of the graph:\n";
    for (int i = 0; i < V; ++i) {
        cout << i << ": ";
        for (int j : graph[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
