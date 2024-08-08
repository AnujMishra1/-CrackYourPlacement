#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int mod = 1e9 + 7;

    int solve(vector<vector<int>>& nums, int i, int j, int n, vector<vector<vector<int>>>& dp) {
        if (i < 0 || i >= 4 || j < 0 || j >= 3) return 0;
        if (nums[i][j] == -1) return 0;
        if (n == 1) return 1;

        if (dp[i][j][n] != -1) return dp[i][j][n];

        // Recursive calls to explore all 8 possible knight moves
        int op1 = solve(nums, i - 2, j - 1, n - 1, dp);
        int op2 = solve(nums, i - 2, j + 1, n - 1, dp);
        int op3 = solve(nums, i - 1, j - 2, n - 1, dp);
        int op4 = solve(nums, i + 1, j - 2, n - 1, dp);
        int op5 = solve(nums, i - 1, j + 2, n - 1, dp);
        int op6 = solve(nums, i + 1, j + 2, n - 1, dp);
        int op7 = solve(nums, i + 2, j - 1, n - 1, dp);
        int op8 = solve(nums, i + 2, j + 1, n - 1, dp);

        // Apply modulo at each step to avoid overflow
        return dp[i][j][n] = ((((((((op1 + op2) % mod + op3) % mod + op4) % mod + op5) % mod + op6) % mod + op7) % mod + op8) % mod);
    }

public:
    int knightDialer(int n) {
        vector<vector<int>> nums(4, vector<int>(3, -1));
        int curr = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = 0; j < nums[0].size(); j++) {
                nums[i][j] = curr++;
            }
        }

        vector<vector<vector<int>>> dp(4, vector<vector<int>>(3, vector<int>(n + 1, -1)));
        nums[3][1] = 0;
        int ans = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if (nums[i][j] != -1) {   
                    ans = (ans + solve(nums, i, j, n, dp)) % mod;
                }
            }
        }

        return ans;
    }
};
