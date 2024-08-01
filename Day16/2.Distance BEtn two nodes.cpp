#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
}; 

class Solution{
    private:
    
    Node* LowestCA(Node* root,int a,int b)
    {
        if(root==NULL)return NULL;
        if(root->data==a || root->data==b)return root;
        
        Node* l=LowestCA(root->left,a,b);
        Node* r=LowestCA(root->right,a,b);
        
        if(l && r)return root;
        else  if(l)return l;
        else if(r)return r;
        else return NULL;
    }
    
    int solve(Node* root,int a)
    {
        if(root==NULL)return 0;
        
        if(root->data==a)return 1;
        
        int l=solve(root->left,a);
        int r=solve(root->right,a);
        
        if(l!=0)return 1+l;
        if(r!=0)return 1+r;
        
        
        return 0;
    }
    
    public:
    
    int findDist(Node* root, int a, int b) {
     Node *LCA=LowestCA(root,a,b);
     
     int l=solve(LCA,a);
     int r=solve(LCA,b);
     
     return l+r-2;
    }
};