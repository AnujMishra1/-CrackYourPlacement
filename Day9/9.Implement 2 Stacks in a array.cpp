class twoStacks {
  public:
    vector<int>nums;
    int i;
    int j;
    twoStacks() {
        nums=vector<int>(100,0);
        i=-1;
        j=100;
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        if(i+1==j)
        {
            return;
        }
        i++;
        nums[i]=x;
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        if(j-1==i)return;
        j--;
        nums[j]=x;
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        if(i==-1)return -1;
        return nums[i--];
        
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        if(j==100)return -1;
        return nums[j++];
    }
};