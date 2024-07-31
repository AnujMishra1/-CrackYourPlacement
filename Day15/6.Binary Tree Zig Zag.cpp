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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)return {};

        vector<vector<int>>ans;

        queue<TreeNode*>q;
        q.push(root);

        bool ltr=true;

        while(!q.empty())
        {
            int size=q.size();
            vector<int>output(size);
            
            for(int i=0;i<size;i++)
            {
                auto f=q.front();
                q.pop();
                if(ltr)output[i]=f->val;
                else output[size-i-1]=f->val;

                if(f->left)q.push(f->left);
                if(f->right)q.push(f->right);
            }
            ltr=!ltr;
            ans.push_back(output);
        }
        return ans;
        
    }
};