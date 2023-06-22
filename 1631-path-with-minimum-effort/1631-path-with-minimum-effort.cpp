class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        
        vector<vector<int>>dist(n,vector<int>(m,1e6));
        pair<int,int>dirs[4]={{0,1},{0,-1},{1,0},{-1,0}};

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        dist[0][0]=0;
        // {dist,{x,y}}
        pq.push({dist[0][0],{0,0}});
        while(!pq.empty())
        {
            // {dist,{x,y}}
         pair<int,pair<int,int>>curr=pq.top();
            int d=curr.first,x=curr.second.first,y=curr.second.second;
            pq.pop();
            if(d>dist[x][y])continue;
            // we reach our destination 
            if(x==n-1&&y==m-1)return d;
            
            for(auto it:dirs)
            {
                int dx=x+it.first;
                int dy=y+it.second;
                if(dx>=0&&dy>=0&&dx<n&&dy<m)
                {
                    int diff=abs(heights[x][y]-heights[dx][dy]);
                    int maxD=max(diff,d);
                    if(dist[dx][dy]>maxD)
                    {
                        dist[dx][dy]=maxD;
                        pq.push({maxD,{dx,dy}});
                    }
                }
            }
            
            
        }
        // just for the shake of return statement
        return dist[n-1][m-1];
        
    }
};