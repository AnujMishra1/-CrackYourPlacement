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

    void inorder(TreeNode* root,vector<int>&temp)
    {
        if(root==NULL)return;

        inorder(root->left,temp);
        temp.push_back(root->val);
        inorder(root->right,temp);
    }

    void solve(TreeNode* &root,int a,int b)
    {
        if(root==NULL)return ;
        if(root->val==a)root->val=b;
        else if(root->val==b)root->val=a;

        solve(root->left,a,b);
        solve(root->right,a,b);
    }
public:
    void recoverTree(TreeNode* root) {

        vector<int>temp;

        inorder(root,temp);
        vector<int>k(temp);

        sort(k.begin(),k.end());
        int a=-1,b=-1;

        for(int i=0;i<temp.size();i++)
        {
            if(temp[i]!=k[i])
            {
                if(a==-1)a=temp[i];
                else b=temp[i];
            }
        }

        solve(root,a,b);

        cout<<a<<" "<<b;


        
    }
};