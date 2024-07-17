#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int i=0;
       for(int j=0;j<nums.size()-1;j++)
       {
        if(nums[j]!=nums[j+1])
        {
            nums[i++]=nums[j];
        }
       }

       nums[i++]=nums[nums.size()-1];
       return i;   
    }
};