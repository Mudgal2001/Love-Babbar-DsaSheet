//Initial template for C++

#include <bits/stdc++.h> 
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

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    Node *reverse(Node *head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node* tail =head->next;
        Node* h=reverse(head->next);
        tail->next=head;
        head->next=NULL;
        return h;
    }
    public:
    Node* addOne(Node *head) 
    {
        if(head==NULL){
            Node* newNode= new Node (1);
            return newNode;
        }
        Node * h=reverse(head);
        int carr=0;
        Node*temp=h;
        int num= temp->data+1;
        temp->data = num%10;
         carr = num/10;
        while(carr!=0){
            if(temp->next==NULL){
                break;
            }
            temp=temp->next;
            num=temp->data+carr;
            temp->data=num%10;
            carr = num/10;
        }
        if(carr!=0){
            Node*newNode = new Node(carr);
            temp->next=newNode;
        }
        Node *ans=reverse(h);
        return ans;
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends