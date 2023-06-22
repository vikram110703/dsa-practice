class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1||grid[n-1][n-1]==1)return -1;
        
        pair<int,int>dirs[8]={{1,0},{0,1},{0,-1},{-1,0},{1,-1},{-1,1},{-1,-1},{1,1}};
        queue<pair<int,int>>q;
        //{dx,dy}
        q.push({0,0});
        grid[0][0]=1;
        while(!q.empty())
        {
            pair<int,int>curr;
             curr.first=q.front().first;
             curr.second=q.front().second;
            if(curr.first==n-1&&curr.second==n-1)return grid[n-1][n-1];
            q.pop();
            for(auto it:dirs)
            {
                int dx=curr.first+it.first;
                int dy=curr.second+it.second;
                // for viss cond. wr r checking grid[dx][dy]==0
                if(dx>=0&&dy>=0&&dx<n&&dy<n&&grid[dx][dy]==0)
                {
                    q.push({dx,dy});
                    grid[dx][dy]=grid[curr.first][curr.second]+1;
                }
            }
        }
        return -1;
        
    }
};