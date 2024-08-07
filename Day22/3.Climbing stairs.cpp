#include<bits/stdc++.h>
using namespace std;

class Solution {

    int solve(int  n)
    {
        if(n==2 || n==1)return n;

        return solve(n-1)+solve(n-2);
    }

    int solve1(int  n,vector<int>&dp)
    {
        if(n==2 || n==1)return n;

        if(dp[n]!=-1)return dp[n];

        return  dp[n]=solve1(n-1,dp)+solve1(n-2,dp);
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return solve1(n,dp);
        
    }
};