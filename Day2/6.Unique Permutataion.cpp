#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void solve(vector<int>&nums,int i,vector<vector<int>>&ans)
    {
        if(i>=nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for(int j=i;j<nums.size();j++)
        {
            if(i!=j && nums[i]==nums[j])continue;
            swap(nums[i],nums[j]);
            solve(nums,i+1,ans);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &nums ,int n) {
        // code here
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;

        solve(nums,0,ans);

        return ans;
    }
};