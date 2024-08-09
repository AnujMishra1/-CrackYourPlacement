#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    
    bool solve(int arr[],int target,int i,int n,vector<vector<int>>&dp)
    {
        if(target<0)return false;
        if(target==0)return true;
        if(i>=n)return false;
        if(dp[target][i]!=-1)return dp[target][i];
        bool inc=solve(arr,target-arr[i],i+1,n,dp);
        bool exc=solve(arr,target,i+1,n,dp);
        
        return dp[target][i]=(inc || exc);
    }
public:
    int equalPartition(int N, int arr[])
    {
        int sum=0;
       for(int i=0;i<N;i++)
       {
           sum+=arr[i];
       }
       if(sum%2!=0)return 0;
       vector<vector<int>>dp((sum/2)+1,vector<int>(N,-1));
       return solve(arr,sum/2,0,N,dp);
    }
};