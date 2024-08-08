#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
        
        if (i >= grid.size() || j >= grid[0].size()) return INT_MAX;

        
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return grid[i][j];
        }

        
        if (dp[i][j] != -1) return dp[i][j];

        
        int down = solve(grid, i + 1, j, dp);
        int right = solve(grid, i, j + 1, dp);


        return dp[i][j] = grid[i][j] + min(down, right);
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return solve(grid, 0, 0, dp);
    }
};
