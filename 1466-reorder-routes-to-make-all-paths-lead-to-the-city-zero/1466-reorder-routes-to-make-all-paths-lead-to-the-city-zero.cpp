class Solution
{
    public:
    vector<vector<pair<int,int>>>adj;
    vector<bool>viss;
    int ans=0;
    void dfs(int node){
        viss[node]=true;
        for(auto &it:adj[node]){
            if(viss[it.first]==false){
                ans+=it.second;
                dfs(it.first);
            }
        }
    }

    int minReorder(int n, vector<vector < int>> &connections)
    {
        int nn=connections.size();
        adj.resize(n);
        viss.resize(n,false);
        for(int i=0;i<nn;i++){
            int a=connections[i][0];
            int b=connections[i][1];
            adj[a].push_back({b,1});
            adj[b].push_back({a,0});//img edge
        }
        dfs(0);
        return ans;
    }
};