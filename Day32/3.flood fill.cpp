#include<bits/stdc++.h>
using namespace std;

class Solution {

    void solve(vector<vector<int>>&image,int i,int j,int color,int curr)
    {
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size())return;
        if(image[i][j]!=curr)return;


        image[i][j]=color;

        solve(image,i-1,j,color,curr);
        solve(image,i+1,j,color,curr);
        solve(image,i,j-1,color,curr);
        solve(image,i,j+1,color,curr);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color)return image;
        solve(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};