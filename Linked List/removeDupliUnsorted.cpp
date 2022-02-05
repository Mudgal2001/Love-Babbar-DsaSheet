#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}





class Solution
{
    public:
    
    Node * removeDuplicates( Node *head) 
    {
        if(head==NULL || head->next==NULL){
            return head;
        }
     unordered_map<int,int>freq;
     Node*temp=head;
     Node*prev=NULL;
     while(temp!=NULL){
         if(freq.count(temp->data)==0){
         freq[temp->data]=1;
         prev=temp;
        temp=temp->next;
      }else{
         Node*a=temp;
         prev->next=temp->next;
         temp=temp->next;
         delete a;
      }
      
}
return head;
    }
};



int main() {
	
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
	    Solution ob;
		Node *result  = ob.removeDuplicates(head);
		print(result);
		cout<<endl;
		
	}
	return 0;
}  