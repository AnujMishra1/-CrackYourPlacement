#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    bool safe(int row,int col,vector< vector<char> > suduko, int val)
    {
        for(int i=0;i<9;i++)
        {
            if(suduko[row][i]==val+'0')return false;
            if(suduko[i][col]==val+'0')return false;
            if(suduko[3*(row/3) + i/3][3*(col/3) +i%3] == val+'0')  return false;
        
    }
    return true;
    }
    bool solve(vector<vector<char>>& board)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {

                if(board[i][j]=='.')
                {
                    for(char ch='1';ch<='9';ch++)
                    {
                        if(safe(i,j,board,ch-'0'))
                        {
                            board[i][j]=ch;
                            if(solve(board))return true;

                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};