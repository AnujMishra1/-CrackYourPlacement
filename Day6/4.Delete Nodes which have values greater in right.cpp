#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution
{
     Node* reverseList(struct Node *head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        
         Node* temp=head;
         Node* prev=NULL;
         Node* next=temp->next;
        
        while(next!=NULL && temp!=NULL)
        {
            temp->next=prev;
            prev=temp;
            temp=next;
            next=next->next;
        }
        temp->next=prev;
        
        return temp;
        
    }
    public:
    Node *compute(Node *head)
    {
        head=reverseList(head);
        int mini=INT_MAX;
        int maxi=INT_MIN;
        
        Node* prev=head;
        Node* curr=head;
        
        while(curr!=NULL)
        {
            int value=curr->data;
            if(value<mini || value<maxi)
            {
                prev->next=curr->next;
                curr=curr->next;
            }
            else
            {
                prev=curr;
                curr=curr->next;
            }
            mini=min(mini,value);
            maxi=max(maxi,value);
        }
        head=reverseList(head);
        return head;
    }
    
};