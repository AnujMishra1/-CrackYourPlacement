#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i=m-1;
        int j=n-1;
        int k=m+n-1;

        while(i>=0 && j>=0)
        {
            if(nums1[i]>nums2[j])
            {
                swap(nums1[k--],nums1[i--]);
            }
            else
            {
                swap(nums2[j--],nums1[k--]);
            }
        }

        while(j>=0)
        {
            swap(nums2[j--],nums1[k--]);
        }
        
    }
};