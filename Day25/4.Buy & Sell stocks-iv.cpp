#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:

    int solve(int k,vector<int>&prices,int i,int buy,vector<vector<vector<int>>>&dp)
    {
        if(k==0)return 0;
        if(i>=prices.size())return 0;
        if(dp[k][i][buy]!=-1)return dp[k][i][buy];
        int op1=0;
        
        
        if(buy==1)
        {
            op1=max(-prices[i]+solve(k,prices,i+1,0,dp),solve(k,prices,i+1,buy,dp));
        }
        else
        {
            op1=max(prices[i]+solve(k-1,prices,i+1,1,dp),solve(k,prices,i+1,buy,dp));
        }

        return dp[k][i][buy]=op1;
    }
public:
    int maxProfit(int k, vector<int>& prices) {

        vector<vector<vector<int>>>dp(k+1,vector<vector<int>>(prices.size(),vector<int>(2,-1)));
        
        return solve(k,prices,0,1,dp);
        
    }
};