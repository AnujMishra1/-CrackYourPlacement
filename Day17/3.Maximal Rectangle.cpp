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

     int largestRectangleArea(vector<int>& height) {
        int n = height.size();
    int maxArea = 0;
    vector<int> next = nextSmallerElement(height);
    vector<int> prev = previousSmallerElement(height);

    for(int i=0; i<n; i++) {
        if(next[i] == -1) {
            next[i] = n;
        }

        int length = height[i];
        int breadth = next[i] - prev[i] - 1; 

        int newArea = length * breadth;
        maxArea = max(newArea, maxArea);
    }

    return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        vector<int>t(matrix[0].size(),0);
        int ans=0;

        for(int i=0;i<matrix.size();i++)  
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]=='1')
                t[j]+=1;
                else
                {
                    t[j]=0;
                }
            }
            ans=max(ans,largestRectangleArea(t));

        }
        return ans;


        
    }
};