class Solution
{
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

    int findCircleNum(vector<vector < int>> &isConnected)
    {
        int n = isConnected.size();
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