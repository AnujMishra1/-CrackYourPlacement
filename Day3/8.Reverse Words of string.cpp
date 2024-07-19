#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {

        stack<char>st;

        for(auto i:s)
        {
            st.push(i);
        }

        string ans="";

        while(!st.empty())
        {
            if(st.top()==' ')
            {
                st.pop();
            }
            else
            {
                 string word;
                while(!st.empty() && st.top()!=' ')
                {
                   
                    word.push_back(st.top());
                    st.pop();
                    
                }
                
                    reverse(word.begin(),word.end());
                    cout<<word<<endl;
                    ans=ans+word+' ';
            }
        }
        ans.pop_back();
        return ans;        
    }
};