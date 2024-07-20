#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(string &s,string &t,int i,int j,vector<vector<int>>&dp)
    {
        if(i>=s.size() && j>=t.size())
        {
            return 1;
        }
        if(j>=t.size())return 1;
        if(i>=s.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];

        int op1=0;
        if(s[i]==t[j])
        {
            op1=solve(s,t,i+1,j+1,dp);
        }
        int op2=solve(s,t,i+1,j,dp);

        return dp[i][j]=op1+op2;
    }
public:
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));
        return solve(s,t,0,0,dp);
        
    }
};