#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        vector<int>t;
        t.push_back(nums[0]);

        for(int i=1;i<n;i++)
        {
            if(nums[i]>t.back())
            {
                t.push_back(nums[i]);
            }
            else
            {
                int index=lower_bound(t.begin(),t.end(),nums[i])-t.begin();
                t[index]=nums[i];
            }
        }

        // for(auto i:t)cout<<i<<" ";
        return t.size();
        
    }
};