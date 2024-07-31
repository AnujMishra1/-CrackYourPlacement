#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

class Solution{ 
    private:
    void solve(Node* root,int l,int h, int &ans)
    {
        if(root==NULL)return ;
        
        solve(root->left,l,h,ans);
        if(root->key>=l && root->key<=h)ans++;
        solve(root->right,l,h,ans);
    }
public:
    int getCount(Node *root, int l, int h)
    {
        int ans=0;
        
        solve(root,l,h,ans);
        return ans;
    }
};