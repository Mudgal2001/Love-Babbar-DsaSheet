#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};


void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}



class Solution
{
    public:
     pair<node*,node*>reverse(node * head){
         if(head==NULL || head->next==NULL){
             return {head,head};
         }
         node* tail =head->next;
         pair<node*,node*>p=reverse(head->next);
         tail->next=head;
         head->next=NULL;
         return {p.first,head};
     }
    struct node *reverse (struct node *head, int k)
    { 
        node *h1=head;
        node *t1=head;
        int count=k-1;
        while(t1->next!=NULL && count!=0){
            t1=t1->next;
            count--;
        }
        if(count!=0){
            pair<node*,node*>p=reverse(h1);
            return p.first;
        }else if(t1->next!=NULL){
            node*h2=t1->next;
            t1->next=NULL;
            pair<node*,node*>p=reverse(h1);
            node*temp=reverse(h2,k);
            p.second->next=temp;
            return p.first;
        }else{
            pair<node*,node*>p=reverse(h1);
            return p.first;
        }
    }
};



int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}

  