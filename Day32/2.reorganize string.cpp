#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {

      unordered_map<char,int>mp;

      for(auto i:s)mp[i]++;

      priority_queue<pair<int,char>>pq;

      for(auto i:mp)
      {
        pq.push({i.second,i.first});
      }

      string ans;
      pair<int,char>prev={-1,'#'};

      while(!pq.empty())
      {
            auto f=pq.top();
            pq.pop();

            ans+=f.second;

            if(prev.first>0)
            {
                pq.push(prev);
            }

            f.first--;
            prev=f;
      }
    if(ans.size()!=s.size())return "";
      return ans;



        
    }
};