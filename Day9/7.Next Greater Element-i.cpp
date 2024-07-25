class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int,int>mp;

        stack<int>s;
        s.push(-1);

        for(int i=nums2.size()-1;i>=0;i--)
        {
            while(s.top()!=-1 && s.top()<=nums2[i])
            {
                s.pop();
            }
            mp[nums2[i]]=s.top();
            s.push(nums2[i]);
        }

        for(auto &i:nums1)
        {
            i=mp[i];
        }
        return nums1;
        
    }
};