#include<bits/stdc++.h>
using namespace std;

class Solution {

    void solve(vector<int>&nums,int remain,vector<vector<int>>&ans,vector<int>output,int i)
    {
        if(remain==0)
        {
            ans.push_back(output);
            return;
        }
        if(remain<0)return;
        if(i>=nums.size())return ;

        for(int j=i;j<nums.size();j++)
        {
            if(j>i && nums[j]==nums[j-1])continue;
            output.push_back(nums[j]);
            solve(nums,remain-nums[j],ans,output,j+1);
            output.pop_back();
        }


    }
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        vector<vector<int>>ans;
        vector<int>output;

        solve(nums,target,ans,output,0);

        return ans;

        
    }
};