#include<bits/stdc++.h>
using namespace std;

//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {

    ListNode* solve(ListNode* head,int k)
    {
        if(head==NULL || head->next==NULL)return head;
        int cnt=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {   
                temp=temp->next;
                cnt++;
        }

        if(cnt<k)return head;

        ListNode* curr=head;
        ListNode* prev=NULL;
        cnt=0;
        while(cnt<k)
        {
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            cnt++;
        }

        head->next=solve(curr,k);

        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(k==0 || head==NULL || head->next==NULL)return head;

        return solve(head,k);
        
    }
};