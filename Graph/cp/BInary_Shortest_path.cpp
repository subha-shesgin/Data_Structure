#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Step 1: If start or end is blocked, no path is possible
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
            return -1;

        // Step 2: Define all 8 directions (right, down, left, up, and 4 diagonals)
        vector<pair<int, int>> directions = {
            {0, 1}, {1, 0}, {-1, 0}, {0, -1},
            {1, 1}, {-1, -1}, {-1, 1}, {1, -1}
        };

        // Step 3: BFS using queue
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1; // Mark starting cell with path length 1

        // Step 4: BFS traversal
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            int dist = grid[x][y];

            // If we reached the bottom-right cell
            if (x == n - 1 && y == n - 1)
                return dist;

            // Explore all 8 directions
            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;

                // Check bounds and whether the cell is unvisited (0)
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0) {
                    q.push({nx, ny});
                    grid[nx][ny] = dist + 1; // Update distance and mark visited
                }
            }
        }

        // If no path found
        return -1;
    }
};

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0},
        {1, 1, 0},
        {1, 1, 0}
    };

    Solution sol;
    int result = sol.shortestPathBinaryMatrix(grid);

    cout << "Shortest path length: " << result << endl;

    return 0;
}
