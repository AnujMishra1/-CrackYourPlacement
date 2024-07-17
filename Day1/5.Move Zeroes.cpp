#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //s->keeps track of most previous zero where a number should be added
        //e->keeps track of number not equal to zero
        int s=0;
        int e=0;

        while(e<nums.size())
        {
            if(nums[e]!=0)
            {
                swap(nums[s++],nums[e++]);
            }
            else
            {
                e++;
            }
        }
        
    }
};