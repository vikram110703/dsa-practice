class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        // u->{v,w}
        for(auto &it:flights)
        {
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
        }

        vector<int>dist(n+1,INT_MAX);
        dist[src]=0;

        //min heap //will push (-1*stops,-1*w);
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({0,{0,src}});
        while(!pq.empty())
        {
            int fnode=pq.top().second.second;
            int currDist=pq.top().second.first*-1;
            int stops=pq.top().first*-1;
            pq.pop();
            if(stops>k)continue;
            for(auto&it:adj[fnode])
            {
                int child=it.first;
                int w=it.second;
                if(stops<=k&&(currDist+w<dist[child]))
                {
                    dist[child]=currDist+w;
                    pq.push({-1*(stops+1),{-1*(dist[child]),child}});
                }
            }
        }
        return dist[dst]!=INT_MAX?dist[dst]:-1;
    }
};