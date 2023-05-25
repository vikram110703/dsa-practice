class Solution {
public:
    bool dfs(int node,vector<vector<int>>&g,map<int,bool>&viss,map<int,bool>&iscycle,map<int,bool>&dfsViss)
    {
        viss[node]=true;
        dfsViss[node]=true;
        for(auto &child:g[node])
        {
            if(viss[child]==false)
            {
               bool chk=dfs(child,g,viss,iscycle,dfsViss);
                if(chk)
                {
                    iscycle[node]=true;
                    return true;
                }
            }
            else if(dfsViss[child]==true)
            {
                iscycle[node]=true;
                return true;
            }
        }
        dfsViss[node]=false;
        return false;
        
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n=g.size();
        map<int,bool>iscycle;
        map<int,bool>viss;
        map<int,bool>dfsViss;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(viss[i]==false)
            {
                if(iscycle[i]==true)
                {
                    ;;
                }
              
                else 
                {
                    bool chk=dfs(i,g,viss,iscycle,dfsViss);
                    if(chk)
                    {
                        iscycle[i]=true;
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(iscycle[i]==false)ans.push_back(i);
        }
        
        return ans;
        
        
        
    }
};