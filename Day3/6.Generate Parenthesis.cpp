#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void solve(int open,int close,vector<string>&ans,string &output)
    {
        if(open<0 || close<0)return;
        if(open==0 && close==0)
        {
            ans.push_back(output);
            return;
        }

        output.push_back('(');
        solve(open-1,close,ans,output);
        output.pop_back();

        if(close>open)
        {
            output.push_back(')');
            solve(open,close-1,ans,output);
            output.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {

        vector<string>ans;
        string output="";

        solve(n,n,ans,output);
        return ans;
        
    }
};