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
  
  
class BSTIterator {
    private:
    void inorder(TreeNode* root,vector<int>&ans)
    {
        if(root==NULL)return;

        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
public:

    vector<int>temp;
    int i=-1;
    BSTIterator(TreeNode* root) {
        inorder(root,temp);
    }
    
    int next() {
        if(i+1<temp.size())
        {
            i++;
            return temp[i];
        }
        return -1;
    }
    
    bool hasNext() {
        if(i+1<temp.size())return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */