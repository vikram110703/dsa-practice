class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        
        vector<vector<bool>>viss(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>>q;   //{{i,j},time}
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    viss[i][j]=true;
                }
            }
        }
        int minTime=0;
        
        while(!q.empty())
        {
            int i=q.front().first.first;
            int j=q.front().first.second;
            int time=q.front().second;
            minTime=max(minTime,time);
            q.pop();
            
            if(i-1>=0&&viss[i-1][j]==false&&grid[i-1][j]==1)
            {
                q.push({{i-1,j},time+1});
                viss[i-1][j]=true;
            }
             if(j-1>=0&&viss[i][j-1]==false&&grid[i][j-1]==1)
            {
                q.push({{i,j-1},time+1});
                viss[i][j-1]=true;
            }
             if(i+1<n&&viss[i+1][j]==false&&grid[i+1][j]==1)
            {
                q.push({{i+1,j},time+1});
                viss[i+1][j]=true;
            }
              if(j+1<m&&viss[i][j+1]==false&&grid[i][j+1]==1)
            {
                q.push({{i,j+1},time+1});
                viss[i][j+1]=true;
            }
            
        }
        bool chk=true;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1&&viss[i][j]==false)
                {
                    chk=false;
                    break;
                }
            }
        }
        
       return chk==true? minTime: -1;
        
        
    }
};