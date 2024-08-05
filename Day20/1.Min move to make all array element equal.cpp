#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minMoves2(vector<int>& nums) {

       sort(nums.begin(),nums.end());

       int median;
        int n=nums.size();
       if(n%2==0)
       {
            median=(nums[n/2]+nums[(n/2)-1])/2;
       }
       else
       {
        median=nums[(n/2)];
       } 
        cout<<median<<" ";
       int ans=0;

       for(auto i:nums)
       {
        ans+=abs(i-median);
       }
       return ans;
    }
};