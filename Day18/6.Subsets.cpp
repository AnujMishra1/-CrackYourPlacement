#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void solve(vector<int>&nums,int i,vector<int>&output,vector<vector<int>>& ans)
    {
        if(i>=nums.size())
        {
            ans.push_back(output);
            return;
        }

        //include
        output.push_back(nums[i]);
        solve(nums,i+1,output,ans);
        output.pop_back();

        //exclude
        solve(nums,i+1,output,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int>output;
        vector<vector<int>>ans;

        solve(nums,0,output,ans);
        return ans;
        
    }
};