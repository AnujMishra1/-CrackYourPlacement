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



class Solution {
Node* solve(int pre[], int s, int e, int n) {
    if (s > e) return NULL;
    
    Node* root = new Node(pre[s]);
    
    int k = s + 1;
    while (k <= e && pre[k] < pre[s]) k++;
    
    root->left = solve(pre, s + 1, k - 1, n);
    root->right = solve(pre, k, e, n);
    return root;
}

public:
    // Function that constructs BST from its preorder traversal.
    Node* Bst(int pre[], int size) {
        return solve(pre, 0, size - 1, size);
    }
};