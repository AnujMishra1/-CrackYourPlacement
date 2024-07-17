#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        vector<int>ans;

        for(int i=0;i<nums.size();i++)
        {
            int a=abs(nums[i]);

            if(nums[a-1]<0)
            {
                ans.push_back(a);
            }
            else
            {
                nums[a-1]=-nums[a-1];
            }
        }
        return ans;
        
    }
};