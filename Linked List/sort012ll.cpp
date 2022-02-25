#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


 // } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
       Node*node0=new Node(0);
       Node*t0=node0;
       Node*node1=new Node(1);
       Node*t1=node1;
       Node*node2=new Node(2);
       Node*t2=node2;
       Node*temp=head;
       bool a=false,b=false,c=false;
       while(temp!=NULL){
           if(temp->data==0){
               t0->next=temp;
               t0=temp;
               temp=temp->next;
               t0->next=NULL;
               a=true;
           }else if(temp->data==1){
               t1->next=temp;
               t1=temp;
               temp=temp->next;
               t1->next=NULL;
               b=true;
           }else{
               t2->next=temp;
               t2=temp;
               temp=temp->next;
               t2->next=NULL;
               c=true;
           }
           
       }
       
        if(a&&b&&c){
            t0->next=node1->next;
            t1->next=node2->next;
            return node0->next;
        }else if(a&&b){
         t0->next=node1->next;
         return node0->next;
        }else if(b&&c){
            t1->next=node2->next;
            return node1->next;
        }else if(a&&c){
            t0->next=node2->next;
            return  node0->next;
        }else{
            return head;
        }
    }
};


// { Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}  // } Driver Code Ends