#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
  bool possible(int arr[],int student,int pages,int n)
  {
      int curr=1;
      int page=0;
      
      for(int i=0;i<n;i++)
      {
          if(page+arr[i]>pages)
          {
              curr++;
              page=arr[i];
              if(curr>student || arr[i]>pages)return false;
          }
          else
          {
              page+=arr[i];
          }
      }
      return curr<=student;
  }
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        if(m>n)return -1;
        int s=0;
        
        int e=0;
        
        for(int j=0;j<n;j++)
        {
            int i=arr[j];
            s=max(s,i);
            e+=i;
        }
        int ans=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(possible(arr,m,mid, n))
            {
                ans=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return ans;
    }
};