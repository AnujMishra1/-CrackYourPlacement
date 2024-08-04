#include<bits/stdc++.h>
using namespace std;

class Solution {

    void solve(int n,vector<vector<string>>&ans,vector<string>board,int col,vector<int>left,
    vector<int>up,vector<int>down)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }


        for(int row=0;row<n;row++)
        {
            if(left[row]==0 && up[(n-1)+(col-row)]==0 && down[row+col]==0)
            {
                board[row][col]='Q';
                left[row]=1;
                up[(n-1)+(col-row)]=1;
                down[row+col]=1;

                solve(n,ans,board,col+1,left,up,down);

                board[row][col]='.';
                left[row]=0;
                up[(n-1)+(col-row)]=0;
                down[row+col]=0;

            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>>ans;

        vector<string>board(n);
        string s(n,'.');

        for(auto &i:board)i=s;

        vector<int>left(n,0);
        vector<int>up(2*n-1,0);
        vector<int>down(2*n-1,0);

        solve(n,ans,board,0,left,up,down);

        return ans;
        
    }
};