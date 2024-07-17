#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        unordered_map<int,int>mp;   
        int ans=0;
        int sum=0;
        mp[0]++;

        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];

            int rem=sum%k;
            if(rem<0)rem+=k;
            
            if(mp.find(rem)!=mp.end())
            {
                ans+=mp[rem];
            }
            mp[rem]++;
        }
        return ans;
        
    }
};