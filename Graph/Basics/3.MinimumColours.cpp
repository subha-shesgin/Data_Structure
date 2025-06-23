#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100;
vector<int> graph[MAX];
int V;  // number of vertices

bool isSafe(int v, vector<int>& color, int c) {
    for (int u : graph[v]) {
        if (color[u] == c)
            return false;
    }
    return true;
}

bool graphColoringUtil(int m, vector<int>& color, int v) {
    if (v == V)
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, color, c)) {
            color[v] = c;
            if (graphColoringUtil(m, color, v + 1))
                return true;
            color[v] = 0;
        }
    }

    return false;
}

int findChromaticNumber() {
    for (int m = 1; m <= V; ++m) {
        vector<int> color(V, 0);
        if (graphColoringUtil(m, color, 0)) {
            return m;
        }
    }
    return V;  // Worst case
}

int main() {
    V = 4;  // number of vertices

    // Add edges
    graph[0].push_back(1);
    graph[1].push_back(0);

    graph[1].push_back(2);
    graph[2].push_back(1);

    graph[2].push_back(3);
    graph[3].push_back(2);

    graph[3].push_back(0);
    graph[0].push_back(3);

    int chromaticNumber = findChromaticNumber();
    cout << "Minimum number of colors needed: " << chromaticNumber << endl;

    return 0;
}
