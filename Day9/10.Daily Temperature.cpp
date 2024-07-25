class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {

        vector<int>ans(nums.size(),0);

        stack<int>st;
        st.push(INT_MAX);

        for(int i=nums.size()-1;i>=0;i--)
        {
            while(st.top()!=INT_MAX  && nums[st.top()]<=nums[i])
            {
                st.pop();
            }

            if(st.top()==INT_MAX)
            {
                ans[i]=0;
            }
            else
            {
                ans[i]=st.top()-i;
            }
            
            st.push(i);
        }
        return ans;        
    }
};