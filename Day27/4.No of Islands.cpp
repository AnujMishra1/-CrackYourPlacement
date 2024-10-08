#include<bits/stdc++.h>
using namespace std;

class Solution {

    private:

    void solve(vector<vector<char>>&grid,int i,int j)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size())return;
        if(grid[i][j]=='0')return;

        grid[i][j]='0';

        solve(grid,i-1,j);
        solve(grid,i+1,j);
        solve(grid,i,j-1);
        solve(grid,i,j+1);
    }
public:

    int numIslands(vector<vector<char>>& grid) {

        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    ans++;
                    solve(grid,i,j);
                }
            }
        }
        return ans;
        
    }
};