#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        
        queue<int>q;
        q.push(0);
        vector<int>vis(V,0);
        vis[0]=1;
        while(!q.empty())
        {
            
            int node=q.front();
            q.pop();
            
            ans.push_back(node);
            
            
            for(auto j:adj[node])
            {
                if(vis[j]==0)
                {
                    vis[j]=1;
                    q.push(j);
                }
            }
        }
        
        return ans;
    }
};

