class Solution {
public:
    vector<vector<int>>adj;
    vector<bool>viss;
    void dfs(int node){
        viss[node]=true;
        for(auto &it:adj[node]){
            if(!viss[it])dfs(it);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        adj.resize(n+1);
        viss.resize(n+1,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j&&isConnected[i][j]==1)adj[i+1].push_back(j+1);
            }
        }
        int count=0;
        for(int i=1;i<=n;i++){
            if(!viss[i]){
                // cout<<i<<" ";
                dfs(i);
                count+=1;
            }
        }
        return count;
        
    }
};