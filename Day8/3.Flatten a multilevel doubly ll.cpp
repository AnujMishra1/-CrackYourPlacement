#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
    private:
    void solve(Node* &parent,Node* &child)
    {
        if(parent==NULL || child==NULL)return;
        Node* k=parent->next;
        parent->next=child;
        child->prev=parent;
        Node* prev=parent;
        while(child!=NULL)
        {
            
            if(child->child)
            {
                solve(child,child->child);
            }
            prev=child;
            child=child->next;
        }
        prev->next=k;
        if(k!=NULL)
        {
            k->prev=prev;        }
    
    }
public:
    Node* flatten(Node* head) {

        Node* temp=head;

        while(temp!=NULL)
        {
            if(temp->child)
            {
                
                solve(temp,temp->child);
            }
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL)
        {
            temp->child=NULL;
            temp=temp->next;
        }
        return head;
        
    }
};

