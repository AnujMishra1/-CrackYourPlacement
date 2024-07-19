#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {

        if(s.size()==0)return "";
        if(s.size()==1)return s[0];

        sort(s.begin(),s.end());

        string a=s[0];
        string b=s[s.size()-1];

        int i=0;
        int j=0;
        string ans="";

        while(i<a.size()  &&  j<b.size())
        {
            if(a[i]==b[j])
            {
                ans.push_back(a[i]);
                i++;
                j++;
            }
            else
            {
                break;
            }
        }
        return ans;
        
    }
};