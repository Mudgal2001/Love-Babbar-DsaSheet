#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}


class Solution
{
    public:
    
    vector<int> levelOrder(Node* node)
    {
      
      vector<int>ans;
      if(node==NULL){
          return ans;
      }
      queue<Node*>nodes;
      nodes.push(node);
      while(nodes.size()!=0){
          Node* front= nodes.front();
          nodes.pop();
          ans.push_back(front->data);
          if(front->left!=NULL){
              nodes.push(front->left);
          }
          if(front->right!=NULL){
              nodes.push(front->right);
          }
      }
      return ans;
    }
};


void inOrder(struct Node* node)
{
  if (node == NULL)
    return;

  inOrder(node->left);
  printf("%d ", node->data);

  inOrder(node->right);
}


Node* buildTree(string str)
{   
    
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    
    Node* root = newNode(stoi(ip[0]));
        
    
    queue<Node*> queue;
    queue.push(root);
        
    
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        
        Node* currNode = queue.front();
        queue.pop();
            
        
        string currVal = ip[i];
            
        
        if(currVal != "N") {
                
            
            currNode->left = newNode(stoi(currVal));
                
            
            queue.push(currNode->left);
        }
            
        
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
        
        if(currVal != "N") {
                
            
            currNode->right = newNode(stoi(currVal));
                
           
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


int main()
{
  int t;
  scanf("%d ",&t);
  while (t--)
  {
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		Solution ob;
        vector <int> res = ob.levelOrder(root);
        for (int i : res) cout << i << " ";
        cout << endl;
  }
  return 0;
}


  