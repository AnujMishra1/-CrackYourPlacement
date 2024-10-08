#include<bits/stdc++.h>
using namespace std;

//  * Definition for singly-linked list.
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

        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* ans=dummy;

        while(head!=NULL)
        {
            int val=head->val;

            ListNode* track=head->next;

            while(track!=NULL && track->val==val)
            {
                track=track->next;
            }
            if(track==head->next)
            {
                dummy=head;
                head=head->next;
            }
            else
            {
                dummy->next=track;
                head=track;
            }
        }
        return ans->next;
    }
};