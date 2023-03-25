class Solution {
public:
    
    void dfs(int node, vector<vector<int>>&adj ,map<int,bool>&viss,int &elements)
    {
        viss[node]=true;
        elements+=1;
        for(auto it:adj[node])
        {
            if(viss[it]==false)
            {
                dfs(it,adj,viss,elements);
            }
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        int nn=edges.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<nn;i++)
        {
            int a=edges[i][0];
            int b=edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        map<int,bool>viss;
        int elements=0;
        vector<int>ans;// storing elements in each disconnected components
        for(int i=0;i<n;i++)
        {
            if(viss[i]==false)
            {
                dfs(i,adj,viss,elements);
                ans.push_back(elements);
                elements=0;
            }
        }
        //converting ans-> prefix sum array of ans
        for(int i=0;i<ans.size();i++)
        {
            if(i!=0)
            {
                ans[i]=ans[i-1]+ans[i];
            }
        }
       long long  ways=0;
         nn=ans.size();
        for(int i=0;i<ans.size();i++)
        {
            if(i==0)
            {
                long long  rem=(ans[nn-1]-ans[i])*1ll;
                ways=(ans[0]*rem);
            }
            else
            {
                long long rem=(ans[nn-1]-ans[i])*1ll;
                long long curr=(ans[i]-ans[i-1])*1ll;
                ways+=(curr*rem);
            }
        }
        return ways;
        
    }
};