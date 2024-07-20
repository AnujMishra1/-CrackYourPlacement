#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {

        unordered_map<string,vector<string>>mp;

        for(auto i:s)
        {
            string temp=i;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(i);
        }

        vector<vector<string>>ans;

        for(auto i:mp)
        {
            ans.push_back(i.second);
        }
        return ans;
        
    }
};