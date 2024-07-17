#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

     vector<int> ans;
     int row=matrix.size();
     int col=matrix[0].size();

     int count =0;
     int n=row*col;

     int startingrow=0;
     int startingcol=0;
     int endingrow=row-1;
     int endingcol=col-1;

    while(count<n)
    {
        for(int i=startingcol;i<=endingcol && count<n;i++)
        {
            ans.push_back(matrix[startingrow][i]);
            count++;
        }
        startingrow++;

        for(int i=startingrow;i<=endingrow && count<n;i++)
        {
            ans.push_back(matrix[i][endingcol]);
            count++;
        }
        endingcol--;

        for(int i=endingcol;i>=startingcol && count<n;i--)
        {
            ans.push_back(matrix[endingrow][i]);
            count++;
        }
        endingrow--;

        for(int i=endingrow;i>=startingrow && count<n;i--)
        {
            ans.push_back(matrix[i][startingcol]);
            count++;
        }
        startingcol++;
    }
    return ans;


    }
    
};