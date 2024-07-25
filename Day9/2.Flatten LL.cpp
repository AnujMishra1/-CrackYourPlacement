 #include<bits/stdc++>
 using namespace std;
 
 void flatten(Node *root)
    {
        Node* temp=root;
        
        while(root!=NULL)
        {
            if(root->left)
            {
                Node* left=root->left;
                while(left->right)
                {
                    left=left->right;
                }
                
                left->right=root->right;
                root->right=root->left;
                root->left=NULL;
            }
            root=root->right;
        }
    }