#include<bits/stdc++.h>
using namespace std;

class Solution {

    void solve(vector<vector<int>>&ans,vector<int>&output,vector<int>nums,int i)
    {
     
            ans.push_back(output);
        

        //include
        
        for(int j=i;j<nums.size();j++)
        {
            if(j>i && nums[j]==nums[j-1])continue;

            output.push_back(nums[j]);
            solve(ans,output,nums,j+1);
            output.pop_back();
        }
        
        
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         vector<vector<int>>ans;
         vector<int>output;
         sort(nums.begin(),nums.end());

         solve(ans,output,nums,0);
         return ans;
    }
};