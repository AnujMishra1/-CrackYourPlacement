#include<bits/stdc++.h>
using namespace std;

class CustomCompare{
    public:
    bool operator()(pair<int,int>a,pair<int,int>b)
    {
        return a.first<b.first;
    }
};

class Solution {
public:



    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int>mp;

        for(auto i:nums)
        {
            mp[i]++;
        }

        

      priority_queue<pair<int,int>,vector<pair<int,int>>,CustomCompare>pq;
        for(auto i:mp)
        {
            pq.push({i.second,i.first});
        }

        int i=0;
        vector<int>ans;
        while(i<k)
        {
            auto f=pq.top();
            pq.pop();

            ans.push_back(f.second);
            i++;
        }
        return ans;



        
    }
};