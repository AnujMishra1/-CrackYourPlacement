#include<bits/stdc++.h>
using namespace std;

class Solution {
    int CountOneBits(int n)
    {
        
        int oneCount=0;

        
        while(n!=0)
        {
            
            if(n%2==1)oneCount++;
            
            n=n/2;
        }
        return oneCount;
    }
public:
    vector<int> countBits(int n) {
        
        vector<int>ans;

        
        for(int i=0;i<=n;i++)
        {
           
            ans.push_back(CountOneBits(i));
        }

       
        return ans;
        
    }
};