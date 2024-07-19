#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool solve(string s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        
        bool check=false;
        int i=0;
        int j=s.size()-1;

        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
            {
                return (solve(s,i,j-1) || solve(s,i+1,j));
                
            }
        }

        return true;

    }
};