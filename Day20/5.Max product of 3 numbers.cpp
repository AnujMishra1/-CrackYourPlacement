#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // only 2 options
        // 1. product of last 3 
        // 2. product of first 2 and last
        sort(nums.begin(),nums.end());

        int i=0;
        int j=nums.size()-1;
        int ans=1;
        
        int op1=nums[i]*nums[i+1]*nums[j];
        int op2=nums[j]*nums[j-1]*nums[j-2];
        return max(op1,op2);
       

        
    }
};