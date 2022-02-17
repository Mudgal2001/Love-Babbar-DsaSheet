#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(vector<int>adj[],vector<int>&ans,vector<bool>&visited,int V,int s){
        if(s>V){
            return;
        }
        queue<int>q;
        q.push(s);
        while(q.size()!=0){
            int front = q.front();
            q.pop();
               if(!visited[front]){
                 ans.push_back(front);
                 visited[front]=true;}
             
             for(int i=0;i<adj[front].size();i++){
                   if(!visited[adj[front][i]]){
                     q.push(adj[front][i]);
                   }
             }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<bool>visited(V);
        for(int i=0;i<V;i++){
            visited[i]=false;
        }
        vector<int>ans;
        bfs(adj,ans,visited,V,0);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends