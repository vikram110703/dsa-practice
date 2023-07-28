class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,vector<bool>&viss)
    {
        viss[node]=true;
        for(auto child:adj[node])
        {
            if(viss[child]==false)
            {
                dfs(child,adj,viss);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& adj) {
        int n=adj.size();
        // vector<vector<int>>adj(n);
        // for(int i=0;i<n;i++)
        // {
        //     adj[i].push_back(rooms[i]);
        //     adj[rooms[i]].push_back(i);
        // }
       
        vector<bool>viss(n,false);
         dfs(0,adj,viss);
        for(int i=0;i<n;i++)
        {
            if(viss[i]==false)
            {
                return false;
            }
            // cout<<viss[i]<<" ";
        }
        return true;
    }
};