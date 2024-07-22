#include<bits/stdc++.h>
using namespace std;

//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* a=headA;
        ListNode* b=headB;

        while(a!=NULL && b!=NULL)
        {
            a=a->next;
            b=b->next;
        }
       

        if(a)
        {
            while(a!=NULL)
            {
                a=a->next;
                headA=headA->next;
            }
        }
        else
        {
            while(b!=NULL)
            {
                b=b->next;
                headB=headB->next;
            }
        }

        while(headA!=headB)
        {
            headA=headA->next;
            headB=headB->next;
        }

        return headA;
        
    }
};