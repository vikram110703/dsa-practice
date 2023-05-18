class Solution {
public:
    void dfs(vector<vector<int>>&adj,int node,map<int,bool>&viss,map<int,bool>&inDeg)
{
    viss[node]=true;
        for(auto &child:adj[node])
        {
            
                inDeg[child]=true;
            if(viss[child]==false)
                dfs(adj,child,viss,inDeg);
            
        }
}    
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            int a=edges[i][0];
            int b=edges[i][1];
            adj[a].push_back(b);
        }
        map<int,bool>viss,inDeg;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(viss[i]==false)
            {
                dfs(adj,i,viss,inDeg);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(inDeg[i]==false)
            {
                ans.push_back(i);
            }
        }
        
        return ans;
        
    }
};