class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int>s;

        for(auto i:tokens)
        {
            if(i=="+")
            {
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                s.push(a+b);
            }
            else if(i=="-")
            {
                
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                s.push(b-a);
            }
            else if(i=="*")
            {
                
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                s.push(a*b);

            }
            else if(i=="/")
            {
                
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                s.push(b/a);
            }
            else
            {
                int num=stoi(i);
                s.push(num);
            }
        }
        return s.top();
        
    }
};