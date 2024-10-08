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
    void solve(TreeNode* root,vector<int>&ans,int i)
    {
        if(root==NULL)return;


        if(ans.size()==i)ans.push_back(root->val);

        solve(root->right,ans,i+1);
        solve(root->left,ans,i+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {

        vector<int>ans;
        solve(root,ans,0);
        return ans;
    }
};