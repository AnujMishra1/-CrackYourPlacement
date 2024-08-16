#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> mp;
        
       
        for (auto& pair : nums) {
            int u = pair[0];
            int v = pair[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        
       
        int curr = -1;
        for (auto& entry : mp) {
            if (entry.second.size() == 1) { 
                curr = entry.first;
                break;
            }
        }
        
        vector<int> ans;
        ans.push_back(curr);
        int prev = -1;
        
        
        while (ans.size() < nums.size() + 1) {
            for (int neighbor : mp[curr]) {
                if (neighbor != prev) {
                    ans.push_back(neighbor);
                    prev = curr;
                    curr = neighbor;
                    break;
                }
            }
        }
        
        return ans;
    }
};
