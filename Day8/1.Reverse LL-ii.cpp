#include<bits/stdc++.h>
using namespace std;

//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

  
class Solution {
    ListNode* reverse(ListNode* head,int l,int r)
    {
        if(head==NULL || head->next==NULL)return head;

        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next=head->next;

        while(next!=NULL && l<r)
        {
            curr->next=prev;
            prev=curr;
            curr=next;
            next=next->next;
            l++;
        }

        curr->next=prev;
        head->next=next;
        return curr;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(left==right)return head;
        if(head==NULL || head->next==NULL)return head;

        ListNode* prev=NULL;
        ListNode* curr=head;
        int i=1;

        while(curr!=NULL && i<left)
        {
            i++;
            prev=curr;
            curr=curr->next;
        }

        if(curr==NULL)return head;
        ListNode* p=prev;
        if(p!=NULL)
        {
            p->next=reverse(curr,left,right);
        }
        else
        {
            return reverse(curr,left,right);
        }
        return head;
        
    }
};