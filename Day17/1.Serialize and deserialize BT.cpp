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

class Codec {
private:
    void preorder(TreeNode* root, string &s) {
        if (root == NULL) {
            s.push_back('.');
            s.push_back(' ');
            return;
        }
        s.append(to_string(root->val) + " ");
        preorder(root->left, s);
        preorder(root->right, s);
    }

    TreeNode* solve(const string& s, int &i) {
        if (i >= s.size()) return NULL;
        if (s[i] == '.') {
            i += 2; // Skip the '.' and the following space
            return NULL;
        }

        int start = i;
        while (i < s.size() && s[i] != ' ') {
            i++;
        }
        int num = stoi(s.substr(start, i - start));
        i++; // Skip the space

        TreeNode* root = new TreeNode(num);
        root->left = solve(s, i);
        root->right = solve(s, i);
        return root;
    }


    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        preorder(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return solve(data, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;

// TreeNode* ans = deser.deserialize(ser.serialize(root));