#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool arraySortedOrNot(vector<int>& arr) {
        
        if(arr.size()==1)return true;
        
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]>=arr[i-1])continue;
            else return false;
        }
        return true;
    }
};