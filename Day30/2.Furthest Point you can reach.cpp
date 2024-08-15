#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& nums, int bricks, int ladders) {

        priority_queue<int>pq;

       int i=0;
       int diff=0;

       for( i=0;i<nums.size()-1;i++)
       {
        diff=nums[i+1]-nums[i];

        if(diff<=0)continue;

        bricks=bricks-diff;
        pq.push(diff);

        if(bricks<0)
        {
            bricks+=pq.top();
            ladders--;
            pq.pop();
        }

        if(ladders<0)break;


       }
        return i;
    }
};