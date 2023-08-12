class Solution
{
    public:
        int uniquePathsWithObstacles(vector<vector < int>> &v)
        {
            int n = v.size(), m = v[0].size();

            vector<vector<int>>dp(n,vector<int>(m,0));
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (i == 0 && j == 0)
                    {
                        if (v[i][j] == 1) dp[i][j] = 0;
                        else dp[i][j] = 1;
                    }
                    else
                    {
                        if (i - 1 >= 0 && v[i - 1][j] != 1&&v[i][j]!=1)
                        {
                            dp[i][j] += dp[i - 1][j];
                        }
                        if (j - 1 >= 0 && v[i][j - 1] != 1&&v[i][j]!=1)
                        {
                            dp[i][j] += dp[i][j - 1];
                        }
                    }
                }
            }
            return dp[n-1][m-1];
        }
};