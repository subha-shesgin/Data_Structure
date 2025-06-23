#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bipartite(int V, vector<vector<int>> &adj) {
    vector<int> color(V, -1);
    queue<int> q;

    // Handle disconnected graphs too
    for (int start = 0; start < V; ++start) {
        if (color[start] == -1) {
            q.push(start);
            color[start] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (auto it : adj[node]) {
                    if (color[it] == -1) {
                        color[it] = !color[node];
                        q.push(it);
                    } else if (color[it] == color[node]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int V = 4;  // Number of vertices
    vector<vector<int>> graph(V);

    // Create a bipartite graph: 0-1-2-3
    graph[0].push_back(1);
    graph[1].push_back(0);

    graph[1].push_back(2);
    graph[2].push_back(1);

    graph[2].push_back(3);
    graph[3].push_back(2);

    bool result = bipartite(V, graph);

    if (result) 
        cout << "The graph is bipartite." << endl;
    else
        cout << "The graph is NOT bipartite." << endl;

    return 0;
}
