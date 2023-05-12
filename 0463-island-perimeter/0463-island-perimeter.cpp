class Solution
{
    public:
        int islandPerimeter(vector<vector < int>> &grid)
        {
            int n = grid.size(), m = grid[0].size();

            int cnt = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (grid[i][j] == 1) cnt += 1;
                }
            }
            cnt *= 4;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (grid[i][j] == 1)
                    {
                        if (i + 1 < n && grid[i + 1][j] == 1)
                            cnt -= 1;
                        if (i - 1 > -1 && grid[i - 1][j] == 1)
                            cnt -= 1;

                        if (j + 1 < m && grid[i][j + 1] == 1) cnt -= 1;
                        if (j - 1 >-1 && grid[i][j - 1] == 1) cnt -= 1;
                    }
                }
            }
            return cnt;
        }
};