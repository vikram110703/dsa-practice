class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0&&j==0)
                {
                    dp[i][j]=grid[i][j];
                }
                else
                {
                    int upper=INT_MAX,left=INT_MAX;
                    if(i-1>=0)upper=dp[i-1][j];
                    if(j-1>=0)left=dp[i][j-1];
                    dp[i][j]=(min(left,upper))+grid[i][j];
                }
            }
        }
        
        return dp[n-1][m-1];
    }
};