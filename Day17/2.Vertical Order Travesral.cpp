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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        if(root==NULL)return {};

        map<int,map<int,vector<int>>>mp;

        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        

        while(!q.empty())
        {
            auto f=q.front();
            TreeNode* node=f.first;
            int hd=f.second.first;
            int lvl=f.second.second;

            mp[hd][lvl].push_back(node->val);
            q.pop();

            if(node->left){
                q.push({node->left,{hd-1,lvl+1}});
            }
            if(node->right)
            {
                q.push({node->right,{hd+1,lvl+1}});
            }

        }
        vector<vector<int>>ans;
        
        vector<int>temp;
        for(auto i:mp)
        {
           for(auto j:i.second)
           {
            sort(j.second.begin(),j.second.end());
            for(auto k:j.second)
            {
                temp.push_back(k);
            }
          
           }
             ans.push_back(temp);
            temp.clear();
        }
        return ans;


        
    }
};