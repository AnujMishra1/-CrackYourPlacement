#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool possible(int target, vector<int>& nums, int k) {
        int count = 1; // At least one subarray is needed
        int current_sum = 0;
        
        for (int num : nums) {
            if (current_sum + num > target) {
                // Create a new subarray
                count++;
                current_sum = num;
                if (count > k) {
                    return false;
                }
            } else {
                current_sum += num;
            }
        }
        return true;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int max_element = 0;
        int sum = 0;

        for (int num : nums) {
            sum += num;
            max_element = max(max_element, num);
        }

        int left = max_element;
        int right = sum;
        int ans = sum;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (possible(mid, nums, k)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
