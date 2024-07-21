#include<bits/stdc++.h>
using namespace std;

//   Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
      int z=0;
      int o=0;
      int t=0;
      
      Node* temp=head;
      
      while(temp!=NULL)
      {
          if(temp->data==0)z++;
          else if(temp->data==1)o++;
          else t++;
          
          temp=temp->next;
      }
      
      temp=head;
      
      while(temp!=NULL)
      {
          while(z!=0)
          {
              temp->data=0;
              z--;
              temp=temp->next;
          }
          
            while(o!=0)
            {
                temp->data=1;
                o--;
                temp=temp->next;
            }
            
            while(t!=0)
            {
                temp->data=2;
                t--;
                temp=temp->next;
            }
      }
      
      return head;
        
    }
};
