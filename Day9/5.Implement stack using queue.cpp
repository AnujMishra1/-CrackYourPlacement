class MyStack {
public:

    queue<int>q,ref;
    MyStack() {
        
    }
    
    void push(int x) {

        if(q.empty())
        {
            q.push(x);
            return;
        }
        
        while(!q.empty())
        {
            int f=q.front();
            q.pop();
            ref.push(f);
        }

        q.push(x);
        while(!ref.empty())
        {
            q.push(ref.front());
            ref.pop();
        }  
    }
    
    int pop() {

        int f=q.front();
        q.pop();
        return f;       
    }
    
    int top() {
        return q.front();     
    }
    
    bool empty() {
        return q.empty();   
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */