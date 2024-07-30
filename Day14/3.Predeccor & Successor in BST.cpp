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


// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& succ, int key)
    {
        pre=NULL;
        succ=NULL;
        
        while(root!=NULL)
        {
            if(root->key==key)break;
            else if(root->key<key)
            {
                pre=root;
                root=root->right;
            }
            else
            {
                succ=root;
                root=root->left;
            }
        }
        if(!root)return ;
        
        if(root->left)
        {
            Node* temp=root->left;
            
            while(temp->right)temp=temp->right;
            pre=temp;
        }
        if(root->right)
        {
            Node* temp=root->right;
            while(temp->left)temp=temp->left;
            succ=temp;
        }
        
    }
};