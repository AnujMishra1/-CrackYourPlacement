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
    ListNode* solve(ListNode* l1,ListNode* l2)
    {
         ListNode* temp=NULL;
        ListNode* ans=NULL;
       
        int carry=0;
        while(l1!=NULL && l2!=NULL)
        {
            int a=l1->val;
            int b=l2->val;

            int sum=a+b+carry;
            int digit=sum%10;
             carry=sum/10;

            insertAtTail(ans,temp,digit);
            l1=l1->next;
            l2=l2->next;
        }
        

        while(l1!=NULL)
        {
            int a=l1->val;
            int sum=carry+a;

            int digit=sum%10;
             carry=sum/10;

            insertAtTail(ans,temp,digit);
            l1=l1->next;
        }

        while(l2!=NULL)
        {
            int a=l2->val;
            int sum=carry+a;

            int digit=sum%10;
             carry=sum/10;

            insertAtTail(ans,temp,digit);
            l2=l2->next;
        }

        if(carry!=0)
        {
            insertAtTail(ans,temp,carry);
        }

        return ans;

    }
     ListNode* reverseList(ListNode* head) {

     if(head==NULL || head->next==NULL)return head;
        ListNode* prev=NULL;
        ListNode* curr=head;

        while(curr->next!=NULL)
        {
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        curr->next=prev;
        return curr;
    }

    void insertAtTail(ListNode* &ans,ListNode* &temp,int val)
    {
        cout<<val;
        ListNode* k=new ListNode(val);
        if(ans==NULL)
        {
            ans=k;
            temp=ans;
            return ;
        }
        else
        {
            temp->next=k;
            temp=k;
        }
    }
  
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        l1=reverseList(l1);
        l2=reverseList(l2);
        return reverseList(solve(l1,l2));
        
    }
};