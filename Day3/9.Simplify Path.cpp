#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void get(stack<string>s,string &ans)
    {
        if(s.empty())return;

        string t=s.top();
        s.pop();
        get(s,ans);
        ans+=t;
    }
public:
    string simplifyPath(string path) {

        stack<string>s;

       int i=0;
       while(i<path.size())
        {
          
          int j=i+1;

          while(j<path.size() && path[j]!='/')
          {
            ++j;
          }
          string temp=path.substr(i,j-i);
          i=j;
          if(temp=="/" || temp=="/.")continue;
          else if(temp!="/..")s.push(temp);
          else if(!s.empty())s.pop();
        }

        string ans;
        if(s.empty())return "/";

        get(s,ans);

        return ans;
        
    }
};