#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& nums) {
       int smax=0;
       int emax=0;

       int s=0;
       int e=nums.size()-1;
       int ans=0;
       while(s<e)
       {
            smax=max(smax,nums[s]);
            emax=max(emax,nums[e]);
            
            if(smax<emax)
            {
                ans+=(smax-nums[s++]);
            }
            else
            {
                ans+=(emax-nums[e--]);
            }
       }

       return ans;
        
    }
};