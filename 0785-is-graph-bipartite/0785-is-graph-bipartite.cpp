class Solution {
public:
    bool chk;
    
    // color: -1->noColor,0->red,1->blue
    bool dfs(int node,vector<vector<int>>&g,unordered_map<int,bool>&viss,vector<int> &color)
    {
        // viss[node]=true;
        for(auto child:g[node])
        {
            if(viss[child]==false)
            {
                //swap color{0,1};
                viss[child]=true;
                color[child]=(color[node]+1)%2;
               if(dfs(child,g,viss,color)==false)return false;
            }
            else
            {
                if(color[child]==color[node])return false;
            }
        }
        return true;
    }
    
    
    
    bool isBipartite(vector<vector<int>>& g) {
        int n=g.size();
        unordered_map<int,bool>viss;
        vector<int>color(n,-1);
        for(int i=0;i<n;i++)
        {
            color[i]=-1;
        }
        chk=true;
        
        for(int i=0;i<n;i++)
        {
            if(viss[i]==false)
            {
                chk&=dfs(i,g,viss,color);
            }
        }
        return chk;
        
        
    }
};