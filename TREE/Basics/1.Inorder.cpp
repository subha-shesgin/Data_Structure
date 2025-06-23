#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100;
vector<int> adj[MAX];  // Adjacency list
int parent[MAX];       // To find the root

// Inorder-style DFS traversal
void inorder(int node, int par) {
    if (!adj[node].empty()) {
        for (int child : adj[node]) {
            if (child != par) {
                inorder(child, node);
                break;
            }
        }
    }

    cout << node << " ";

    bool skipped = false;
    for (int child : adj[node]) {
        if (child != par) {
            if (!skipped) {
                skipped = true;
                continue;
            }
            inorder(child, node);
        }
    }
}

int main() {
    int n = 6;

    for (int i = 0; i < MAX; i++) parent[i] = -1;

    adj[1].push_back(12); adj[12].push_back(1); parent[12] = 1;
    adj[1].push_back(9); adj[9].push_back(1); parent[9] = 1;
    adj[12].push_back(5); adj[5].push_back(12); parent[5] = 12;
    adj[12].push_back(6); adj[6].push_back(12); parent[6] = 12;
    //adj[3].push_back(6); adj[6].push_back(3); parent[6] = 3;

    int root = -1;
    for (int i = 1; i <= n; i++) {
        if (parent[i] == -1) {
            root = i;
            break;
        }
    }

    cout << "Inorder-like traversal: ";
    inorder(root, -1);

    return 0;
}