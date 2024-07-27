#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> nextSmallerElement(vector<int> arr) {
    vector<int> solution(arr);
    stack<int> st;
    st.push(-1);

    for(int i=arr.size()-1; i>=0; i--) {
        int curr = arr[i];
        while(st.top() != -1 && arr[st.top()] >= curr) {
            st.pop();
        }

        solution[i] = st.top();
        st.push(i);
    }

    return solution;
}

vector<int> previousSmallerElement(vector<int> arr) {
    vector<int> solution(arr);
    stack<int> st;
    st.push(-1);

    for(int i=0; i<arr.size(); i++) {
        int curr = arr[i];
        while(st.top() != -1 && arr[st.top()] >= curr) {
            st.pop();
        }

        solution[i] = st.top();
        st.push(i);
    }

    return solution;
}
public:
    int largestRectangleArea(vector<int>& nums) {
       int n = nums.size();
    
    vector<int> next = nextSmallerElement(nums);
    vector<int> prev = previousSmallerElement(nums);

        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(next[i]==-1)next[i]=n;
            int l=i-prev[i];
            int r=next[i]-i-1;


            ans=max(ans,(l+r)*nums[i]);
        }

        return ans;
        
    }
};