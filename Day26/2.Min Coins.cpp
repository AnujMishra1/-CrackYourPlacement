#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    
    int solve(vector<int>&nums,int remain)
    {
        if(remain==0)return 0;
        if(remain<0)return INT_MAX;
        
        int ans=INT_MAX;
        
        for(int j=0;j<nums.size();j++)
        {
            int op1=solve(nums,remain-nums[j]);
            if(op1!=INT_MAX)ans=min(ans,1+op1);
        }
        
        return ans;
    }
    
    
	public:
	int MinCoin(vector<int>nums, int amount)
	{
	    
	    int ans=solve(nums,amount);
	    
	    if(ans==INT_MAX)return -1;
	    
	    return ans;
	}
};