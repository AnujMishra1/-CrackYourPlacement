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
     bool isSameTree(TreeNode* p, TreeNode* q) {

        if(p==NULL && q==NULL)return true;
        if(p==NULL || q==NULL)return false;

        return (p->val==q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right) );
        
    }

    bool solve(TreeNode* root,TreeNode* sub)
    {
        if(root==NULL)return false;;

        if(root->val==sub->val)
        {
            bool check=isSameTree(root,sub);
            if(check)return true;
        }


        bool l=solve(root->left,sub);
        bool r=solve(root->right,sub);

        return l||r;

    }
public:
    bool isSubtree(TreeNode* &root, TreeNode* &subRoot) {

        return solve(root,subRoot);
        
    }
};