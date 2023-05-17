//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
   void dfs(int n, vector<int> adj[], vector<int> &viss)
        {
            viss[n]=true;
            for (auto child: adj[n])
            {
                if (viss[child] == 0)
                {
                    viss[child] = 1;
                    dfs(child, adj, viss);
                }
            }
        }

  
    int numProvinces(vector<vector<int>> isConnected, int V) {
        // code here
        
         int n = V;
        vector<int> adj[n + 1];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)

                {
                    if (i!=j&&isConnected[i][j] == 1)
                    {
                        adj[i + 1].push_back(j + 1);
                        adj[j + 1].push_back(i + 1);
                    }
                }
            }
        }
        vector<int> viss(n + 1, 0);
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (viss[i] == 0)
            {
                dfs(i, adj, viss);
                cnt += 1;
            }
        }
        return cnt;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends