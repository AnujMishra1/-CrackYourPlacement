#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:

    bool isPalindrome(string s)
    {
        int i=0;
        int j=s.size()-1;
        while(i<j)
        {
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }

    void solve(string s,vector<vector<string>>&ans,vector<string>&output,int i)
    {
        if(i>=s.size())
        {
            ans.push_back(output);
            return;
        }


        for(int j=1;j<s.size()-i+1;j++)
        {
            if(isPalindrome(s.substr(i,j)))
            {
                output.push_back(s.substr(i,j));
                solve(s,ans,output,j+i);
                output.pop_back();
            }
        }

        
    }
public:
    vector<vector<string>> partition(string s) {

        vector<vector<string>>ans;

        vector<string>output;


        solve(s,ans,output,0);
        return ans;
    }
};