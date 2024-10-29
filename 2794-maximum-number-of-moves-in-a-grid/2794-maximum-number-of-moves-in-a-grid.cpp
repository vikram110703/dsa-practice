class Solution {
public:
    vector<vector<int>>dp;
    int n,m;

    int solve(int i,int j,vector<vector<int>>& grid)
    {
        if(i>=n||j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int dig1=0,right=0,dig2=0;
        if(i-1>=0 && j+1<m && grid[i-1][j+1]>grid[i][j])
        {
            dig1=1+solve(i-1,j+1,grid);
        }
        if(j+1<m && grid[i][j]<grid[i][j+1])
        {
            right=1+solve(i,j+1,grid);
        }
        if(i+1<n && j+1<m && grid[i+1][j+1]>grid[i][j])
        {
            dig2=1+solve(i+1,j+1,grid);
        }

        return dp[i][j]=max({dig1,right,dig2});
    }

    int maxMoves(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        int ans=0;
        dp.assign(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n;i++)
        {
            int elements=solve(i,0,grid);
            ans=max(ans,elements);
        }

        return ans;
    }
};