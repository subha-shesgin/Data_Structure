#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100;
int parent[MAX];
int rankArr[MAX];

// Find the parent (with path compression)
int find(int i) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent[i]);
}

// Union by rank
void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        if (rankArr[rootX] < rankArr[rootY]) {
            parent[rootX] = rootY;
        } else if (rankArr[rootX] > rankArr[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rankArr[rootX]++;
        }
    }
}

// Comparator for sorting edges based on weight
bool compare(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

// Kruskal’s Algorithm to find Minimum Spanning Tree cost
int kruskalMST(int V, vector<vector<int>> &edges) {
    // Step 1: Sort the edges based on weight
    sort(edges.begin(), edges.end(), compare);

    // Step 2: Initialize parent and rank
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rankArr[i] = 0;
    }

    int mstCost = 0;
    int count = 0;

    // Step 3: Traverse sorted edges
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        // Step 4: Check if including this edge forms a cycle
        if (find(u) != find(v)) {
            unite(u, v);
            mstCost += weight;
            count++;

            if (count == V - 1) break;  // Minimum edges = V - 1
        }
    }

    return mstCost;
}

int main() {
    int V = 4; // Number of vertices

    // Each edge: {u, v, weight}
    vector<vector<int>> edges = {
        {0, 1, 10},
        {1, 3, 15},
        {2, 3, 4},
        {2, 0, 6},
        {0, 3, 5}
    };

    int result = kruskalMST(V, edges);
    cout << "Minimum cost of MST is: " << result << endl;

    return 0;
}