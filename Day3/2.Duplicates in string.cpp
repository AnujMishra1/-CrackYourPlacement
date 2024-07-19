#include<bits/stdc++.h>
using namespace std;

vector<int>getDuplicates(string s)
{
    vector<int>ans;
    vector<int>mp(26,0);
    for(auto i:s)
    {
        mp[i-'a']++;
    }
    
    for(int i=0;i<26;i++)
    {
        if(mp[i]>1)
        {
            ans.push_back(char(i+'a'));
            cout<<char(i+'a')<<" ";
        }
    }
    return ans;
    
}