#include<bits/stdc++.h>
using namespace std;

//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


class Solution {
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = head->next;

        while (next != NULL) {
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
        }

        curr->next = prev;
        return curr;
    }
public:
    void reorderList(ListNode* head) {

        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;

        while(fast!=NULL && fast->next!=NULL)
        {
            prev=slow;
            fast=fast->next->next;
            slow=slow->next;
        }

        if(fast)
        {
            prev=slow;
            slow=slow->next;
        }
        prev->next=NULL;

        slow=reverse(slow);
        bool first=true;

        while(true)
        {
            if((!slow) || (!head))break;
            if(first)
            {
                ListNode* next=head->next;
                head->next=slow;
                head=next;
                first=!first;
            }
            else
            {
                ListNode* next=slow->next;
                slow->next=head;
                slow=next;
                first=!first;
            }
        }

         
        
    }
};