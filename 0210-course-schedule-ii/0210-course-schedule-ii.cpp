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
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& v) {
        
        int n=v.size();
        vector<int>adj[numCourses];
        unordered_map<int,bool>dfsViss;
        unordered_map<int,bool>viss;
        unordered_map<int,int>inDeg;
        for(int i=0;i<n;i++)
        {
            adj[v[i][1]].push_back(v[i][0]);
            inDeg[v[i][0]]++;
        }
        bool iscycle=false;
        vector<int>ans;
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
        
        if(iscycle)return {};
        else
        {
            for(int i=0;i<numCourses;i++)
            {
                if(inDeg[i]==0)ans.push_back(i);
            }
            int i=0;
            while(ans.size()<numCourses&&i<ans.size())
            {
                for(auto it:adj[ans[i]])
                {
                    --inDeg[it];
                    if(inDeg[it]==0)ans.push_back(it);
                }
                i+=1;
            }
            return ans;
        }
        
    }
};