#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map<char,int>mp;
        int left=0;
        int popular=-1;
        int ans=INT_MIN;
        for(int right=0;right<s.size();right++)
        {
            mp[s[right]]++;
            popular=max(popular,mp[s[right]]);

            if(popular+k<right-left+1)
            { 
                         
                    mp[s[left]]--;
                    left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
        
    }
};