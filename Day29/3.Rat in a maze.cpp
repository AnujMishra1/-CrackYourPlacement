#include<bits/stdc++.h>
using namespace std;

// User function template for C++

class Solution{
    private:
    bool valid(int i,int j,vector<vector<int>> &m,vector<vector<int>>visited,int n)
    {
        if(i>=0 && i<n && j>=0 && j<n && visited[i][j]==0 && m[i][j]==1)
        {
            return true;
        }
        return false;
    }
    
    void solve(vector<vector<int>> &m, int n,vector<string>& ans,string output,int i,int j,vector<vector<int>>visited)
    {
        if(i==n-1 && j==n-1)
        {
            ans.push_back(output);
            return;
        }
        
        visited[i][j]=1;
        //down
        if(valid(i+1,j,m,visited,n))
        {
            
           output.push_back('D');
           solve(m,n,ans,output,i+1,j,visited);
           output.pop_back();
        }
        //up
        if(valid(i-1,j,m,visited,n))
        {
            
           output.push_back('U');
           solve(m,n,ans,output,i-1,j,visited);
           output.pop_back();
        }
        //left
        if(valid(i,j-1,m,visited,n))
        {
            
           output.push_back('L');
           solve(m,n,ans,output,i,j-1,visited);
           output.pop_back();
        }
        //right
        if(valid(i,j+1,m,visited,n))
        {
            
           output.push_back('R');
           solve(m,n,ans,output,i,j+1,visited);
           output.pop_back();
        }
        visited[i][j]=0;
       
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        if(m[0][0]==0)
        {
            return ans;
        }
        vector<vector<int>>visited=m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                visited[i][j]=0;
            }
        }
        
        
        
        string output="";
        int i=0;
        int j=0;
        // visited[0][0]=1;
        solve(m,n,ans,output,i,j,visited);
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};



    