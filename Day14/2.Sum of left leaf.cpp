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

    int solve(TreeNode* root,bool left)
    {
        if(root==NULL)return 0;

        if(root->left==NULL && root->right==NULL && left)
        {
            return root->val;
        }


        int l=solve(root->left,true);
        int r=solve(root->right,false);

        return l+r;


    }
public:
    int sumOfLeftLeaves(TreeNode* root) {

        return solve(root,false);
        
    }
};