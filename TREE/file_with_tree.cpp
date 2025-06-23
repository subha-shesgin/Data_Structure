#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

const int MAXN = 100;
vector<int> tree[MAXN];
bool visited[MAXN];

// Simple DFS traversal to print tree
void dfs(int node, int parent = -1) {
    cout << "Visited node: " << node << endl;
    visited[node] = true;

    for (int child : tree[node]) {
        if (child != parent && !visited[child]) {
            dfs(child, node);
        }
    }
}

int main() {
    ifstream infile("tree.txt");
    string line;

    // Read tree edges from file using stringstream
    while (getline(infile, line)) {
        stringstream ss(line);
        int u, v;
        ss >> u >> v;

        // Bidirectional edge (since tree is undirected)
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    cout << "DFS traversal from root node 0:" << endl;
    dfs(0);

    return 0;
}
