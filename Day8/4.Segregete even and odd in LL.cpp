#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution{
public:
    Node* divide(int N, Node *head) {
    if (!head) return head;

    Node* evenDummy = new Node(0);
    Node* oddDummy = new Node(0);
    Node* even = evenDummy;
    Node* odd = oddDummy;
    Node* current = head;

    while (current) {
        if (current->data % 2 == 0) {
            even->next = current;
            even = even->next;
        } else {
            odd->next = current;
            odd = odd->next;
        }
        current = current->next;
    }

    // Connect the even list to the odd list
    even->next = oddDummy->next;
    // Terminate the odd list
    odd->next = nullptr;

    // The head of the new list is the next of the even dummy node
    Node* newHead = evenDummy->next;

    // Clean up dummy nodes
    delete evenDummy;
    delete oddDummy;

    return newHead;
}
};