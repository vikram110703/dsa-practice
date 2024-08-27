class Solution {
public:
    vector<vector<pair<int,double>>> adj;
    vector<double> probability;

    double maxProbability(int n, vector<vector<int>>& edges,vector<double>& succProb, int start_node, int end_node) {
        adj.resize(n);

        for (int i = 0; i < edges.size(); i++) 
        {
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        probability.resize(n, -1);

        bfs(start_node, end_node);

        double ans = probability[end_node];

        if (ans == -1)
            return 0;
        else
            return ans;
    }

    void bfs(int strt, int end) {
        priority_queue<pair<double, int>> pq;

        probability[strt] = 1.0;
        pq.push({1.0, strt}); //{w,node}

        while (!pq.empty()) {
            double curr_prob = pq.top().first;
            int curr_node = pq.top().second;
            pq.pop();

            if (probability[curr_node] > curr_prob)
                continue;

            if(curr_node==end)return;

            for (auto& child : adj[curr_node]) {
                int adj_node = child.first;
                double w = child.second;

                if (curr_prob * w > probability[adj_node]) {
                    probability[adj_node] = curr_prob * w;
                    pq.push({probability[adj_node], adj_node});
                }
            }
        }
    }
};
