class Solution
{
    public:
        int dfs(int node, vector<int> &time, vector<vector< int >> &adj, vector< int >&maxDist)
        {
            if(maxDist[node]!=INT_MIN){
                return maxDist[node];
            }
            int tm = time[node];
            int maxi=0;
            for (auto &child: adj[node])
            {
               int a= dfs(child, time, adj, maxDist);
                maxi=max(maxi,a);
                
            }
            return maxDist[node]=tm+maxi;
        }

    int minimumTime(int n, vector<vector < int>> &rel, vector< int > &time)
    {

        vector<int> inDeg(n + 1);
        vector<vector < int>> adj(n + 1);
        for (auto &it: rel)
        {
            int a = it[0] - 1;
            int b = it[1] - 1;
            adj[a].push_back(b);
            inDeg[b]++;
        }
        vector<int> maxDist(n + 1, INT_MIN);
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (inDeg[i] == 0) q.push(i);
        
        int ans=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans=max(ans,dfs(node,time,adj,maxDist));
        }
    return ans;
       
    }
};