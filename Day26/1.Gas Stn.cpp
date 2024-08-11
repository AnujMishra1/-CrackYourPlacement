#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int def=0;
        int petrol=0;
        int s=0;

        for(int i=0;i<gas.size();i++)
        {
            petrol+=gas[i]-cost[i];
            if(petrol<0)
            {   
                def+=petrol;
                petrol=0;
                s=i+1;
            }
           
        }
        cout<<petrol<<" "<<def<<" ";
        if(petrol+def>=0)return s;
        return -1;


        
    }
};