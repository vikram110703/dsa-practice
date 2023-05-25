class Solution {
public:
      bool dfs(int node,vector<int>adj[],unordered_map<int,bool>&dfsViss,unordered_map<int,bool>&viss)
    {
        
        viss[node]=true;
        dfsViss[node]=true;
        for(auto child:adj[node])
        {
            if(viss[child]==false)
            {
                bool chk=dfs(child,adj,dfsViss,viss);
                if(chk==true)return true;
            }
            else
            {
                if(dfsViss[child]==true)return true;
            }
        }
        dfsViss[node]=false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& v) {
        
          
        int n=v.size();
        vector<int>adj[numCourses];
        unordered_map<int,bool>dfsViss;
        unordered_map<int,bool>viss;
        for(int i=0;i<n;i++)
        {
            adj[v[i][1]].push_back(v[i][0]);
        }
        bool iscycle=false;
        for(int i=0;i<numCourses;i++)
        {
            if(viss[i]==false)
            {
                if(dfs(i,adj,dfsViss,viss)==true)
                {
                    iscycle=true;
                    break;
                }
            }
        }
        return iscycle==true?false:true;
        
        
    }
};