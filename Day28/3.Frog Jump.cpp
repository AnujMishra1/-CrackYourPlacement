#include<bits/stdc++.h>
using namespace std;
class Solution {

    private:

    bool solve(vector<int>&nums,int i,int jump,vector<vector<int>>&dp)
    {
        if(i==nums.size()-1)
        {
            return true;
        }
        if(i>=nums.size())
        {
            return false;
        }
        if(dp[i][jump]!=-1)return dp[i][jump];
        bool ans;
        int next=-1;
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[j]==nums[i]+jump)
            {
                next=j;
                break;
            }
        }
        if(next==-1)return dp[i][jump]= false;
        else
        {
             ans=(solve(nums,next,jump,dp) || solve(nums,next,jump-1,dp)|| solve(nums,next,jump+1,dp));
        }
        
        return  dp[i][jump]= ans;
    }
public:
    bool canCross(vector<int>& stones) {
        vector<vector<int>>dp(stones.size(),vector<int>(stones.size(),-1));
        return solve(stones,0,1,dp);
        
    }
};