class Solution
{
    public:

        int cal(int row, int col, vector<vector < int>> &dp)
        {
            if (row == 0 && row == col)
            {
                return dp[row][col] = 1;
            }
            if (dp[row][col] != -1) return dp[row][col];

            if (row == 0)
            {
                return dp[row][col] = cal(row, col - 1, dp);
            }
            if (col == 0)
            {
                return dp[row][col] = cal(row - 1, col, dp);
            }

            return dp[row][col] = cal(row - 1, col, dp) + cal(row, col - 1, dp);
        }

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return cal(m-1,n-1,dp);
        
    }
};