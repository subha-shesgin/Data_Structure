#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100;
vector<int> adj[MAX];  // Adjacency list
int parent[MAX];       // To find the root

// Preorder Traversal: Node -> Children
void preorder(int node, int par) {
    cout << node << " ";  // Visit the node

    // Visit all children (skip parent to avoid going backward)
    for (int child : adj[node]) {
        if (child != par) {
            preorder(child, node);
        }
    }
}

int main() {
    int n = 6; // Number of nodes

    // Initialize parent array
    for (int i = 0; i < MAX; i++) parent[i] = -1;

    // Build the tree as an adjacency list
    adj[1].push_back(2); adj[2].push_back(1); parent[2] = 1;
    adj[1].push_back(3); adj[3].push_back(1); parent[3] = 1;
    adj[2].push_back(4); adj[4].push_back(2); parent[4] = 2;
    adj[2].push_back(5); adj[5].push_back(2); parent[5] = 2;
    adj[3].push_back(6); adj[6].push_back(3); parent[6] = 3;

    // Find the root node
    int root = -1;
    for (int i = 1; i <= n; i++) {
        if (parent[i] == -1) {
            root = i;
            break;
        }
    }

    cout << "Preorder Traversal: ";
    preorder(root, -1);

    return 0;
}