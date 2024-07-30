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

    void solve(TreeNode* root,int k,unordered_map<TreeNode*,TreeNode*>parent,vector<int>&ans,unordered_map<TreeNode*,bool>vis)
    {
        if(root==NULL)return;

        if(k==0)
        {
            ans.push_back(root->val);
            return;
        }

        vis[root]=true;

        if(!vis[root->left])
        {
            solve(root->left,k-1,parent,ans,vis);
        }
        if(!vis[root->right])
        {
            solve(root->right,k-1,parent,ans,vis);
        }
        if(parent[root]!=NULL && !vis[parent[root]])
        {
            solve(parent[root],k-1,parent,ans,vis);
        }


    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*,TreeNode*>parent;

        queue<TreeNode*>q;
        q.push(root);
        parent[root]=NULL;

        while(!q.empty())
        {
            auto f=q.front();

            q.pop();
            if(f->left)
            {
                parent[f->left]=f;
                q.push(f->left);
            }
            if(f->right)
            {
                parent[f->right]=f;
                q.push(f->right);
            }
        }
        vector<int>ans;
        unordered_map<TreeNode*,bool>vis;
        solve(target,k,parent,ans,vis);
        return ans;
        
    }
};