class Solution {
public:
    string removeDuplicates(string s, int k) {

        stack<pair<char,int>>st;

        for(auto i:s)
        {

            if(st.empty())
            {
                st.push({i,0});
            }
            else 
            {
                if(st.top().first==i)
                {

                    if(st.top().second==k-2)
                    {
                        int j=0;
                        while(j<k-1)
                        {
                            st.pop();
                            j++;
                        }
                    }
                    else
                    {
                        if(!st.empty())
                        st.push({i,st.top().second+1});
                    }

                }
                else
                {
                    st.push({i,0});
                }
            }

        }
        string ans;

        while(!st.empty())
        {
            ans.push_back(st.top().first);
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};