class Solution {
public:
    
    void dfs(int node,vector<vector<int>>&adj,unordered_map<int,bool>&viss)
    {
        viss[node]=true;
        for(auto &child:adj[node])
        {
            if(viss[child]==false)
            {
                dfs(child,adj,viss);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adj(n+1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    adj[i+1].push_back(j+1);
                }
            }
        }
        unordered_map<int,bool>viss;
        
        // coutn disconnected components
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(viss[i]==false)
            {
                dfs(i,adj,viss);
                cnt+=1;
            }
        }
        
        return cnt;
        
    }
};