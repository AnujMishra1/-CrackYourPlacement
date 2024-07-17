#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int i=0;
        
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j]==0)
            {
                swap(nums[i++],nums[j]);
            }
        }

        for(int j=i;j<nums.size();j++)
        {
            if(nums[j]==1)
            {
                swap(nums[i++],nums[j]);
            }
        }
        
    }
};
