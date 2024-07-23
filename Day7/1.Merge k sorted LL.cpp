#include<bits/stdc++.h>
using namespace std;

//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class compare{
    public:
    bool operator()(ListNode* a,ListNode* b)
    {
        return a->val>b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode* ans=NULL;
        ListNode* tail=NULL;

         priority_queue<ListNode*,vector<ListNode*>,compare>pq;

         for(auto i:lists)
         {
            if(i)
            pq.push(i);
         }

         while(!pq.empty())
         {
            auto f=pq.top();
            auto n=f->next;
            pq.pop();
            if(ans==NULL)
            {
                ans=f;
                ans->next=NULL;
                tail=ans;
            }
            else
            {
                tail->next=f;
                tail=f;
                tail->next=NULL;
            }

            if(n)pq.push(n);
         }
         return ans;

        
    }
};