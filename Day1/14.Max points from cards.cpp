#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& nums, int k) {

        //approach bahot easy hai just find a subaaray of size nums.size()-k
        // with min sum aur fir total sum-min sum will be your ans

        int mini=INT_MAX;
        int sum=0;
        int t=0;

        int right=0;
        int left=0;

        for(right;right<nums.size();right++)
        {
            t+=nums[right];
            sum+=nums[right];
            if(right-left+1==nums.size()-k)
            {
                cout<<"h";
                mini=min(mini,sum);
                sum-=nums[left++];
            }
        }
        if(left==0)return t;

        return t-mini;
       
        
    }
};