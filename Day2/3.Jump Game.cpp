#include<bits/stdc++.h>
using namespace std;

//jump game 
class Solution {
public:
    bool canJump(vector<int>& nums) {

        int goal=nums.size()-1;

        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]+i>=goal)
            {
                goal=i;
            }
        }
        return goal==0;
        
    }
};

//jump game-ii
class Solution {
public:
    int jump(vector<int>& nums) {
           if(nums.size()==1)return 0;

        int ans=0;

        for(int i=0;i<nums.size();)
        {
            int j=i+nums[i];
            if(j>=nums.size()-1)return ans+1;
            int maxi=INT_MIN;


            for(int k=i+1;k<=j;k++)
            {
                if(maxi<k+nums[k])
                {
                    i=k;
                    maxi=k+nums[k];
                }
            }
            ans++;
        }
        return ans;
        
    }
};