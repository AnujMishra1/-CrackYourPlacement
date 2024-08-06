#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findPair(int n, int x, vector<int> &nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=1;
        while(i<n && j<n){
            if(i!=j && nums[j]-nums[i]==x) return 1;
            else if(nums[j]-nums[i]>x) i++;
            else j++;
        }
        return -1;
    }
};

