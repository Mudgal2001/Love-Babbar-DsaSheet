#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node*middleNode(Node* head){
        Node*slow=head;
        Node*fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
     }
     Node *mergesortedll(Node*head1,Node*head2){
         if(head1==NULL){
             return head2;
         }else if(head2==NULL){
             return head1;
         }
         Node*head=NULL;
         Node*tail=NULL;
         while(head1 && head2){
             if(head1->data>=head2->data){
                 if(head==NULL){
                     head= head2;
                     tail=head2;
                     head2=head2->next;
                     continue;
                 }
                 tail->next=head2;
                 tail=head2;
                 head2=head2->next;
             }else{
                  if(head==NULL){
                     head=head1;
                     tail=head1;
                     head1=head1->next;
                     continue;
                 }
                 tail->next=head1;
                 tail=head1;
                 head1=head1->next;
             }
         }
         if(head1!=NULL){
             if(tail==NULL){
                 tail=head1;
                 return head;
             }
             tail->next=head1;
         }
          if(head2!=NULL){
             if(tail==NULL){
                 tail=head2;
                 return head;
             }
             tail->next=head2;
         }
         return head;
        
     }
    Node* mergeSort(Node* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node*mid=middleNode(head);
        Node*b=mid->next;
        mid->next=NULL;
        Node*temp1=mergeSort(head);
        Node*temp2=mergeSort(b);
        Node*c=mergesortedll(temp1,temp2);
        return c;
        
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends