#include<bits/stdc++.h>
using namespace std;

class Solution {

int solve(string s,int i)
{
    if(i>=s.size())
    {
        return 1;
    }
    else if(s[i]=='0')return 0;
    else if(i==s.size()-1)return 1;
    else if(s[i]=='1' ||(s[i]=='2' &&( s[i+1]>='0' && s[i+1]<='6')))
    {
        return solve(s,i+1)+solve(s,i+2);
    }
    else
    {
        return solve(s,i+1);
    }
}

int solve1(string s, int i, vector<int>& dp) {
    if (i >= s.size()) {
        return 1;
    } else if (s[i] == '0') {
        return 0;
    } else if (i == s.size() - 1) {
        return 1;
    }
    if (dp[i] != -1) {
        return dp[i];
    }
    int ans;
    if (s[i] == '1' || (s[i] == '2' && (s[i + 1] >= '0' && s[i + 1] <= '6'))) {
        ans = solve1(s, i + 1, dp) + solve1(s, i + 2, dp);
    } else {
        ans = solve1(s, i + 1, dp);
    }
    dp[i] = ans;
    return dp[i];
}


    int numDecodings(string s) {
        // return solve(s,0);
        vector<int >dp(s.size(),-1);
        return solve1(s,0,dp);
        
    }
};