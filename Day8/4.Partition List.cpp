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
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small=new ListNode(0);
        ListNode* big=new ListNode(0);
        ListNode* t=big;
        ListNode* temp=head;
        ListNode* ans=small;
        while(temp!=NULL)
        {
            if(temp->val<x){
            small->next=temp;
            small=temp;
            temp=temp->next;
            small->next=NULL;
            }
            else
            {
                t->next=temp;
                t=temp;
                temp=temp->next;
                t->next=NULL;
            }
        }
        small->next=big->next;
        return ans->next;
    }
};