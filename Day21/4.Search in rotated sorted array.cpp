#include<bits/stdc++.h>
using namespace std;
class Solution {

    int getPivot(vector<int>&nums)
    {
        int s=0;
        int e=nums.size()-1;

        while(s<e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]>=nums[0])s=mid+1;
            else e=mid;
        }

        return s;
    }

    int binarySearch(vector<int>& nums,int s,int e,int target)
    {int mid=s+(e-s)/2;
        while(s<=e)
        {
if(nums[mid]==target)
{
    return mid;
}
if(nums[mid]<target)
{
    s=mid+1;
}
else
{
    e=mid-1;
}
mid=s+(e-s)/2;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {

        int pivot=getPivot(nums);

       if(target>=nums[pivot]&&target<=nums[nums.size()-1])
{
    return binarySearch(nums,pivot,nums.size()-1,target);
}
else
{
   return binarySearch(nums,0,pivot-1,target); 
}
        
    }
};