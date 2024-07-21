#include<bits/stdc++.h>
using namespace std;


//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
       ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp=head;
        

        while(temp!=NULL)
        {
            int data=temp->val;

            ListNode* next=temp->next;

            while(next!=NULL &&next->val==data)
            {
                next=next->next;
            }
            temp->next=next;
            temp=next;
        }
        return head;
        
    }
};