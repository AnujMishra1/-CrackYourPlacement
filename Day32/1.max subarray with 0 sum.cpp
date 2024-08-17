

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        unordered_map<int,int>mp;
        
        int sum=0;
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum==0)ans=max(ans,i+1);
            
            if(mp.find(sum)!=mp.end())
            {
                ans=max(ans,i-mp[sum]);
            }
            else mp[sum]=i;
        }
        return ans;
    }
};


