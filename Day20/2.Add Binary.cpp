#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {

        string ans;

        int i=a.size()-1;
        int j=b.size()-1;
        int carry=0;
        

        while(i>=0 && j>=0)
        {
            int cnt=0;
            if(a[i]=='1')cnt++;
            if(b[j]=='1')cnt++;
            if(carry==1)cnt++;
            cout<<cnt<<" ";

            if(cnt==0)
            {
                ans.push_back('0');
                carry=0;
            }
            else if(cnt==1)
            {
                ans.push_back('1');
                carry=0;
            }
            else if(cnt==2)
            {
                ans.push_back('0');
                carry=1;
            }
            else{
                ans.push_back('1');
                carry=1;
            }
            i--;
            j--;
        }
//  cout<<ans<<" ";
        while(i>=0)
        {
             int cnt=0;
            if(a[i]=='1')cnt++;
            if(carry==1)cnt++;
             if(cnt==0)
            {
                ans.push_back('0');
                carry=0;
            }
            else if(cnt==1)
            {
                ans.push_back('1');
                carry=0;
            }
              else{
                ans.push_back('0');
                carry=1;
            }
            i--;

        }
       

        while(j>=0)
        {
             int cnt=0;
            if(b[j]=='1')cnt++;
            if(carry==1)cnt++;
             if(cnt==0)
            {
                ans.push_back('0');
                carry=0;
            }
            else if(cnt==1)
            {
                ans.push_back('1');
                carry=0;
            }
              else{
                ans.push_back('0');
                carry=1;
            }
            j--;

        }

        if(carry)
        {
            ans.push_back('1');
        }

        reverse(ans.begin(),ans.end());

        return ans;
        
    }
};