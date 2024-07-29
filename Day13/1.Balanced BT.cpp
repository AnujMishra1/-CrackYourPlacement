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

    pair<int,bool> solve(TreeNode* root)
    {
        if(root==NULL)
        {
            return {0,true};
        }

        pair<int,bool>l=solve(root->left);
        pair<int,bool>r=solve(root->right);

        pair<int,bool>ans;
        ans.first=max(l.first,r.first)+1;

        ans.second=(abs(l.first-r.first)<=1 && l.second && r.second);

        return  ans;
    }

public:
    bool isBalanced(TreeNode* root) {

        return solve(root).second;
        
    }
};