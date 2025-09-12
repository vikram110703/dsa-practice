class Solution {
public:
    bool bfs(int n,vector<int>&inDeg,vector<vector<int>>&adj){
        queue<int>q;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(inDeg[i]==0)q.push(i);
        }
        while(!q.empty())
        {
            int fnode=q.front();
            q.pop();
            cnt+=1;
            for(auto &it:adj[fnode]){
                inDeg[it]--;
                if(inDeg[it]==0){
                    q.push(it);
                }
            }
        }
        return cnt==n;
    }
    
    bool canFinish(int n, vector<vector<int>>& preq) {
        vector<vector<int>>adj(n);
        vector<int>inDeg(n,0);
        for(int i=0;i<preq.size();i++){
           int u=preq[i][1];
           int v=preq[i][0];
            adj[u].push_back(v);
            inDeg[v]+=1;
        }
        return bfs(n,inDeg,adj);
    }
};