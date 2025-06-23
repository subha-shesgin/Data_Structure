#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100;
int adjMatrix[MAX][MAX] = {0};     // Adjacency matrix
int indegree[MAX] = {0};           // Indegree of each node
bool visited[MAX] = {false};       // Visited flag
vector<int> result;                // Stores current topological sort
int V;                             // Number of vertices

void allTopologicalSorts() {
    bool flag = false;

    for (int i = 0; i < V; i++) {
        if (!visited[i] && indegree[i] == 0) {
            // Choose vertex i
            visited[i] = true;
            result.push_back(i);

            // Reduce indegree of neighbors
            for (int j = 0; j < V; j++) {
                if (adjMatrix[i][j] == 1)
                    indegree[j]--;
            }

            // Recurse
            allTopologicalSorts();

            // Backtrack
            visited[i] = false;
            result.pop_back();
            for (int j = 0; j < V; j++) {
                if (adjMatrix[i][j] == 1)
                    indegree[j]++;
            }

            flag = true;
        }
    }

    // If all nodes are included in result, print it
    if (!flag && result.size() == V) {
        for (int node : result)
            cout << node << " ";
        cout << endl;
    }
}

int main() {
    int E;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter " << E << " directed edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        indegree[v]++;
    }

    cout << "\nAll possible Topological Sorts:\n";
    allTopologicalSorts();

    return 0;
}