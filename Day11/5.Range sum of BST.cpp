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
    void solve(TreeNode* root, int low, int high,int & sum)
    {
        if(root==NULL)return;
 if(root->val<=high && root->val>=low){
            sum+=root->val;
        }
       if(root->val>=high){
            solve(root->left,low,high,sum);
            return;
        }
        else if(root->val<=low){
            solve(root->right,low,high,sum);
            return;
        }
        else{
            solve(root->left,low,high,sum);
            solve(root->right,low,high,sum);
        }

    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {

        
        int ans=0;
        solve(root,low,high,ans);
        return ans;
    }
};