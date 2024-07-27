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
    //1->height 2->diameter
    pair<int,int>solve(TreeNode* root)
    {
        if(root==NULL)
        {
            return {0,0};
        }

        pair<int,int>l=solve(root->left);
        pair<int,int>r=solve(root->right);

        pair<int,int>ans;

        ans.second=max(l.second,r.second)+1;
        ans.first=max({l.first,r.first,l.second+r.second});

        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {

        return solve(root).first;
        
    }
};