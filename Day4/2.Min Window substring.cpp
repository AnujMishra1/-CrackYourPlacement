#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char,int>mp,window;

        for(auto i:t)
        {
            mp[i]++;
        }

        int toCreate=mp.size();
        // string ans;
        int size=INT_MAX;
        int left=0;
        int created=0;
        int start=-1;

        for(int right=0;right<s.size();right++)
        {
            if(mp.find(s[right])!=mp.end())
            {
                window[s[right]]++;
                if(mp[s[right]]==window[s[right]])created++;
            }

               
                while(created==toCreate)
                {
                     
                     if(size>right-left+1)
                        {
                            size=right-left+1;
                            start=left;
                        }

                    if(mp.find(s[left])!=mp.end())
                    {
                        window[s[left]]--;
                        if(window[s[left]]<mp[s[left]])created--;
                    }
                    left++;
                }
            }
        if(start==-1)return "";
        return s.substr(start,size);
        
    }
};

       