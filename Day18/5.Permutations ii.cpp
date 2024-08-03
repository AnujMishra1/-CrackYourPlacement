
#include<bits/stdc++.h>
using namespace std;

class Solution {
vector<vector<int>>ans;
    void solve(vector<int>nums,int i)
    {
       if(i==nums.size())
       {
        ans.push_back(nums);
        return;
       }

       for(int j=i;j<nums.size();j++)
       {
        if(i==j || nums[i]!=nums[j]){
        swap(nums[i],nums[j]);
        solve(nums,i+1);
        }
        
       }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         

         sort(nums.begin(),nums.end());

        solve(nums,0);

        return ans;
        
    }
};


