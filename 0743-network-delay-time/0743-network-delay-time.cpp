class Solution
{
    public:
        int networkDelayTime(vector<vector < int>> &times, int n, int k)
        {
            int nn = times.size();
            vector<vector<pair<int, int>>> adj(n + 1);
            for (int i = 0; i < nn; i++)
            {
                adj[times[i][0]].push_back({ times[i][1],
                    times[i][2] });
            }

            vector<int> dist(n + 1, INT_MAX);
           	//         {dist,node}
            priority_queue<pair<int, int>, vector< pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({ 0,
                k });
            dist[k] = 0;
            while (!pq.empty())
            {
                pair<int, int> curr = pq.top();
                pq.pop();
                int dst = curr.first, node = curr.second;
               	// cout<<" Node "<<node<<" "<<dist[node]<<endl;
                for (auto &it: adj[node])
                {
                    int child = it.first, wt = it.second;

                    if (dist[child] > dst + wt)
                    {
                        cout << child << endl;
                        dist[child] = dst + wt;
                        pq.push({ dist[child],
                            child });
                    }
                }
            }
            int maxi = 0;
            for (int i = 1; i <= n; i++)
            {
                maxi = max(maxi, dist[i]);
            }
            return maxi == INT_MAX ? -1 : maxi;
        }
};