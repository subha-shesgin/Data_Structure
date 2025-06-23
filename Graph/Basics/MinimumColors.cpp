#include <iostream>
#include <vector>
using namespace std;

// Function to check if it's safe to color a vertex with a specific color
bool isSafe(int node, int color, vector<vector<int>>& graph, vector<int>& colorAssigned, int V) {
    for (int i = 0; i < V; i++) {
        if (graph[node][i] == 1 && colorAssigned[i] == color) {
            return false; // Adjacent node has the same color
        }
    }
    return true;
}

// Recursive function to try assigning colors using backtracking
bool solve(int node, int maxColors, vector<vector<int>>& graph, vector<int>& colorAssigned, int V) {
    if (node == V) return true; // All nodes are colored

    for (int color = 1; color <= maxColors; color++) {
        if (isSafe(node, color, graph, colorAssigned, V)) {
            colorAssigned[node] = color;

            if (solve(node + 1, maxColors, graph, colorAssigned, V)) {
                return true;
            }

            colorAssigned[node] = 0; // Backtrack
        }
    }

    return false; // No valid color found
}

int findChromaticNumber(vector<vector<int>>& graph, int V) {
    for (int maxColors = 1; maxColors <= V; maxColors++) {
        vector<int> colorAssigned(V, 0); // All vertices initially uncolored

        if (solve(0, maxColors, graph, colorAssigned, V)) {
            cout << "Color assignment: ";
            for (int c : colorAssigned) cout << c << " ";
            cout << endl;

            return maxColors;
        }
    }

    return V; // Worst case: need V colors
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V, 0));

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter " << E << " edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1; // Undirected graph
    }

    int chromaticNumber = findChromaticNumber(graph, V);
    cout << "Minimum number of colors needed: " << chromaticNumber << endl;

    return 0;
}
