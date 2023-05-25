class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        
        int n=g.size();
        unordered_map<int,int>outDeg;
        vector<vector<int>>rg(n);
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            outDeg[i]=g[i].size();
            if(outDeg[i]==0)q.push(i);
            for(auto &it:g[i])
            {
                rg[it].push_back(i);
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            int fnode=q.front();
            ans.push_back(fnode);
            q.pop();
            for(auto &it:rg[fnode])
            {
                outDeg[it]-=1;
                if(outDeg[it]==0)q.push(it);
            }
            
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};