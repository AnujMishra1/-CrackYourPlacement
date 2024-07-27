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
    bool solve(TreeNode* l,TreeNode* r)
    {
        if(l==NULL && r==NULL)return true;
        if(l==NULL)return false;
        if(r==NULL)return false;

        bool left=solve(l->left,r->right);
        bool right=solve(l->right,r->left);

        return (left && right && (l->val==r->val) );
    }
public:
    bool isSymmetric(TreeNode* root) {

        return solve(root->left,root->right) ;   
    }
};