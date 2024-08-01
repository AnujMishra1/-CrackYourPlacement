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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;

        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            long long mini = q.front().second; 
            long long first, last;
            
            for (int i = 0; i < size; ++i) {
                auto f = q.front();
                q.pop();
                TreeNode* node = f.first;
                long long pos = f.second - mini; 
                
                if (i == 0) first = pos;
                if (i == size - 1) last = pos;
                
                if (node->left) q.push({node->left, 2 * pos});
                if (node->right) q.push({node->right, 2 * pos + 1});
            }

            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};