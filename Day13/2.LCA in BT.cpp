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

    TreeNode* solve(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        if(root==NULL)return NULL;

        if(root==p || root==q)return root;

        TreeNode* l=solve(root->left,p,q);
        TreeNode* r=solve(root->right,p,q);

        if(l&&r)return root;
        else if(l)return l;
        else if(r)return r;
        else return NULL;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        

        return solve(root,p,q);
    }
};