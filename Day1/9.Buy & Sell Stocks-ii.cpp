#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int temp=prices[0];
        int ans=0;

        for(int i=0;i<prices.size();i++)
        {
            temp=min(temp,prices[i]);

            if(prices[i]>temp)
            {
                ans+=(prices[i]-temp);
                temp=prices[i];
            }
        }
        return ans;
        
    }
};