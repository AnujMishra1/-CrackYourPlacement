#include<bits/stdc++.h>
using namespace std;

class Solution {

    private:
    bool solve(vector<vector<char>>&nums,string &word,int i,int j,int index)
    {
        if(index>=word.size())return true;

        if(i<0 || j<0 || i>=nums.size() || j>=nums[0].size() ||  nums[i][j]=='~')
        return false;

        if(nums[i][j]!=word[index])return false;
        char a=nums[i][j];
        
        //up
        nums[i][j]='~';
        bool up=solve(nums,word,i-1,j,index+1);
        //down
        bool down=solve(nums,word,i+1,j,index+1);
        //right
        bool right=solve(nums,word,i,j+1,index+1);
        //left
        bool left=solve(nums,word,i,j-1,index+1);

        nums[i][j]=a;

        return (up || down || left || right);
    }
public:
    bool exist(vector<vector<char>>& board, string word) {

        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    bool c=solve(board,word,i,j,0);
                    if(c)return true;
                }
                
            }
        }
        return false;
        
    }
};