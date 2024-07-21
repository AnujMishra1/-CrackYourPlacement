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
    ListNode* removeElements(ListNode* head, int val) {

        ListNode* temp=new ListNode(-1);
        ListNode* curr=temp;
        temp->next=head;

        while(head!=NULL)
        {
            if(head->val==val)
            {
                curr->next=head->next;
                head=head->next;
            }
            else
            {
                curr=head;
                head=head->next;
            }
        }
        return temp->next;
        
    }
};