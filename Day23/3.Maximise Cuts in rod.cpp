#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(int n, int x, int y, int z, vector<int>& dp) {
        if (n == 0) return 0; // Base case: no more cuts needed
        if (n < 0) return INT_MIN; // Invalid case: not a valid cut

        if (dp[n] != -1) return dp[n]; // Check memoization

        // Recursively try all cuts and take the maximum
        int op1 = 1 + solve(n - x, x, y, z, dp);
        int op2 = 1 + solve(n - y, x, y, z, dp);
        int op3 = 1 + solve(n - z, x, y, z, dp);

        // Store the maximum result in dp array
        return dp[n] = max({op1, op2, op3});
    }

public:
    int maximizeTheCuts(int n, int x, int y, int z) {
        vector<int> dp(n + 1, -1); // Initialize dp array with -1
        int result = solve(n, x, y, z, dp);

        // If result is negative, it means no valid cuts can be made, so return 0
        return result < 0 ? 0 : result;
    }
};