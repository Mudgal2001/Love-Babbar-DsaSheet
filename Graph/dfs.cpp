#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(vector<int>adj[],bool *visited,vector<int>&ans,int s,int V){
      if(adj[s].size()==1){
          if(visited[adj[s][0]]==true){
              if(visited[s]!=true){
              ans.push_back(s);
              visited[s]=true;}
              return ;
          }
         
      }
        if(s>=V){
            return;
        }else{
            if(visited[s]!=true){
                ans.push_back(s);
                visited[s]=true;
            }
            
            for(int i=0;i<adj[s].size();i++){
                
                
                if(visited[adj[s][i]]!=true){
                    
                    ans.push_back(adj[s][i]);
                    visited[adj[s][i]]=true;
                    dfs(adj,visited,ans,adj[s][i],V);
                }
                
            }
          return;
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans;
        bool *visited=new bool[V];
        for(int i=0;i<V;i++){
            visited[i]=false;
        }
        dfs(adj,visited,ans,0,V);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends