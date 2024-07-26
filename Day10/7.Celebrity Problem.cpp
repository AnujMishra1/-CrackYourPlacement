int celebrity(vector<vector<int> >& M, int n) {
        
        stack<int>s;
        
        for(int i=0;i<n;i++)
        {
            s.push(i);
        }
        
        while(s.size()>1)
        {
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            
            if(M[a][b]==1)
            {
                s.push(b);
            }
            else
            {
                s.push(a);
            }
        }
        
        int potentialCelebrity=s.top();
        
        for(int i=0;i<n;i++)
        {
            if(M[potentialCelebrity][i]==1)return -1;
        }
        
        for(int i=0;i<n;i++)
        {
            if(i!=potentialCelebrity)
            {
                if(M[i][potentialCelebrity]==0)return -1;
            }
        }
        return potentialCelebrity;
    }