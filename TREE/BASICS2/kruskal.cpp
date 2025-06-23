#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int parent[MAXN], rankArr[MAXN];

// Initialize DSU
void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rankArr[i] = 0;
    }
}

// Find with path compression
int find(int u) {
    if (parent[u] != u)
        parent[u] = find(parent[u]);
    return parent[u];
}

// Union by rank
void unionByRank(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);

    if (rootU == rootV) return;

    if (rankArr[rootU] < rankArr[rootV]) {
        parent[rootU] = rootV;
    } else if (rankArr[rootV] < rankArr[rootU]) {
        parent[rootV] = rootU;
    } else {
        parent[rootV] = rootU;
        rankArr[rootU]++;
    }
}

int SpanningTree(int n, vector<vector<int>> adj[], vector<tuple<int, int, int>> &mstEdges) {
    vector<pair<int, pair<int, int>>> edges;

    // Collect all unique undirected edges
    for (int i = 0; i < n; i++) {
        for (auto it : adj[i]) {
            int adjNode = it[0];
            int wt = it[1];
            int node = i;

            if (node < adjNode) {
                edges.push_back({wt, {node, adjNode}});
            }
        }
    }

    sort(edges.begin(), edges.end());
    makeSet(n);  // Initialize DSU

    int mstWt = 0;

    for (auto it : edges) {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if (find(u) != find(v)) {
            mstWt += wt;
            unionByRank(u, v);
            mstEdges.push_back({u, v, wt});
        }
    }

    return mstWt;
}

int main() {
    int n, e, u, v, w;
    cin >> n >> e;

    vector<vector<int>> adj[n];

    for (int i = 0; i < e; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<tuple<int, int, int>> mstEdges;
    int mstWeight = SpanningTree(n, adj, mstEdges);

    cout << "\nMST Total Weight: " << mstWeight << endl;
    cout << "\nEdges in MST:\n";
    for (auto &[u, v, w] : mstEdges) {
        cout << u << " - " << v << " (weight: " << w << ")\n";
    }

    return 0;
}
