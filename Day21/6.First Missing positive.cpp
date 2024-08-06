#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool onePresent=false;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)onePresent=true;
            if(nums[i]<=0 || nums[i]>nums.size())nums[i]=1; 
        }
        if(!onePresent)return 1;

        for(int i=0;i<nums.size();i++)
        {
            int a=abs(nums[i]);

            if(nums[a-1]>0)nums[a-1]=-nums[a-1];
        }

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)return i+1;
        }
        return nums.size()+1;
        
    }
};