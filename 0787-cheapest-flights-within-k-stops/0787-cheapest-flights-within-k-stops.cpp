class Solution
{
    public:
        int findCheapestPrice(int n, vector<vector < int>> &flights, int src, int dst, int k)
        {
            int nn = flights.size();
            vector<vector<pair<int, int>>> adj(n);
            for (int i = 0; i < nn; i++)
            {
               	// from[({to,price})]
                adj[flights[i][0]].push_back({ flights[i][1],
                    flights[i][2] });
            }
            vector<int> stops(n, INT_MAX);
           	//{dist,{node,stops}} 
            priority_queue<pair<int, pair<int, int>>, vector< pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
            pq.push({ 0,
                {
                    src,
                    0
                } });
            while (!pq.empty())
            {
                pair<int, pair<int, int>> curr = pq.top();
                pq.pop();
                int node = curr.second.first;
                int dist = curr.first;
                int steps = curr.second.second;
               	//           bcz of use of pq, if we get a node lesser steps then currnt then we will no include it again bcz we r getting nodes in ascending ordr of dist    
                if (steps > stops[node] || steps > k + 1)
                    continue;

                stops[node] = steps;
               	//return at 1st occurence bcz we r using pq to sort acrding to dist or price
                if (node == dst) return dist;
                for (auto &it: adj[node])
                {
                    int price = it.second, child = it.first;
                    pq.push({ dist + price,
                        {
                            child,
                            steps + 1
                        } });
                }
            }
           	// unable to reach dst
            return -1;
        }
};