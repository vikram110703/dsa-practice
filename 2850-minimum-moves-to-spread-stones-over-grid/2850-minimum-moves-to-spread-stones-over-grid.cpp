class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int cnt=0;
        int n=grid.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)cnt+=1;
            }
        }
        if(cnt==0)return 0;
            int ans=INT_MAX;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(grid[i][j]==0)
            {
                for(int ii=0;ii<3;ii++)
                {
                    for(int jj=0;jj<3;jj++)
                    {
                        if(grid[ii][jj]>1)
                        {
                            int dist=abs(ii-i)+abs(jj-j);
                            grid[i][j]+=1;
                            grid[ii][jj]-=1;
                            ans=min(ans,dist+minimumMoves(grid));
                            //backtracking 
                            grid[i][j]-=1;
                            grid[ii][jj]+=1;
                        }
                    }
                }
            }
        }
    }
        return ans;
        
    }
};