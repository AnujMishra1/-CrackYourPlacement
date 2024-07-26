int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,pair<int,int>>>q;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({0,{i,j}});
                }
            }
        }
        
        int time=0;
        
        while(!q.empty())
        {
            auto f=q.front();
            int t=f.first;
            int i=f.second.first;
            int j=f.second.second;
            q.pop();
            time=max(time,t);
            
            
            if(i-1>=0 && grid[i-1][j]==1)
            {
                grid[i-1][j]=2;
                q.push({t+1,{i-1,j}});
            }
            if(i+1<grid.size() && grid[i+1][j]==1)
            {
                grid[i+1][j]=2;
                q.push({t+1,{i+1,j}});
            }
            if(j-1>=0 && grid[i][j-1]==1)
            {
                grid[i][j-1]=2;
                q.push({t+1,{i,j-1}});
            }
            if(j+1<grid[0].size() && grid[i][j+1]==1)
            {
                grid[i][j+1]=2;
                q.push({t+1,{i,j+1}});
            }
            
        }
        
        for(auto i:grid)
        {
            for(auto j:i)
            {
                if(j==1)return -1;
            }
        }
        
        return time;
    }