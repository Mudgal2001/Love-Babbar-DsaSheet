#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


 

class Solution {
  public:
   
    void inorder_helper(Node*root,vector<int>&ans){
        if(root==NULL){
         return;
        }
        inorder_helper(root->left,ans);
        ans.push_back(root->data);
        inorder_helper(root->right,ans);
        
        return;
    }
    vector<int> inOrder(Node* root) {
       vector<int>ans;
       inorder_helper(root,ans);
       return ans;
    }
};


Node* buildTree(string str) {
    
    if (str.length() == 0 || str[0] == 'N') return NULL;

   
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    
    Node* root = new Node(stoi(ip[0]));

    
    queue<Node*> queue;
    queue.push(root);

    
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        
        Node* currNode = queue.front();
        queue.pop();

        
        string currVal = ip[i];

       
        if (currVal != "N") {

         
            currNode->left = new Node(stoi(currVal));

            
            queue.push(currNode->left);
        }

        
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        
        if (currVal != "N") {

            
            currNode->right = new Node(stoi(currVal));

            
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        Solution ob;
        vector<int> res = ob.inOrder(root);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
