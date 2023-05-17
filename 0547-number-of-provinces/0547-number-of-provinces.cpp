class Solution
{
    public:

        void bfs(vector<vector < int>> &adj, int ind, map< int, bool> &viss)
        {
            queue<int> q;
            q.push(ind);
            viss[ind] = true;

            while (!q.empty())
            {
                int fnode = q.front();
                q.pop();

                for (auto &child: adj[fnode])
                {
                    if (viss[child] == false)
                    {
                       q.push(child);
                         viss[child] = true;
                    }
                }
            }
        }


    int findCircleNum(vector<vector < int>> &isConnected)
    {
        int n = isConnected.size();

        vector<vector < int>> adj(n + 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i!=j&&isConnected[i][j] == 1)
                {
                    adj[i + 1].push_back(j + 1);
                    adj[j + 1].push_back(i + 1);
                }
            }
        }

        map<int, bool> viss;
        int disConnectedComp = 0;
        for (int i = 1; i <= n; i++)
        {
            if (viss[i] == false)
            {
                bfs(adj, i, viss);
                disConnectedComp += 1;
            }
        }

        return disConnectedComp;
    }
};
