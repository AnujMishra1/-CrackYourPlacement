#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};

class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        long MOD = 1000000007;
      long long a=0;
      long long b=0;
      while(first!=NULL)
      {
        a=(((a*10)%MOD)+first->data);
        first=first->next;
      }
      
      while(second!=NULL)
      {
        b=((b*10)%MOD)+second->data;
          second=second->next;
      }
    
      
      long long c=(a*b)%MOD;
      return c;
   
    }
};