#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100;
vector<int> graph[MAX];
int V;  // number of vertices

bool isBipartite(int start, vector<int>& color) {
    queue<int> q;
    q.push(start);
    color[start] = 0;  // Start with color 0

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (color[v] == -1) {
                // Assign opposite color to neighbor
                color[v] = 1 - color[u];
                q.push(v);
            } else if (color[v] == color[u]) {
                // Same color on both sides = not bipartite
                return false;
            }
        }
    }

    return true;
}

bool checkBipartite() {
    vector<int> color(V, -1);  // -1 = uncolored

    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            if (!isBipartite(i, color)) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    V = 4;  // Number of vertices

    // Create a bipartite graph: 0-1-2-3 (even cycle)
    graph[0].push_back(1);
    graph[1].push_back(0);

    graph[1].push_back(2);
    graph[2].push_back(1);

    graph[2].push_back(3);
    graph[3].push_back(2);

    bool result = checkBipartite();

    if (result)
        cout << "The graph is bipartite." << endl;
    else
        cout << "The graph is NOT bipartite." << endl;

    return 0;
}
