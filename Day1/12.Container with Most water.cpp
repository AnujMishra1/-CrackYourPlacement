#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {

        int s=0;
        int e=height.size()-1;

        int ans=0;

        while(s<e)
        {
            int l=e-s;
            int h=min(height[s],height[e]);
            ans=max(ans,l*h);

            if(height[s]<height[e])
            {
                s++;
            }
            else
            {
                e--;
            }
        }
        return ans;
        
    }
};