#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        vector<long long int>ans(n);
        long long int t=1;
        for(int i=0;i<nums.size();i++)
        {
            t=nums[i]*t;
            ans[i]=t;
        }
        
         t=1;
        for(int i=n-1;i>0;i--)
        {
            ans[i]=ans[i-1]*t;
            t=t*nums[i];
            
        }
        ans[0]=t;
        
        return ans;
    }
};