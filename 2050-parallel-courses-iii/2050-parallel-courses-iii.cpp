class Solution
{
    public:
        // int dfs(int node, vector<int> &time, vector<vector< int >> &adj, vector< bool > &viss)
        // {
        //     int tm = time[node];
        //     for (auto &child: adj[node])
        //     {
        //         if (viss[child] == false)
        //         {
        //             tm += dfs(child, time, adj, viss);
        //         }
        //     }
        //     return tm;
        // }

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

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            maxDist[node] = max(maxDist[node], time[node]);
            for (auto &it: adj[node])
            {
                maxDist[it] = max(maxDist[it], maxDist[node] + time[it]);

                inDeg[it]--;
                if (inDeg[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        return *max_element(maxDist.begin(),maxDist.end());
    }
};