#include<bits/stdc++.h>
using namespace std;

// The Node structure is
struct Node {
int data;
Node * right, * left;
};


class Solution {
private:
    bool solve(Node* root, int mini, int maxi) {
        if (root == NULL) return false;
        
        // If it's a dead end
        if (mini == maxi) return true;
        
        return solve(root->left, mini, root->data - 1) || solve(root->right, root->data + 1, maxi);
    }

public:
    bool isDeadEnd(Node *root) {
        return solve(root, 1, INT_MAX);
    }
};