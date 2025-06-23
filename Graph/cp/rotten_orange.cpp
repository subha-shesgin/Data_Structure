// https://leetcode.com/problems/rotting-oranges/description/
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        // Function to find minimum time required to rot all oranges
        int oranges_Rotting(vector<vector<int>> & grid){
            int n = grid.size();   // row size
            int m = grid[0].size();// column size
            // {{r, c}, t}
            queue<pair<pair<int, int>, int>> q;
            int vis[n][m];
            int countFresh = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(grid[i][j] == 2){
                        q.push({{i, j}, 0});
                        vis[i][j] = 2;
                    }else{
                        vis[i][j] = 0;
                    }
                    if(grid[i][j] == 1){
                        countFresh++;
                    }
                }
            }
            int time = 0;
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};
            int count = 0;
            while(!q.empty()){
                int r = q.front().first.first;  // q.front() returns ((r, c), t)-> .first.first = r
                int c = q.front().first.second; // .first.second = c
                int t = q.front().second;       // .second = t
                time = max(time, t);
                q.pop();

                for(int i = 0; i < 4; i++){
                    int nrow = r + drow[i];
                    int ncol = c  + dcol[i];
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1 ){
                        q.push({{nrow, ncol}, t + 1});
                        vis[nrow][ncol] = 2;
                        count++;
                    }
                }
               
            }
            if(count != countFresh){
                return -1;
               }
            return time;
        }
};

int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    Solution sol;
    int result = sol.oranges_Rotting(grid);

    cout << "Minimum time to rot all oranges: " << result << endl;

    return 0;
}