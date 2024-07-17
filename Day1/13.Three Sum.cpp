#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;

        for(int i=0;i<nums.size()-2;i++)
        {
            
                if(i>0 && nums[i]==nums[i-1])continue;
            

            int t=-nums[i];

            int s=i+1;
            int e=nums.size()-1;
            while(s<e)
            {
                int sum=nums[s]+nums[e];

                if(sum==t)
                {
                    ans.push_back({nums[i],nums[s],nums[e]});

                    while(s<e && nums[s]==nums[s+1])s++;
                    while(s<e && nums[e]==nums[e-1])e--;

                    s++;
                    e--;
                    
                }
                else if(sum<t)
                {
                    s++;
                }
                else
                {
                    e--;
                }
            }
        }
        return ans;
        
    }
};