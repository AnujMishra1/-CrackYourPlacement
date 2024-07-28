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
    bool solve(TreeNode* &root,int total,int &curr)
    {
        if(root==NULL)return false;
        if(root->left==NULL && root->right==NULL)
        {
          
            if(curr+root->val==total)return true;
            else return false;
        }

        curr+=root->val;
        bool l=solve(root->left,total,curr);
        bool r=solve(root->right,total,curr);
        curr-=root->val;

        return l||r;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        return solve(root,targetSum,sum);
        
    }
};