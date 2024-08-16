#include<bits/stdc++.h>
using namespace  std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        int prev=INT_MIN;
        int ans=0;
        for(auto i:nums)
        {
            int s=i[0];
            int e=i[1];
            if(s<prev)
            {
                ans++;
                prev=min(prev,e);
            }
            else
            {
                prev=e;
            }
        }

        return ans;
        
    }
};