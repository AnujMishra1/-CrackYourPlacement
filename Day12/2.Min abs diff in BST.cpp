#include<bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  
class Solution {

     private:

    void solve(TreeNode* root,vector<int>&ans)
    {
        if(root==NULL)return;

        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        
         vector<int>in;

        solve(root,in);

        int ans=INT_MAX;

        for(int i=1;i<in.size();i++)
        {
            if(in[i]-in[i-1]<ans)
            {
                ans=in[i]-in[i-1];
            }
        }
        return ans;

    }
};