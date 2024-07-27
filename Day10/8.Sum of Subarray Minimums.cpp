#include<bits/stdc++.h>
using namespace std;

class Solution {

     int mod = 1e9 + 7;

    void nextSmaller(vector<int>& arr, int n, vector<int>& t) {
        stack<int> st;
        int i = n - 1;
        while (i >= 0) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                t[i] = n;
            } else {
                t[i] = st.top();
            }
            st.push(i);
            i--;
        }
    }

    void prevSmaller(vector<int>& arr, int n, vector<int>& t) {
        stack<int> st;
        int i = 0;
        while (i < n) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                t[i] = -1;
            } else {
                t[i] = st.top();
            }
            st.push(i);
            i++;
        }
    }


public:
    int sumSubarrayMins(vector<int>& arr) {

        vector<int>prev(arr.size(),0);
        vector<int>next(arr.size(),0);

        prevSmaller(arr,arr.size(),prev);
        nextSmaller(arr,arr.size(),next);

        int ans=0;

        for(auto i:prev)
        {
            cout<<i<<" ";
        }
        cout<<endl;

        for(auto j:next)
        {
            cout<<j<<" ";
        }

        for(int i=0;i<arr.size();i++)
        {
            
            long long  temp=(i-prev[i])*(next[i]-i);

            
            temp=temp%mod;
            temp=(temp*arr[i])%mod;
            ans=(ans+temp)%mod;

        }
        return ans;
        
    }
};