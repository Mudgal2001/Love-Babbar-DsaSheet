// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
   Node *reverse(Node *head)
{
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node*tail=head->next;
    Node*a=reverse(head->next);
    tail->next=head;
    head->next=NULL;
    return a;}
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        
        Node*temp1=reverse(first);
        Node*temp2=reverse(second);
        Node*head=NULL;
        Node*tail=NULL;
        int carr=0;
        while(temp1 && temp2){
            int num=temp1->data+temp2->data+carr;
            Node*newNode=new Node(num%10);
            carr=num/10;
            if(head==NULL){
                head=newNode;
                tail=newNode;
            }else{
                tail->next=newNode;
                tail=newNode;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1){
            if(carr!=0){
                int num=temp1->data+carr;
                Node*newNode=new Node(num%10);
                carr=num/10;
                tail->next=newNode;
                tail=newNode;
                if(temp1->next==NULL && carr!=0){
                    Node*a=new Node(carr);
                    tail->next=a;
                    tail=a;
                    carr=carr/10;
                }
            }else{
                if(tail!=NULL){
                tail->next=temp1;}else{
                    tail=temp1;
                }
                break;
            }
            temp1=temp1->next;
        }
        while(temp2){
            if(carr!=0){
                int num=temp2->data+carr;
                Node*newNode=new Node(num%10);
                carr=num/10;
                tail->next=newNode;
                tail=newNode;
                if(temp2->next==NULL && carr!=0){
                    Node*a=new Node(carr);
                    tail->next=a;
                    tail=a;
                    carr=carr/10;
                }
            }else{
                if(tail!=NULL){
                tail->next=temp2;}else{
                    tail=temp2;
                }
                break;
            }
            temp2=temp2->next;
        }
        if(carr!=0){
            Node* newNode=new Node(carr);
            tail->next=newNode;
            tail=newNode;
        }
        Node*newhead=reverse(head);
        return newhead;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends