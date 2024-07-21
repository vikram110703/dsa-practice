class Solution {
public:
    
       vector<int> bfs(int n,vector<int>&inDeg,vector<vector<int>>&adj){
        queue<int>q;
        vector<int>topo;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(inDeg[i]==0)q.push(i);
        }
        while(!q.empty())
        {
            int fnode=q.front();
            q.pop();
            topo.push_back(fnode);
            for(auto &it:adj[fnode]){
                inDeg[it]--;
                if(inDeg[it]==0){
                    q.push(it);
                }
            }
        }
        if(topo.size()==n)return topo;
         else return {};
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& preq){
         vector<vector<int>>adj(n);
         vector<int>inDeg(n,0);
         for(int i=0;i<preq.size();i++){
           int u=preq[i][0];
           int v=preq[i][1];
            adj[v].push_back(u);
            inDeg[u]+=1;
        }
        return bfs(n,inDeg,adj);
        
    }
};