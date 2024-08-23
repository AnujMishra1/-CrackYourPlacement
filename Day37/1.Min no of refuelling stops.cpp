#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minRefuelStops(int target, int s, vector<vector<int>>& nums) {

        nums.push_back({target,0});
        priority_queue<int>pq;

        int ans=0;

        for(auto i:nums)
        {
            int pos=i[0];
            int petrol=i[1];
            if(pos>s)
            {
                while(pos>s && !pq.empty())
                {
                    s+=pq.top();
                    pq.pop();
                    ans++;
                }
            }

            if(pos>s)return -1;
            pq.push(petrol);
        }
        return ans;
        
    }
};