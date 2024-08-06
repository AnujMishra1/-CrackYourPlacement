#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isPossible(int k, vector<int>& arr1, vector<int>& arr2) {
        // Sort arr1 in ascending order and arr2 in descending order
        
        if(arr1.size()!=arr2.size())return false;
        sort(arr1.begin(), arr1.end());
        sort(arr2.rbegin(), arr2.rend());

        int n = arr1.size();

        // Use two pointers to check the pairs
        for (int i = 0; i < n; ++i) {
            // Check if the sum of the current pair is at least k
            if (arr1[i] + arr2[i] < k) {
                return false;
            }
        }

        // If all pairs meet the condition, return true
        return true;
    }
};