#include<bits/stdc++.h>
using namespace std;
//Two approaches Available

// 1. Fast & slow pointer
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow=nums[0];
        int fast=nums[0];

        while(true)
        {
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(slow==fast)break;
        }

        slow=nums[0];

        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }

        return slow;
    }
};

// 2.Modifying the array
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        for(int i=0;i<nums.size();i++)
        {
            int a=abs(nums[i]);

            if(nums[a]<0)return a;
            else
            {
                nums[a]=-nums[a];
            }

        }
        return -1;
    }
};