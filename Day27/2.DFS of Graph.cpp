#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    void solve(int node,vector<int>&ans,vector<int>&vis,vector<int>adj[])
  {
      ans.push_back(node);
      
      for(auto j:adj[node])
      {
          if(vis[j]==0)
          {
               vis[j]=1;
          solve(j,ans,vis,adj);
          }
         
      }
  }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        
        vector<int>ans;
        
        vector<int>vis(V,0);
        // vis[0]=true;
        
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                vis[i]=1;
                solve(i,ans,vis,adj);
                
            }
        }
        
        return ans;
        
    }
};