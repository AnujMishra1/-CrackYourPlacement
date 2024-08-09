#include<bits/stdc++.h>
using namespace std;

class Solution {

    int solve(vector<int>&nums,int remain,vector<int>&dp)
    {
        
        if(remain<0)return INT_MAX;
        if(remain==0)return 0;
        if(dp[remain]!=-1)return dp[remain];
        int op1=INT_MAX;
        for(int j=0;j<nums.size();j++)
        {
            int temp=solve(nums,remain-nums[j],dp);

            if(temp!=INT_MAX)op1=min(op1,1+temp);
        }
        return dp[remain]=op1;
    }
public:
    int coinChange(vector<int>& coins, int amount) {


        vector<int>dp(amount+1,-1);
        int ans= solve(coins,amount,dp);

        if(ans==INT_MAX)return -1;
        return ans;
        
    }
};