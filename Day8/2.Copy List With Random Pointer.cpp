#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {

        Node* copyHead=NULL;
        Node* copyTail=NULL;

        

        Node* temp=head;

        while(temp!=NULL)
        {
            int val=temp->val;
            Node* k=new Node(val);
            if(copyHead==NULL)
            {
                copyHead=k;
                copyTail=k;   
            }
            else{
                    copyTail->next=k;
                    copyTail=k;
            } 
            temp=temp->next;  
        }

       
        Node* tempA=head;
        Node* tempB=copyHead;
        while(tempA!=NULL)
        {
            Node* k1=tempA->next;
            Node* k2=tempB->next;

            tempA->next=tempB;
            tempB->next=k1;

            tempA=k1;
            tempB=k2;
        }

        tempA=head;

        while(tempA!=NULL)
        {
            Node* copy=tempA->next;

            if(tempA->random)
            copy->random=tempA->random->next;

            tempA=tempA->next->next;
        }

        tempA=head;
        
        while(tempA!=NULL)
        {

            Node* nxt=tempA->next;


            tempA->next=nxt->next;
            if(tempA->next)
            nxt->next=tempA->next->next;

            tempA=tempA->next;
           
        }


        return copyHead;
        
    }
};