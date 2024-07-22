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
    void solve(ListNode* &head1,ListNode* &head2)
    {
        ListNode* first=head1;
        ListNode* second=head1->next;

        while(head2!=NULL && second!=NULL)
        {
            if(head2->val>=first->val && head2->val<=second->val)
            {
                ListNode* temp=head2->next;
                first->next=head2;
                head2->next=second;
                head2=temp;
                first=first->next;
            }
            else
            {
                first=second;
                second=second->next;
            }
        }

        if(head2!=NULL)
        {
            first->next=head2;
        }

        // return head1;

    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL )return list2;
        if(list2==NULL)return list1;

        if(list1->val<=list2->val)
        {
            if(list1->next==NULL)
            {
                list1->next=list2;
                return list1;
            }
            else
            {
                solve(list1,list2);
                return list1;
            }
        }
        else
        {
            if(list2->next==NULL)
            {
                list2->next=list1;
                return list2;
            }
            else
            {
                solve(list2,list1);
                return list2;
            }
        }
        
    }
};