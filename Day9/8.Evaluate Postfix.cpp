int evaluatePostfix(string S)
    {
        stack<int>s;
        
        for(auto i:S)
        {
            
           
            if(i=='+')
            {
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            s.push(a+b);
                
            }
            else if(i=='-')
            {
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            s.push(b-a);
                
            }
            else if(i=='*')
            {
                 int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            s.push(a*b);
                
            }
            else if(i=='/')
            {
                 int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            s.push(b/a);
                
            }
            else
            {
                s.push(i-'0');
            }
        }
        return s.top();
        
    }