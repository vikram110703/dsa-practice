class Solution
{
    public:

        void dfs(int node,  map<int, vector < pair<int,int>>> &adj, map< int, bool> &viss, int &ans)
        {
            viss[node] = true;
            for (auto it: adj[node])//adj[node]-> vector<pair>
            {
                if (viss[it.first] == false)
                {
                    if(it.second==1)ans+=1;// 1-> actual node which is in forward dir so ans+=1
                    dfs(it.first, adj, viss, ans);
                }
            }
        }

    int minReorder(int n, vector<vector < int>> &connections)
    {
        map<int, bool> viss;
        int ans = 0;
        map<int, vector < pair<int,int>>> adj;
        for (int i = 0; i < connections.size(); i++)
        {
            int a = connections[i][0];
            int b = connections[i][1];
            //1-> actual path
            adj[a].push_back({b,1});
            //-1 imaginary path , to travel in tree
            adj[b].push_back({a,-1});
        }

            dfs(0,adj,viss,ans);
        return ans;
    }
};