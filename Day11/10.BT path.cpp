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

    void solve(TreeNode* root,vector<string>&ans,string output)
    {
        if(root==NULL)
        {
            return;
        }

        if(root->left==NULL && root->right==NULL)
        {
           output+=to_string(root->val);
             ans.push_back(output);
             while(output.size()>0 && output.back()!='>')
             output.pop_back();
            return;
            
        }

        output+=to_string(root->val);
        output.push_back('-');
        output.push_back('>');

        solve(root->left,ans,output);
        solve(root->right,ans,output);

        // return ans;


    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string>ans;
        string output;
        if(root==NULL)return ans;

        solve(root,ans,output);

        return ans;

        
    }
};