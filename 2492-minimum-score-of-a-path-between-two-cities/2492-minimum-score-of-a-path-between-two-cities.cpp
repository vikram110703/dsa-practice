class Solution
{
    public:

        void bfs(int node, map<int, vector<pair<int, int>>> &adj, map< int, bool> &viss, int &mini)
        {
            queue<int> q;
            q.push(node);
           	// viss[node]=true;
            while (!q.empty())
            {
                int fnode = q.front();
                q.pop();
                if (viss[fnode] == false)
                {
                    viss[fnode] = true;

                    for (auto it: adj[fnode])
                    {
                        mini = min(mini, it.second);
                        if (viss[it.first] == false) q.push(it.first);
                    }
                }
            }
        }
    
    void dfs(int node, map<int, vector<pair<int, int>>> &adj, map< int, bool> &viss, int &mini)
    {
        if(viss[node]==false)
        {
            viss[node]=true;
            for(auto it:adj[node])
            {
                mini=min(mini,it.second);
                dfs(it.first,adj,viss,mini);
            }
        }
        
    }

    int minScore(int n, vector<vector < int>> &v)
    {
        map<int, vector<pair<int, int>>> adj;
        int nn = v.size();	// size of v
        for (int i = 0; i < nn; i++)
        {
            int a = v[i][0], b = v[i][1], c = v[i][2];
            adj[a].push_back({ b,
                c });
            adj[b].push_back({ a,
                c });
        }
        map<int, bool> viss;
        for (int i = 0; i < n; i++) viss[i + 1] = false;
        int mini = INT_MAX;

        // bfs(1, adj, viss, mini);
        dfs(1,adj,viss,mini);
        return mini;
    }
};