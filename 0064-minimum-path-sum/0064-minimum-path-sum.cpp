class Solution
{
    public:
        int minPathSum(vector<vector < int>> &grid)
        {
            int n = grid.size();
            int m = grid[0].size();
            int dp[n][m];
           	// filled row 0
            for (int i = 0; i < m; i++)
            {
                if (i == 0) dp[0][i] = grid[0][i];
                else dp[0][i] = grid[0][i] + dp[0][i - 1];
            }
           	//filled col 0
            for (int i = 1; i < n; i++)
            {
                dp[i][0] = dp[i - 1][0] + grid[i][0];
            }
            for (int i = 1; i < n; i++)
            {
                for (int j = 1; j < m; j++)
                {
                    dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
                }
            }

            int ans = dp[n - 1][m - 1];
            return ans;
        }
};