class Solution
{
    public:
        int findTheCity(int n, vector<vector < int>> &edges, int distanceThreshold)
        {

            int nn = edges.size();
            vector<vector<pair<int, int>>> adj(n);
            for (int i = 0; i < nn; i++)
            {
                adj[edges[i][0]].push_back({ edges[i][1],
                    edges[i][2] });
                adj[edges[i][1]].push_back({ edges[i][0],
                    edges[i][2] });
            }
            vector<int> count(n, 0);
            for(int i=0;i<n;i++)
            {
                
            vector<int> dist(n, INT_MAX);
            priority_queue<pair<int, int>, vector< pair<int, int>>, greater<pair<int, int>>> pq;
           	// {dist,node}
            pq.push({ 0,
                i });
            dist[i]=0;
            while (!pq.empty())
            {
                pair<int, int> curr = pq.top();
                pq.pop();
                int node = curr.second, currDist = curr.first;

                if (currDist > dist[node]) continue;
                for (auto &it: adj[node])
                {
                    int child = it.first, wt = it.second;
                    if (dist[child] > currDist + wt)
                    {
                        dist[child] = currDist + wt;
                        pq.push({dist[child],child});
                    }
                }
            }
                 for(int j=0;j<n;j++)
           {
               if(j!=i&&dist[j]<=distanceThreshold)
               {
                   count[i]+=1;
               }
           }
            
            }
            
            int val=INT_MAX,ans=0;
            for(int i=0;i<n;i++)
            {
                // cout<<count[i]<<" ";
                if(count[i]<=val)
                {
                    val=count[i];
                    ans=i;
                }
            }
          return ans;
            
        }
};