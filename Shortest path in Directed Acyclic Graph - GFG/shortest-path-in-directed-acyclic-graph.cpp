//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
  // topo sort
  void dfs(int node,vector<vector<pair<int,int>>>adj, unordered_map<int,bool>&viss,stack<int>&topo)
  {
      viss[node]=true;
      for(auto &child:adj[node])
      {
          if(viss[child.first]==false)
          {
              dfs(child.first,adj,viss,topo);
          }
      }
      topo.push(node);
      
  }
  
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        
        vector<vector<pair<int,int>>>adj(n);
        unordered_map<int,bool>viss;
        stack<int>topo;
        
        for(int i=0;i<m;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
        }
        
        // dfs call to manage topo sort stack .
        for(int i=0;i<n;i++)
        {
            if(viss[i]==false)
            {
                dfs(i,adj,viss,topo);
            }
        }
        
        //update distance array following topo sort
        vector<int>dist(n,INT_MAX);
        dist[0]=0;
        while(!topo.empty())
        {
            int fnode=topo.top();
            topo.pop();
            if(dist[fnode]!=INT_MAX)
            {
                for(auto &child:adj[fnode])
                {
                    dist[child.first]=min(dist[child.first],dist[fnode]+child.second);
                }
            }
            
        }
        for(auto &it:dist)
        {
            if(it==INT_MAX)it=-1;
        }
        
        return dist;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends