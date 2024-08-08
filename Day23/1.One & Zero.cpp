#include<bits/stdc++.h>
using namespace std;

class Solution {

    private:
    int solve(vector<pair<int,int>>&nums,int z,int o,int i,vector<vector<vector<int>>>&dp)
    {
        if(i>=nums.size())return 0;

        if(z<0 || o<0)return 0;
        if(dp[z][o][i]!=-1)return dp[z][o][i];
       
        //exclude
        int op1=solve(nums,z,o,i+1,dp);

        int op2=0;
         //include
         if(z>=nums[i].first && o>=nums[i].second)
        op2=1+solve(nums,z-nums[i].first,o-nums[i].second,i+1,dp);

        return dp[z][o][i]= max(op1,op2);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        
        vector<pair<int,int>>nums;

        for(auto i:strs)
        {
            int one=0;
            int zero=0;
            for(auto j:i)
            {
                if(j=='0')zero++;
                else one++;
            }
            nums.push_back({zero,one});
        }
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(nums.size(),-1)));
        return solve(nums,m,n,0,dp);
        
    }
};