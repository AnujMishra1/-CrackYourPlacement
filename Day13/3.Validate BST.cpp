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
   bool check(TreeNode* root,long long mini,long long maxi)
   {
        if(root==NULL)return true;

        bool l=check(root->left,mini,root->val);
        bool r=check(root->right,root->val,maxi);

        return (l&&r&& root->val>mini && root->val<maxi);
   }
public:
    bool isValidBST(TreeNode* root) {
        return check(root,LLONG_MIN,LLONG_MAX);

        
    }
};