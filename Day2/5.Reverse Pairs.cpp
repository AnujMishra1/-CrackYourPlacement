#include<bits/stdc++.h>
using namespace std;

class Solution {
    void getAns(vector<int>&arr,int s,int mid,int e,int &ans)
    {
         

         int len1 = mid - s + 1;
         int len2 = e - mid;

            int *first = new int[len1];
            int *second = new int[len2];

            int mainArrayIndex = s;
    for(int i=0; i<len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    
    for(int i=0; i<len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }
       int j=0;
    for(int i=0;i<len1;i++)
    {
        while(j < len2 && first[i] > 2*(long long)second[j]) j++;

        ans+=j;
    }


    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }   

    while(index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2 ) {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete []first;
    delete []second;
    }
    private:
    void solve(vector<int>&nums,int s,int e,int &ans)
    {
        if(s>=e)return;

        int mid=s+(e-s)/2;
         solve(nums,s,mid,ans);
         solve(nums,mid+1,e,ans);

         getAns(nums,s,mid,e,ans);

    }
public:
    int reversePairs(vector<int>& nums) {
            int ans=0;
          solve(nums,0,nums.size()-1, ans);
          return ans;
    }
};