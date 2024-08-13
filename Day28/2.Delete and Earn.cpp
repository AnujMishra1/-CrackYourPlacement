#include<bits/stdc++.h>
using namespace std;

class Solution {

    private:
    int solve(vector<int>&nums,int i,vector<int>&dp)
    {
        if(i>=nums.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int sum=nums[i];
        int j=i+1;
        while(j<nums.size() && nums[j]==nums[i])
        {
            sum=sum+nums[j++];
        }
        while(j<nums.size() && nums[j]==nums[i]+1)j++;
        cout<<sum+solve(nums,j,dp)<<" "<<solve(nums,i+1,dp)<<endl;
        return dp[i]=max(sum+solve(nums,j,dp),solve(nums,i+1,dp));
    }


public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>dp(nums.size(),-1);
        return solve(nums,0,dp);        
    }
};