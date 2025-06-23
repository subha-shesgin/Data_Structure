#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100;
bool adj[MAX][MAX];
int V;

// Function to check if the graph is K5
bool isK5() {
    if (V != 5) return false;

    for (int i = 0; i < V; ++i) {
        int count = 0;
        for (int j = 0; j < V; ++j) {
            if (i != j && adj[i][j]) count++;
        }
        if (count != 4) return false;
    }
    return true;
}

// Function to check if the graph is K3,3
bool isK33() {
    if (V != 6) return false;

    int set1[3] = {0, 1, 2};
    int set2[3] = {3, 4, 5};

    // No internal edges in either set
    for (int i = 0; i < 3; ++i)
        for (int j = i + 1; j < 3; ++j)
            if (adj[set1[i]][set1[j]] || adj[set2[i]][set2[j]])
                return false;

    // Full connection between the sets
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (!adj[set1[i]][set2[j]])
                return false;

    return true;
}

bool isPlanar() {
    if (isK5() || isK33())
        return false;
    return true;
}

int main() {
    V = 5; // number of vertices
    int edges[][2] = {
        {0, 1}, {0, 2}, {0, 3}, {0, 4},
        {1, 2}, {1, 3}, {1, 4},
        {2, 3}, {2, 4},
        {3, 4}
    };
    int E = sizeof(edges) / sizeof(edges[0]);

    // Initialize adjacency matrix
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            adj[i][j] = false;

    // Add edges
    for (int i = 0; i < E; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][v] = adj[v][u] = true;
    }

    if (isPlanar())
        cout << "Graph is probably planar." << endl;
    else
        cout << "Graph is NOT planar (K5 or K3,3 detected)." << endl;

    return 0;
}