#define ll long long 

class Solution {
public:
    int MOD=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        ll nn=roads.size();
        vector<ll>dist(n,LONG_MAX);
        vector<vector<pair<ll,ll>>>adj(n);
        for(int i=0;i<nn;i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        // we will store no of ways to reach at a node with minimum cost
        vector<ll>ways(n,0);
         // Dijkstra's Algo..
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        // {dist,node}
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;
        while(!pq.empty())
        {
            pair<ll,ll>curr=pq.top();
            pq.pop();
            // {dst,node}
            ll dst=curr.first,node=curr.second;
     //we hace already get a path to this node with lesser distance
               if(dst>dist[node])continue; 
            for(auto &it:adj[node])
            {
                ll child=it.first,wt=it.second;
                if(dist[child]>dst+wt)
                {
                    dist[child]=dst+wt;
//      still we r getting min distance so ways r same as parent .... 
                    ways[child]=ways[node];
                    pq.push({dist[child],child});
                }
                else if(dist[child]==dst+wt)
                {
//         we already have a path with min cost....
                    ways[child]=(ways[node]+ways[child])%MOD;
                }
                // else continue;
                
            }
            
        }
        return ways[n-1];
        
        
    }
};